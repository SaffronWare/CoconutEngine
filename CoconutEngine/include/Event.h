#pragma once

namespace Coco
{
	struct Event
	{
		enum class EventType { MouseEvent, KeyEvent, WindowEvent };

		EventType type;
	};

	struct MouseEvent : public Event
	{
		enum class MouseEventAction {LEFT_PRESS,LEFT_RELEASE, LEFT_HELD, LEFT_RELEASED, RIGHT_PRESS, RIGHT_RELEASE};

		MouseEventAction action;
		int x; int y;


		MouseEvent(int x, int y, MouseEventAction action) : 
			x(x), 
			y(y), 
			action(action)
		{
			type = EventType::MouseEvent;
		}
	};

	struct KeyEvent : public Event
	{
		enum class KeyEventAction {KEY_PRESS, KEY_RELEASE, KEY_HELD};

		KeyEventAction action;
		const char* key;

		KeyEvent(const char* key, KeyEventAction action) :
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
