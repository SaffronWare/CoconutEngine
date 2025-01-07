#pragma once

#include <vector>

#include <glad/glad.h>
#include "Vertex.h"

namespace Coco
{
	class VBO 
	{
	private:
		GLuint ID = 0;

	public:
		void Init();
		void Bind();
		void Unbind();
		void Delete();
		void PassData(std::vector<Vertex>& data);
		VBO() = default;
		~VBO();
	};
}