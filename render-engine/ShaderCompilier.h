#ifndef SHADERCOMPILIER_H
#define SHADERCOMPILIER_H
#include<GL/glew.h>
#include<iostream>

GLuint shaderProgram;

GLuint compileShader(GLenum shaderType, const char* shaderSource)
{
	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	//check for errors
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Compile shader error: " << infoLog << std::endl;
	}

	return shader;
}

void initProgram(GLuint vertexShader, GLuint fragmentShader)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(fragmentShader, vertexShader);
	glLinkProgram(shaderProgram);

	//check for errors
	int status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}
}

void loadShader()
{

}

#endif // SHADERCOMPILIER_H

