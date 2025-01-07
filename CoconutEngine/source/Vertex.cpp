#include "Vertex.h"

namespace Coco
{


	Vertex::Vertex(float x, float y, float z, float nx, float ny, float nz, float txx, float txy)
			:
		pos(glm::vec3(x,y,z)),
		norm(glm::vec3(nx,ny,nz)),
		texture_pos(glm::vec2(txx,txy))
	{

	}
	Vertex::Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 texture_pos)
		:
		pos(pos),
		norm(norm),
		texture_pos(texture_pos)
	{

	}
	Vertex::~Vertex()
	{

	}
}	