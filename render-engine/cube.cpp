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

float cubeVertices[CUBE_VERTEX_COUNT];

float vertexColors[] =
{
	0
};
int i = 0;
void quad(int v1, int v2, int v3, int v4)
{
	cubeVertices[i++] = trueVertices[v1];
	cubeVertices[i++] = trueVertices[v2];
	cubeVertices[i++] = trueVertices[v3];
	cubeVertices[i++] = trueVertices[v1];
	cubeVertices[i++] = trueVertices[v3];
	cubeVertices[i++] = trueVertices[v4];
}


void drawCube()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(7, 7, 4, 5);
	quad(5, 4, 0, 1);
	quad(5, 1, 2, 6);
	quad(4, 0, 3, 7);

	for (size_t i = 0; i < 36; i++)
	{
		std::cout << cubeVertices[i];
	}
}

void initCubeBuffers()
{
	
}