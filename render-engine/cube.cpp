#include "cube.h"
#include<iostream>

const int CUBE_VERTEX_COUNT = 36;

float trueVertices[] =
{
	-0.5f, -0.5f, 0.5f, 1.0f,
	-0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, 0.5f, 0.5f, 1.0f,
	0.5f, -0.5f, 0.5f, 1.0f,
	-0.5f, -0.5f, -0.5f, 1.0f,
	-0.5f, 0.5f, -0.5f, 1.0f,
	0.5f, 0.5f, -0.5f, 1.0f,
	0.5f, -0.5f, -0.5f, 1.0f
};

float cubeVertices[CUBE_VERTEX_COUNT * 4];

float vertexColors[] =
{
	0
};
int i = 0;
void quad(int v1, int v2, int v3, int v4)
{
	cubeVertices[i++] = trueVertices[v1 * 4]; 
	cubeVertices[i++] = trueVertices[v1 * 4 + 1]; 
	cubeVertices[i++] = trueVertices[v1 * 4 + 2];
	cubeVertices[i++] = trueVertices[v2 * 4]; 
	cubeVertices[i++] = trueVertices[v2 * 4 + 1]; 
	cubeVertices[i++] = trueVertices[v2 * 4 + 2]; 
	cubeVertices[i++] = trueVertices[v3 * 4]; 
	cubeVertices[i++] = trueVertices[v3 * 4 + 1]; 
	cubeVertices[i++] = trueVertices[v3 * 4 + 2]; 
	cubeVertices[i++] = trueVertices[v1 * 4]; 
	cubeVertices[i++] = trueVertices[v1 * 4 + 1]; 
	cubeVertices[i++] = trueVertices[v1 * 4 + 2]; 
	cubeVertices[i++] = trueVertices[v3 * 4]; 
	cubeVertices[i++] = trueVertices[v3 * 4 + 1];
	cubeVertices[i++] = trueVertices[v3 * 4 + 2]; 
	cubeVertices[i++] = trueVertices[v4 * 4]; 
	cubeVertices[i++] = trueVertices[v4 * 4 + 1]; 
	cubeVertices[i++] = trueVertices[v4 * 4 + 2];
}

void initCube()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);

	i = 0;
}


void initCubeBuffers()
{
	GLuint VAO, VBO;
	//vertex array object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//vertex buffer object
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glDrawArrays(GL_LINE_LOOP, 0, CUBE_VERTEX_COUNT);

	glutSwapBuffers();

	
}

void drawCube()
{
	initCube();
	initCubeBuffers();
}

void deleteCube()
{
	
}