#include "core/glObject.h"


glObject::glObject(vec4* vertices, unsigned int* triangles) : vertices(vertices), triangles(triangles)
{
	VAO = VBO = EBO = 0;
}

void glObject::init()
{
	initGeometry();
	initBuffer();
	initShader();
}