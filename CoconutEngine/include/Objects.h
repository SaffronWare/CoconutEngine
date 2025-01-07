#pragma once
#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp> 

#include <vector>
#include <iterator>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Vertex.h"

namespace Coco
{
    class Renderer;

    const Vertex CUBE_VERTICES[24] = {
        Vertex(-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f),
        Vertex(0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f),
        Vertex(-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f),

        Vertex(-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f),
        Vertex(0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f),
        Vertex(0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f),
        Vertex(-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f),

        Vertex(-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f),
        Vertex(-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f),
        Vertex(-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f),
        Vertex(-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f),

        Vertex(0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f),
        Vertex(0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f),
        Vertex(0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f),

        Vertex(-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f),
        Vertex(0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f),
        Vertex(0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f),
        Vertex(-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f),

        Vertex(-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f),
        Vertex(0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f),
        Vertex(0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f),
        Vertex(-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f)
    };

    const unsigned int CUBE_EBO[36] = {
        0, 1, 2,
        0, 2, 3,

        4, 5, 6,
        4, 6, 7,

        8, 9, 10,
        8, 10, 11,

        12, 13, 14,
        12, 14, 15,

        16, 17, 18,
        16, 18, 19,

        20, 21, 22,
        20, 22, 23
    };

	class Object
	{
        friend class Renderer;

    protected:
		VAO vao;
		VBO vbo;
        EBO ebo;

    public:
		glm::vec3 rotation;
		glm::vec3 position;
		glm::vec3 scale = glm::vec3(1,1,1);

        std::vector<Vertex> vertex_data = {};
        std::vector<unsigned int> index_data = {};

        glm::mat4 getMatrix()
        {
            glm::mat4 rot1 = glm::rotate(glm::mat4(1.0f), rotation.x, glm::vec3(1, 0, 0));
            glm::mat4 rot2 = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0, 1, 0));
            glm::mat4 rot3 = glm::rotate(glm::mat4(1.0f), rotation.z, glm::vec3(0, 0, 1));

            glm::mat4 trans = glm::translate(glm::mat4(1.0f), position);

            glm::mat4 scal = glm::scale(glm::mat4(1.0f), scale);
            //return glm::mat4(1.0f);
            return trans * scal * rot1 * rot2 * rot3;
        }

        virtual void Init() = 0;

        ~Object()
        {
            vao.Delete();
            vbo.Delete();
            ebo.Delete();
        }

    };

	struct Cube : public Object
	{

        Cube() {}
        void Init() override
        {
            vertex_data = std::vector(std::begin(CUBE_VERTICES), std::end(CUBE_VERTICES));
            index_data = std::vector(std::begin(CUBE_EBO), std::end(CUBE_EBO));


            vao.Init();
            vbo.Init();
            ebo.Init();

            vbo.PassData(vertex_data);
            ebo.PassData(index_data);

            vao.AddVBO(vbo);
            vao.AddEBO(ebo);
        }
	};
}