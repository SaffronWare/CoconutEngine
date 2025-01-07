#pragma once
#include <glfw3.h>
#include <vector>



namespace Coco
{
	struct Event
	{
		enum class EventType { MouseEvent, KeyEvent, WindowEvent };

		EventType type;
	};

	struct MouseEvent : public Event
	{
		enum class MouseEventAction {LEFT_PRESS, LEFT_HELD, RIGHT_PRESS, RIGHT_HELD,  CURSOR_MOVED};

		MouseEventAction action;
		double ox;
		double oy;
		double x;
		double y;


		MouseEvent(double x, double y, double ox, double oy, MouseEventAction action) : 
			x(x), 
			y(y),
			ox(ox),
			oy(oy),
			action(action)
		{
			type = EventType::MouseEvent;
		}
	};

	struct KeyEvent : public Event
	{
		enum class KeyEventAction {KEY_PRESS, KEY_RELEASE, KEY_HELD};

		KeyEventAction action;
		int key;

		KeyEvent(int key, KeyEventAction action) :
			action(action),
			key(key)
		{
			type = EventType::KeyEvent;
		}
	};

	struct WindowEvent : public Event
	{
		enum class WindowEventAction {WINDOW_RESIZE, WINDOW_MOVED, WINDOW_MINIMIZED, WINDOW_RESTORATION};

		WindowEventAction action;
		unsigned int new_width; unsigned int new_height;
		unsigned int old_width; unsigned int old_height;

		WindowEvent(
			unsigned int new_width,
			unsigned int new_height, 
			unsigned int old_width, 
			unsigned int old_height, 
			WindowEventAction action ) :
				new_width(new_width),
				new_height(new_height),
				old_width(old_width),
				old_height(old_height),
				action(action)
		{
			type = EventType::WindowEvent;
		}
	};
}
