#pragma once

#include <iostream>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

class Object3D{
public:
	GLuint	VerAr, VerBuff; 

	int VerNum; 

	GLuint shaders; //shaders
	GLuint uniform; //angulo almacenado
	float fAngle;
	float fAngleX, fAngleY, fAngleZ;
	float time;
	float eye;
	float myLight;
};

