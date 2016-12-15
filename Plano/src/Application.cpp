#include "Application.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#include "glm\matrix.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "ShaderFuncs.h"
#include "glm\vec3.hpp"

Application::Application() : plane() { }

Application::~Application() { }

void Application::loadShaders() {
	sVertex = loadTextFile("Shaders/gouradPlane.v");
	sFragment = loadTextFile("Shaders/passThru.f");
}

void Application::setup() {
	eye = glm::vec3(0.0f, 50.0f, 105.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	vEye = glm::vec3(0.0f, 100.0f, 100.0f);

	plane.fAngleX = 0.0;
	plane.fAngleY = 0.0;
	plane.fAngleZ = 0.0;

	plane.createPlane(15);

	loadShaders();
	InitializeProgram(plane.shaders, sVertex, sFragment);

	plane.uTransform[0] = glGetUniformLocation(plane.shaders, "mTransform");
	plane.uTime[0] = glGetUniformLocation(plane.shaders, "fTime");
	plane.uEye[0] = glGetUniformLocation(plane.shaders, "vEye");
	uMyLightPosition[0] = glGetUniformLocation(plane.shaders, "myLightPosition");

	glGenVertexArrays(1, &plane.VerAr);
	glBindVertexArray(plane.VerAr);
	glGenBuffers(1, &plane.VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, plane.VerBuff);

	glBufferData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes() + plane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, plane.getVertexSizeInBytes(), plane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, plane.getVertexSizeInBytes(), plane.getTextureCoordsSizeInBytes(), plane.textureCoords);
	plane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glEnable(GL_DEPTH_TEST); // Field of view
}

void Application::update() {
	plane.fAngleY = plane.fAngleY + 0.1f; // PC
	//plane.fAngleY = plane.fAngleY + 0.05f; // LAP
	plane.time = plane.time + 0.1f;
}


void Application::display() {
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_BACK, GL_LINE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glUseProgram(plane.shaders);
	glBindVertexArray(plane.VerAr);

	glm::mat4 Transformaciones;

	rotation = rotationX * rotationY * rotationZ;
	cam = glm::lookAt(eye, target, up);
	pers = glm::perspective(45.0f, (640.0f / 480.0f), 0.1f, 180.0f);
	rotation = pers * cam * rotation;

	glUniformMatrix4fv(plane.uTransform[0], 1, GL_FALSE, glm::value_ptr(rotation));
	glUniform1f(plane.uTime[0], plane.time);
	glUniform1f(plane.uEye[0], plane.eye);
	glDrawArrays(GL_TRIANGLES, 0, plane.getNumVertex());
}

void Application::reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}