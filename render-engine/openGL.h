#pragma once

#include "Angel.h"			//Angel lib
#include "glslutils.h"		//gl shader utils

#include<Windows.h>			//for MS-windows

#define TRIANGLES GL_TRIANGLES

#define Deg2Rad Angel::DegreesToRadians
#define Rad2Deg = 1.0f / Deg2Rad;


#pragma region GL INIT FUNCTIONS

/// <summary>
/// Gen and bind VAO
/// </summary>
/// <returns></returns>
GLuint initVAO();

/// <summary>
/// 
/// </summary>
/// <param name="size"></param>
/// <param name="data"></param>
/// <param name="usage"></param>
/// <returns></returns>
GLuint initVBO(GLsizeiptr size, const void* data, GLenum usage);

/// <summary>
/// 
/// </summary>
/// <param name="index"></param>
/// <param name="size"></param>
/// <param name="stride"></param>
/// <param name="pointer"></param>
void vertexAttribPointer(GLuint index, GLint size, GLsizei stride, const void* pointer);

GLuint initEBO(GLsizeiptr size, const void* data, GLenum usage);

void unbind(GLuint VAO, GLuint VBO);

#pragma endregion


