#include "VBO.h"

namespace Coco
{
	void VBO::Init()
	{
		this->Delete();
		glGenBuffers(1, &ID);
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, ID);
	}

	void VBO::PassData(std::vector<Vertex>& data)
	{
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(Vertex), data.data(), GL_STATIC_DRAW);
		this->Unbind();
	}

	void VBO::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::Delete()
	{
		if (ID != 0)
		{
			glDeleteBuffers(1, &ID);
		}
	}

	VBO::~VBO()
	{
		this->Delete();
	}
}