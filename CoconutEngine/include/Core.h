#pragma once
#include <glad/glad.h>
#include <glfw3.h>

#include <stdio.h>
#include <iostream>
#include <typeinfo>

#include "Layer.h"
#include "Event.h"
#include "Window.h"

namespace Coco
{
	extern Window window;
	extern Layer* layer;

	void Attach(Layer* p_layer);
	void Start(const char* title);
	void Finish();
}