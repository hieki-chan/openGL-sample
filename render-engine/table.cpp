#include "table.h"


table createTable()
{
	vec4 vertices[] =
	{
		vec4(),
	};

	unsigned int triangles[] =
	{
		1
	};

	return table(vertices, triangles);
}

void table::initGeometry()
{
	vertices = new vec4[1]
	{
		vec4(0, 0, 0, 0),
	};

	unsigned int triangles[] =
	{
		1
	};
}

void table::initBuffer()
{
	VAO = initVAO();
	//VBO = initVBO();
}

void table::initShader()
{

}

void table::draw()
{

}
