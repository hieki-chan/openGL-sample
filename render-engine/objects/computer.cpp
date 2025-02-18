#include "objects/computer.h"

vec3 computer_position;

void drawComputer(vec3 position, vec3 rotation, vec3 scale)
{

	position += computer_position;	//cong them cube input
	mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

	drawCube(vec3(0, 0, 0), vec3(), vec3(.05, .4, .6), color(1, 1, 1, 1));

	drawCube(vec3(0, .2, 0), vec3(), vec3(.07, .05, .7), color(0, 0, 0, 1));
	drawCube(vec3(0, -.2, 0), vec3(), vec3(.07, .05, .7), color(0, 0, 0, 1));
	drawCube(vec3(0, 0, .325), vec3(), vec3(.07, .4, .05), color(0, 0, 0, 1));
	drawCube(vec3(0, 0, -.325), vec3(), vec3(.07, .4, .05), color(0, 0, 0, 1));

	drawCube(vec3(-.05, 0, 0), vec3(), vec3(.05, .4, .6), color(0.05, 0.05, 0.05, 1));

	drawCube(vec3(-.1, -.15, 0), vec3(0, 0, -15), vec3(.05, .4, .2), color(0.15, 0.15, 0.15, 1));

	drawCube(vec3(-.08, -.35, 0), vec3(), vec3(.4, .08, .5), color(0, 0, 0, 1));

	cubeReset();
}

void computerKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 'a':
		computer_position.x -= 0.1f;
		break;
	case 'A':
		computer_position.x += 0.1f;
		break;
	default:
		break;
	}
}