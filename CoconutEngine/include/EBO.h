#pragma once

#include <glad/glad.h>
#include <vector>

namespace Coco
{
	class EBO
	{
	private:
		GLuint ID;
	public:
		void Init();
		void Bind();
		void UnBind();
		void Delete();
		void PassData(std::vector<unsigned int> data);
		EBO() = default;
		~EBO();
	};
}