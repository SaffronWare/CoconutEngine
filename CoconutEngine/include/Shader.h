#pragma once

#include "Utils.h"
#include <glad/glad.h>

#include <iostream>



namespace Coco
{
	class Shader
	{
	private:
		GLuint shaderProgram = 0;
	public:
		Shader() = default;
		void Compile(const char* vert_source, const char* frag_source);
		void Use();
		void EndUse();
		void Delete();
		GLuint GetProgram();
	};
}