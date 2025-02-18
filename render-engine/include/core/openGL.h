#pragma once

#include "Angel.h"			//Angel lib

#include<iostream>
#include <cmath>
#include <cstring>
#include<Windows.h>			//for MS-windows

#include "glObject.h"

#define Deg2Rad Angel::DegreesToRadians
#define Rad2Deg = (1.0f / Deg2Rad);


#define INIT_PROGRAM Angel::InitShader

typedef vec4 color;
typedef vec3 color3;
typedef vec4 point4;

#define WHITE color(1, 1, 1, 1);

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

void bind(GLuint program, GLuint VAO);

void unbind(GLuint VAO = 0, GLuint program = 0);

#pragma endregion


#pragma region MATH UTILS

mat4 TRS(const vec3& position, const vec3& rotation, const vec3& scale);

#pragma endregion



#pragma region SHADERS

GLuint compileShader(GLenum glShaderType, const char* shaderSource);

GLuint initProgram(GLuint vertexShader, GLuint fragmentShader);

GLuint initProgram(const char* vertexShaderPath, const char* fragmentShaderPath);

void setUniformVec3(GLuint program, const std::string& name, const vec3& value);

void setUniformVec4(GLuint program, const std::string& name, const vec4& value);

#pragma endregion



