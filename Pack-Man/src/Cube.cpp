
#include "Cube.h"
#include <iostream>
#include <vector>

#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#include "ShaderFuncs.h"
#include "glm\vec3.hpp"

char Laberinto[15][15]{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
	{0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 1, 2, 1, 0, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
	{0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

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

Cube::Cube() 
{}

Cube::~Cube() 
{}

void Cube::setup()
{
	eye = glm::vec3(-1.0f, 18.0f, 0.0f);

	
	target = glm::vec3(5.0f, 0.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	
	
	triangle.fAngleX = 0.0;
	triangle.fAngleY = 0.0;
	triangle.fAngleZ = 0.0;

	std::string strVertexShader = loadTextFile("Shaders/passThru.vs");
	std::string strFragmentShader = loadTextFile("Shaders/passThru.fs");

	InitializeProgram(triangle.shaders, strVertexShader, strFragmentShader);
	triangle.uniform = glGetUniformLocation(triangle.shaders, "transform");

	triangle.VerNum = 36;
	glGenVertexArrays(1, &triangle.VerAr);
	glBindVertexArray(triangle.VerAr);
	glGenBuffers(1, &triangle.VerBuff);
	glBindBuffer(GL_ARRAY_BUFFER, triangle.VerBuff);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
}

void Cube::update()
{
}


void Cube::display()
{

	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Seleccionamos los shaders a usar
	glUseProgram(triangle.shaders);

	//activamos el vertex array object y dibujamos
	glBindVertexArray(triangle.VerAr);

	//camara
	cam = glm::lookAt(eye, target, up);
	pers = glm::perspective(45.0f, (640.0f / 480.0f), 0.1f, 20.0f);

	for (int i = 0; i < 15; i++) {

		for (int j = 0; j < 15; j++) {

			glm::mat4 traslacion = glm::translate(glm::mat4(1.0f), glm::vec3(1.5f*i, 0.0f, 1.5f*j));
		

				if (Laberinto[i][j] == 0) {
		
					rotationX = glm::rotate(glm::mat4(1.0f), (triangle.fAngleX * 3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
					rotationY = glm::rotate(glm::mat4(1.0f), (triangle.fAngleY * 3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
					rotationZ = glm::rotate(glm::mat4(1.0f), (triangle.fAngleZ * 3.141592f / 180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
					rotation = rotationX * rotationY * rotationZ;
					//pipe line
					rotation = pers * cam * traslacion*rotation;

		//Dibujado
					glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(rotation)); 

					glDrawArrays(GL_TRIANGLES, 0, triangle.VerNum);
				}
				else if (Laberinto[i][j] == 1) {
					glm::mat4 escalacion = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 0.5f));
					
					rotationX = glm::rotate(glm::mat4(1.0f), (triangle.fAngleX * 3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
					rotationY = glm::rotate(glm::mat4(1.0f), (triangle.fAngleY * 3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
					rotationZ = glm::rotate(glm::mat4(1.0f), (triangle.fAngleZ * 3.141592f / 180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
					rotation = rotationX * rotationY * rotationZ;
					//pipe line
					rotation = pers * cam * traslacion*rotation*escalacion;

					//Dibujado
					glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(rotation));

					glDrawArrays(GL_TRIANGLES, 0, triangle.VerNum);
				}
				else if (Laberinto[i][j] == 2) {
					glm::mat4 escalacion = glm::scale(glm::mat4(1.0f), glm::vec3(0.75f, 0.75f, 0.75f));

					rotationX = glm::rotate(glm::mat4(1.0f), (triangle.fAngleX * 3.141592f / 180.0f), glm::vec3(1.0f, 0.0f, 0.0f));
					rotationY = glm::rotate(glm::mat4(1.0f), (triangle.fAngleY * 3.141592f / 180.0f), glm::vec3(0.0f, 1.0f, 0.0f));
					rotationZ = glm::rotate(glm::mat4(1.0f), (triangle.fAngleZ * 3.141592f / 180.0f), glm::vec3(0.0f, 0.0f, 1.0f));
					rotation = rotationX * rotationY * rotationZ;
					//pipe line
					rotation = pers * cam * traslacion*rotation*escalacion;

					//Dibujado
					glUniformMatrix4fv(triangle.uniform, 1, false, glm::value_ptr(rotation));

					glDrawArrays(GL_TRIANGLES, 0, triangle.VerNum);

				}
		}
	}
}

void Cube::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}
