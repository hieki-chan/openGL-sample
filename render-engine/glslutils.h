#pragma once

#include<GL/glew.h>
#include<iostream>

//extern GLuint shaderProgram;
 
GLuint compileShader(GLenum glShaderType, const char* shaderSource);

GLuint initProgram(GLuint vertexShader, GLuint fragmentShader);

GLuint initProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
