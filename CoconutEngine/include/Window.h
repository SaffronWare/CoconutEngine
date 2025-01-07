#pragma once

#include <glad/glad.h>
#include <glfw3.h>

#include <vector>
#include <iostream>
#include <algorithm>

#include "Event.h"

namespace Coco
{
	class Window
	{
	private:
		GLFWwindow* window = nullptr;
		int width = 0; int height = 0;
		int x = 0; int y = 0;

		double mouse_pos_x = 0; double mouse_pos_y = 0;
		bool maximized = true;
		bool LEFT_PRESSED = false; bool RIGHT_PRESSED = false;

		bool states[GLFW_KEY_LAST - GLFW_KEY_SPACE + 1];
		bool new_states[GLFW_KEY_LAST - GLFW_KEY_SPACE + 1];

		double prev_upd_time = 0.0;

		std::vector<KeyEvent> key_events;
		std::vector<WindowEvent> window_events;
		std::vector<MouseEvent> mouse_events;

	public:
		GLFWwindow* GetWindow() { return window; }

		Window() = default;

		void Create(const char* title);
		void Finish();

		void UpdateEvents();
		std::vector<KeyEvent> GetKeyEvents();
		std::vector<WindowEvent> GetWindowEvents();
		std::vector<MouseEvent> GetMouseEvents();

		bool IsOpen();

		double Update(); // return dt
	};
}