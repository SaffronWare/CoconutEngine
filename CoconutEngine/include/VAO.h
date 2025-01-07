#pragma once
#include <glad/glad.h>
#include "VBO.h"
#include "EBO.h"

namespace Coco
{
	class VAO
	{
		GLuint ID = 0;

		void SetupVertexAttributes();
	public:
		void Init();
		void Bind();
		void UnBind();
		void AddVBO(VBO& vbo);
		void AddEBO(EBO& ebo);
		void Delete();
		VAO() = default;
		~VAO();
	};
}