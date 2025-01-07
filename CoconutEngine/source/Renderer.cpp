#include "Renderer.h"

namespace Coco
{
	void Renderer::Init()
	{
		render_program.Compile(vertex_shader_source, fragment_shader_source);
		render_program.Use();
		u_Model = glGetUniformLocation(render_program.GetProgram(), "model");
		u_Camera = glGetUniformLocation(render_program.GetProgram(), "camera");
	}

	void Renderer::Finish()
	{
		render_program.Delete();
	}

	void Renderer::RenderObject(Object* obj)
	{

		obj->vao.Bind();
		//obj->vbo.Bind();
		//obj->ebo.Bind();
		glUniformMatrix4fv(u_Model, 1, GL_FALSE, glm::value_ptr(obj->getMatrix()));

		glDrawElements(GL_TRIANGLES, obj->index_data.size(), GL_UNSIGNED_INT, 0);

		obj->vao.UnBind();
	}

	void Renderer::NewFrame()
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		render_program.Use();

		glUniformMatrix4fv(u_Camera, 1, GL_FALSE, glm::value_ptr(camera->getMatrix()));
		
	}
}

