#pragma once
#include <glad/glad.h>
#include <glfw3.h>

#include <stdio.h>
#include <iostream>
#include <typeinfo>

#include "Layer.h"
#include "Event.h"
#include "Window.h"
#include "Globals.h"
#include "Shader.h"
#include "Renderer.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"
#include "Objects.h"
#include "Vertex.h"

namespace Coco
{
	extern Window window;
	extern Layer* layer;
	extern Renderer renderer;

	void Attach(Layer* p_layer);
	void Start(const char* title);
	void Finish();
}