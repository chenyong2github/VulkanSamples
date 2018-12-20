/*
* Basic camera class
*
* Copyright (C) 2016 by Sascha Willems - www.saschawillems.de
*
* This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
*/

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
private:
	float fov;
	float znear, zfar;

	void updateViewMatrix()
	{
		viewMat = glm::lookAt(
			position,
			lookat,
			glm::vec3(0, 1, 0)
		);
	};
public:
	glm::vec3 rotation = glm::vec3();
	glm::vec3 position = glm::vec3();
	glm::vec3 lookat = glm::vec3();

	float rotationSpeed = 1.0f;
	float movementSpeed = 1.0f;

	float zoomSpeed = 1.0f;
	float zoom = 0;

	void init(glm::vec3 position, 
		      glm::vec3 lookat, 		      
		      float zoomSpeed = 1.0f,
			  float rotationSpeed = 1.0f)
	{
		this->position = position;
		this->lookat = lookat;

		this->zoom = glm::length(position - lookat);
		this->zoomSpeed = zoomSpeed;

		this->rotationSpeed = rotationSpeed;

		updateViewMatrix();
	}

	glm::mat4 viewMat;
	glm::mat4 projMat;

	struct
	{
		bool left = false;
		bool right = false;
		bool up = false;
		bool down = false;
	} keys;

	bool moving()
	{
		return keys.left || keys.right || keys.up || keys.down;
	}

	float getNearClip() { 
		return znear;
	}

	float getFarClip() {
		return zfar;
	}

	void setPerspective(float fov, float aspect, float znear, float zfar)
	{
		this->fov = fov;
		this->znear = znear;
		this->zfar = zfar;
		projMat = glm::perspective(glm::radians(fov), aspect, znear, zfar);
	};

	void updateAspectRatio(float aspect)
	{
		projMat = glm::perspective(glm::radians(fov), aspect, znear, zfar);
	}

	void setPosition(glm::vec3 position)
	{
		this->position = position;

		updateViewMatrix();
	}

	void setLookat(glm::vec3 lookat)
	{
		this->lookat = lookat;

		updateViewMatrix();
	}

	void setZoom(float zoom)
	{
		glm::vec3 front = glm::normalize(this->position - this->lookat);
		this->position = this->lookat + front*zoom;

		updateViewMatrix();
	}
};