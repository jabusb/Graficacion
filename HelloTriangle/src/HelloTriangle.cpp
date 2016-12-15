
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;

void setup()
{
	app.setup();
}

void display()
{
	app.display();
}

//Se 
void reshape(int w, int h)
{
	app.reshape(w, h);
}


int main(int argc, char *argv[])
{
	Application app;

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE; 
	glewInit();
	app.setup();

	// get version info 
	const GLubyte* renderer = glGetString (GL_RENDERER); 
	const GLubyte* version = glGetString (GL_VERSION); 
	printf (" Renderer: %s\ n", renderer); 
	printf (" OpenGL version supported %s\ n", version); 
	
	// tell GL to only draw onto a pixel if the shape is closer to the viewer 
	//glEnable (GL_DEPTH_TEST); // enable depth-testing 	
	//glDepthFunc (GL_LESS); // depth-testing interprets a smaller value as "closer" 

	glViewport(0, 0, (GLsizei)640, (GLsizei)480);

	while (!glfwWindowShouldClose(window))
	{
		/* update other events like input handling */
		glfwPollEvents();

		/* put the stuff we've been drawing onto the display */
		app.display();
		
		glfwSwapBuffers(window);
	}
	
	/* close GL context and any other GLFW resources */
	glfwTerminate();
	return 0;

}
