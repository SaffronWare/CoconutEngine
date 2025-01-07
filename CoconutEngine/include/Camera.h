#pragma once

#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp> 


#include "Globals.h"
#include "Event.h"



namespace Coco
{
	class Camera
	{
	private:
		int MODE;

	public:
		bool attached = false;
		float aspect;
		float FOV = 1.7f;
		float speed = 5.0f;
		float sensitivity = 0.5f;
		glm::vec3 position = glm::vec3(0,0,-3);
		glm::vec3 orientation;
		glm::vec3 c_front;
		glm::vec3 c_right;
		glm::vec3 c_up;

		glm::mat4 getMatrix()
		{
			glm::vec4 front = glm::vec4(0, 0, 1,1);
			glm::mat4 rot1 = glm::rotate(glm::mat4(1.0f), orientation.x, glm::vec3(1, 0, 0));
			glm::mat4 rot2 = glm::rotate(glm::mat4(1.0f), orientation.y, glm::vec3(0, 1, 0));
			glm::mat4 rot3 = glm::rotate(glm::mat4(1.0f), orientation.z, glm::vec3(0, 0, 1));

			front = rot1 * rot2 * rot3 * front;
			c_front = glm::vec3(front);
			c_right = glm::cross(c_front, glm::vec3(0, 1, 0));
			//c_up = glm::cross(c_right, c_front);
			c_up = glm::vec3(0, 1, 0);
			glm::mat4 view = glm::lookAt(position, position + glm::vec3(front), glm::vec3(0, 1, 0));




			glm::mat4 perspective = glm::perspective(FOV, aspect, 0.1f, 1000.0f);

			return perspective * view;
		}

		void DefaultEventHandling(MouseEvent& event, float dt)
		{
			if (event.action == MouseEvent::MouseEventAction::CURSOR_MOVED && attached)
			{
				orientation.y -= sensitivity * dt * (event.x - event.ox);
				orientation.x += sensitivity * dt * (event.y - event.oy);

				orientation.x = std::max(orientation.x, -glm::pi<float>() / 2.0f);
				orientation.x = std::min(orientation.x, glm::pi<float>() / 2.0f);
			}
		}

		void DefaultEventHandling(KeyEvent& event, float dt)
		{
			if (event.action == KeyEvent::KeyEventAction::KEY_HELD)
			{
				if (event.key == COCO_KEY_W)
				{
					position += glm::float32(dt * speed) * c_front;
				}

				if (event.key == COCO_KEY_S)
				{
					position -= glm::float32(dt * speed) * c_front;
				}

				if (event.key == COCO_KEY_D)
				{
					position += glm::float32(dt * speed) * c_right;
				}

				if (event.key == COCO_KEY_A)
				{
					position -= glm::float32(dt * speed) * c_right;
				}

				if (event.key == COCO_KEY_E)
				{
					position += glm::float32(dt * speed) * c_up;
				}

				if (event.key == COCO_KEY_Q)
				{
					position -= glm::float32(dt * speed) * c_up;
				}
			}
		}

		Camera() = default;
	};
}