
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



GLfloat vertexPositions[] = {
	// Cara 1 
	-0.75f, 0.75f, 0.75f, 1.0f,		
	-0.75f, -0.75f, 0.75f, 1.0f,	
	0.75f, -0.75f, 0.75f, 1.0f,		
	
	-0.75f, 0.75f, 0.75f, 1.0f,		
	0.75f, -0.75f, 0.75f, 1.0f,		
	0.75f, 0.75f, 0.75f, 1.0f,		
	// Cara 2 
	0.75f, 0.75f, 0.75f, 1.0f,		
	0.75f, -0.75f, 0.75f, 1.0f,		
	0.75f, -0.75f, -0.75f, 1.0f,	

	0.75f, 0.75f, 0.75f, 1.0f,		
	0.75f, -0.75f, -0.75f, 1.0f,	
	0.75f, 0.75f, -0.75f, 1.0f,		
	// Cara 3 
	0.75f, 0.75f, -0.75f, 1.0f,	
	0.75f, -0.75f, -0.75f, 1.0f,
	-0.75f, -0.75f, -0.75f, 1.0f,	
	
	0.75f, 0.75f, -0.75f, 1.0f,		
	-0.75f, -0.75f, -0.75f, 1.0f,	
	-0.75f, 0.75f, -0.75f, 1.0f,	
	// Cara 4 
	-0.75f, 0.75f, -0.75f, 1.0f,	
	-0.75f, -0.75f, -0.75f, 1.0f,	
	-0.75f, -0.75f, 0.75f, 1.0f,	

	-0.75f, 0.75f, -0.75f, 1.0f,	
	-0.75f, -0.75f, 0.75f, 1.0f,	
	-0.75f, 0.75f, 0.75f, 1.0f,		
	// Cara 5 
	-0.75f, 0.75f, -0.75f, 1.0f,	
	-0.75f, 0.75f, 0.75f, 1.0f,		
	0.75f, 0.75f, 0.75f, 1.0f,	
	
	-0.75f, 0.75f, -0.75f, 1.0f,	
	0.75f, 0.75f, 0.75f, 1.0f,		
	0.75f, 0.75f, -0.75f, 1.0f,		
	// Cara 6 
	-0.75f, -0.75f, 0.75f, 1.0f,	
	-0.75f, -0.75f, -0.75f, 1.0f,	
	0.75f, -0.75f, -0.75f, 1.0f,	

	-0.75f, -0.75f, 0.75f, 1.0f,	
	0.75f, -0.75f, -0.75f, 1.0f,	
	0.75f, -0.75f, 0.75f, 1.0f,	
};


GLfloat vertexColors[] = {
	//Cara 1
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,

	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,
	0.0, 1.0, 0.0, 1.0,

	//Cara 2
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	1.0, 0.0, 0.0, 1.0,
	//Cara 3 
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,

	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	0.0, 0.0, 1.0, 1.0,
	//Cara 4 
	1.0, 0.3, 0.0, 1.0,
	1.0, 0.3, 0.0, 1.0,
	1.0, 0.3, 0.0, 1.0,

	1.0, 0.3, 0.0, 1.0,
	1.0, 0.3, 0.0, 1.0,
	1.0, 0.3, 0.0, 1.0,
	//Cara 5
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,

	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	1.0, 1.0, 1.0, 1.0,
	//Cara 6
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,

	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
	1.0, 1.0, 0.0, 1.0,
};

Application::Application() 
{}

Application::~Application() 
{}

void Application::setup()
{
	eye = glm::vec3(5.0f, 7.0f, -5.0f);
	target = glm::vec3(0.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	
	triangle.fAngleX = 0.0;
	triangle.fAngleY = 0.0;
	triangle.fAngleZ = 0.0;

	loadShaders();

	InitializeProgram(triangle.shaders, strVertexShader, strFragmentShader);
	triangle.uniform = glGetUniformLocation(triangle.shaders, "transform");

	triangle.VerNum = 36;
	glGenVertexArrays(1, &triangle.VerAr);
	glBindVertexArray(triangle.VerAr);
	glGenBuffers(1, &triangle.VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.VerBuff);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void Application::update() {
	triangle.fAngleX = triangle.fAngleX + 0.001f;
	triangle.fAngleY = triangle.fAngleY + 0.001f;
	triangle.fAngleZ = triangle.fAngleZ + 0.001f;
}


void Application::display() {
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	miniMap();
}

void Application::loadShaders() {
	strVertexShader = loadTextFile("Shaders/passThru.vs");
	strFragmentShader = loadTextFile("Shaders/passThru.fs");
}

void Application::miniMap() {
	glViewport(0, 0, (GLsizei)640, (GLsizei)480);

	glUseProgram(triangle.shaders);

	glBindVertexArray(triangle.VerAr);
	
	rotationX = glm::rotate(glm::mat4(1.0f), (triangle.fAngleX * 3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	rotationY = glm::rotate(glm::mat4(1.0f), (triangle.fAngleY * 3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	rotationZ = glm::rotate(glm::mat4(1.0f), (triangle.fAngleZ * 3.141592f / 180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	rotation = rotationX * rotationY * rotationZ;
	cam = glm::lookAt(eye, target, up);
	pers = glm::perspective(45.0f, (640.0f / 480.0f), 0.1f, 20.0f);
	rotation = pers * cam * rotation;


	glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(rotation));

	glDrawArrays(GL_TRIANGLES, 0, triangle.VerNum);
}

void Application::reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
