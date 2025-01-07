#pragma once

#include <glm/glm.hpp>

namespace Coco
{
	struct Vertex
	{
		glm::vec3 pos;
		glm::vec3 norm;
		glm::vec2 texture_pos;

		Vertex(float x, float y, float z, float nx, float ny, float nz, float txx, float txy);
		Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 texture_pos);
		~Vertex();
	};
}