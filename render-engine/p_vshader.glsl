#version 400

in vec4 vPosition;

uniform mat4 matrix;

void main()
{
	gl_Position =  matrix * vPosition;
}