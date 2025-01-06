#pragma once

#include <glad/glad.h>
#include <glfw3.h>

#include <iostream>

namespace Coco
{
	class Window
	{
	private:
		GLFWwindow* window;
		int width; int height;

	public:
		Window() = default;

		void Create(const char* title);

		bool IsOpen();
	};
}