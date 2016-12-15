#pragma once

#include <iostream>
#include "Object3D.h"
#include "glm\mat4x4.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

class Cube {
public:
	Cube();
	~Cube();

	void setup();
	void update();
	void display();
	void reshape(int w, int h);


private:	
	Object3D triangle;
	glm::mat4 rotation;
	glm::mat4 rotationX;
	glm::mat4 rotationY;
	glm::mat4 rotationZ;
	glm::mat4 camPers;
	glm::mat4 cam;
	glm::mat4 pers;

	glm::vec3 eye;
	glm::vec3 target;
	glm::vec3 up;

};

