#pragma once
#include "Event.h"

namespace Coco
{
	class Layer
	{
	public:

		virtual void Init() = 0;
		virtual void Finish() = 0;

		Layer() = default;

	private:
		virtual void Update(double dt) = 0;
		virtual void OnEvent(Event& event) = 0;
	};
}