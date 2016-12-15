#version 430 core

layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;
uniform vec3 vEye;
uniform vec3 myLightPosition;

out vec4 color;

float F(float x, float z) {
	return 4.0 * cos  (0.02 * (x*x + z*z) + fTime); 
}


void main()
{

	color = vec4(1.5, 0.0, 3.0, 2.0); 
	gl_Position = mTransform * vPosition;
}
