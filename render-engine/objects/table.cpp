#include "objects/table.h"

void drawTable(vec3 position, vec3 rotation, vec3 scale)
{
	drawCube(vec3(0, 0, 0), vec3(), vec3(1.1, .05, .6), color(0.76, 0.60, 0.42, 1));

	drawCube(vec3(0, -0.25, -0.2), vec3(), vec3(.95, .5, .05), color(0.55, 0.27, 0.07, 1));
	drawCube(vec3(-0.45, -0.25, 0), vec3(), vec3(.05, .5, .45), color(0.55, 0.27, 0.07, 1));
	drawCube(vec3(0.45, -0.25, 0), vec3(), vec3(.05, .5, .45), color(0.55, 0.27, 0.07, 1));

	drawCube(vec3(.47, -0.25, .22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(-.47, -0.25, .22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(.47, -0.25, -.22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));
	drawCube(vec3(-.47, -0.25, -.22), vec3(), vec3(.05, .5, .05), color(0.36, 0.25, 0.20, 1));

	drawCube(vec3(0, -0.2, -0.23), vec3(), vec3(1, .05, .05), color(0.76, 0.60, 0.42, 1));
	drawCube(vec3(0.48, -0.2, -0.0025), vec3(), vec3(.05, .05, .505), color(0.76, 0.60, 0.42, 1));
	drawCube(vec3(-0.48, -0.2, -0.0025), vec3(), vec3(.05, .05, .505), color(0.76, 0.60, 0.42, 1));

	drawCube(vec3(0, -0.5, -0.23), vec3(), vec3(1, .05, .05), color(0.76, 0.60, 0.42, 1));
	drawCube(vec3(0.48, -0.5, -0.0025), vec3(), vec3(.05, .05, .505), color(0.76, 0.60, 0.42, 1));
	drawCube(vec3(-0.48, -0.5, -0.0025), vec3(), vec3(.05, .05, .505), color(0.76, 0.60, 0.42, 1));
}

void tableKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	default:
		break;
	}
}