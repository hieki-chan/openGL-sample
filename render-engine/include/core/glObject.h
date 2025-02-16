#pragma once

#include "openGL.h"

class glObject
{
protected:
	vec4* vertices;
	unsigned int* triangles;

	//buffers
	GLuint VAO, VBO, EBO;

public:
	glObject(vec4* vertices, unsigned int* triangles);

	void init();

	virtual void initGeometry() = 0;

	virtual void initBuffer() = 0; //abstraction

	virtual void initShader() = 0;

	virtual void draw() = 0;
};

