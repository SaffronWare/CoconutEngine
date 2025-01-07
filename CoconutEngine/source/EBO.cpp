#include "EBO.h"

namespace Coco
{
	void EBO::Init()
	{
		this->Delete();
		glGenBuffers(1, &ID);
	}

	void EBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	}

	void EBO::PassData(std::vector<unsigned int> data)
	{
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), data.data(), GL_STATIC_DRAW);
		this->UnBind();
	}

	void EBO::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void EBO::Delete()
	{
		if (ID != 0)
		{
			glDeleteBuffers(1, &ID);
		}
	}

	EBO::~EBO()
	{
		this->Delete();
	}
}