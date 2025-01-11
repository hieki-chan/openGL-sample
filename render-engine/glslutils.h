#pragma once

#include<GL/glew.h>
#include<iostream>

extern GLuint shaderProgram;
 
GLuint compileShader(GLenum glShaderType, const char* shaderSource);

void initProgram(GLuint vertexShader, GLuint fragmentShader);

void loadShader(const char* vertexShaderPath, const char* fragmentShaderPath);
