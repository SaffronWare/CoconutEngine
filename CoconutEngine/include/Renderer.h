#pragma once

#include "Shader.h"
#include "Objects.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Coco
{
	class Renderer
	{
		Shader render_program;
		const char* vertex_shader_source = "shaders/vertex.glsl";
		const char* fragment_shader_source = "shaders/fragment.glsl";

		GLuint u_Model;
		GLuint u_Camera;
	public:
		Camera* camera;

		void NewFrame();
		void Init();
		void Finish();
		void RenderObject(Object* obj);
	};
}