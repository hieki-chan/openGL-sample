#pragma once

#include "openGL.h"

class table : public glObject
{
	
public:
	table(vec4* vertices, unsigned int* triangles) : glObject(vertices, triangles)
	{
		init();
	}

	void initGeometry() override;

	void initBuffer() override;

	void initShader() override;

	void draw() override;
};


table createTable();

