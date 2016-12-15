#pragma once

#include <iostream>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

class Object3D{
public:
	GLuint	VerAr, VerBuff; 

	int VerNum; 

	GLuint shaders; 
	GLuint uniform; //ángulo
	float fAngle;
	float fAngleX, fAngleY, fAngleZ;
};

