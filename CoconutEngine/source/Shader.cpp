#include "Shader.h"

namespace Coco
{
	void Shader::Compile(const char* vert_source, const char* frag_source)
	{
		if (shaderProgram != 0)
		{
			this->Delete();
		}
		
		std::string vertex_shader_text = get_file_contents(vert_source);
		std::string fragment_shader_text = get_file_contents(frag_source);

		const char* vertex_shader_source = vertex_shader_text.c_str();
		const char* fragment_shader_source = fragment_shader_text.c_str();

		GLint compilation_success;

		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, GL_NONE);
		glCompileShader(vertex_shader);
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &compilation_success);

		if (!compilation_success)
		{
			GLint logLength;
			glGetShaderiv(vertex_shader, GL_INFO_LOG_LENGTH, &logLength);

			char* infoLog = new char[logLength];
			glGetShaderInfoLog(vertex_shader, logLength, &logLength, infoLog);

			std::cerr << "Vertex Shader failed to compile\n" << infoLog << std::endl;
			delete[] infoLog;
			throw(errno);
		}


		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, GL_NONE);
		glCompileShader(fragment_shader);
		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &compilation_success);

		if (!compilation_success)
		{
			GLint logLength;
			glGetShaderiv(fragment_shader, GL_INFO_LOG_LENGTH, &logLength);

			char* infoLog = new char[logLength];
			glGetShaderInfoLog(fragment_shader, logLength, &logLength, infoLog);

			std::cerr << "Vertex Shader failed to compile\n" << infoLog << std::endl;
			delete[] infoLog;
			throw(errno);
		}

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertex_shader);
		glAttachShader(shaderProgram, fragment_shader);
		glLinkProgram(shaderProgram);

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

	}

	void Shader::Use()
	{
		glUseProgram(shaderProgram);
	}

	void Shader::EndUse()
	{
		glUseProgram(0);
	}

	void Shader::Delete()
	{
		glDeleteProgram(shaderProgram);
	}

	GLuint Shader::GetProgram()
	{
		return shaderProgram;
	}
}