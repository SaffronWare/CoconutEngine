#pragma once
#include "Event.h"
#include "Camera.h"

namespace Coco
{
	class Layer
	{
		
	public:
		double dt = 0.0;
		virtual void Init() = 0;
		virtual void Finish() = 0;
		virtual void Update() = 0;
		virtual void OnKeyEvent(KeyEvent& event) = 0;
		virtual void OnWindowEvent(WindowEvent& event) = 0;
		virtual void OnMouseEvent(MouseEvent& event) = 0;

		Camera coco_GameCamera;

		Layer() = default;
	};
}