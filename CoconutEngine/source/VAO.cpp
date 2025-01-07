#include "VAO.h"

namespace Coco
{
	void VAO::Init()
	{
		this->Delete();
		glGenVertexArrays(1, &ID);
	}

	void VAO::SetupVertexAttributes()
	{
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);

		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}

	void VAO::Bind()
	{
		glBindVertexArray(ID);
	}

	void VAO::UnBind()
	{
		glBindVertexArray(0);
	}

	void VAO::AddVBO(VBO& vbo)
	{
		this->Bind();
		vbo.Bind();
		SetupVertexAttributes();
		this->UnBind();
		vbo.Unbind();
	}

	void VAO::AddEBO(EBO& ebo)
	{
		this->Bind();
		ebo.Bind();
		this->UnBind();
		ebo.UnBind();
	}

	void VAO::Delete()
	{
		if (ID != 0)
		{
			glDeleteVertexArrays(1, &ID);
		}
	}

	VAO::~VAO()
	{
		this->Delete();
	}
}