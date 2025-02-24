#include "objects/robo.h"

vec3 robo_position, robo_rotate;

void drawRobo(vec3 position, vec3 rotation, vec3 scale)
{
    position += robo_position;
    rotation += robo_rotate;

    mat4 globalTransformMatrix = sphereTransform(position, rotation, scale);

    color color1 = color(.2, .2, .2, 1);
    color color2 = color(.7, .7, .7, 1);

    drawSphere(vec3(.05, 0, 0), vec3(), vec3(.4, .4, .5), color(color1));

    drawSphere(vec3(.16, .0, -.11), vec3(), vec3(.15, .15, .15), color(color2));

    drawSphere(vec3(.16, .0, .11), vec3(), vec3(.15, .15, .15), color(color2));

    drawSphere(vec3(0, 0, 0), vec3(), vec3(.4, .5, .5), color(color2));

    drawSphere(vec3(0, -.6, 0), vec3(), vec3(.4, .8, .5), color(color1));

    drawSphere(vec3(0, -.6, 0), vec3(), vec3(.45, .75, .55), color(color2));

    drawSphere(vec3(0, -1.2, 0), vec3(0, 0, 0), vec3(.3, .3, .3), color(color2));

    drawSphere(vec3(.15, -.55, .25), vec3(0, -10, 30), vec3(.3, .6, .15), color(color2));

    drawSphere(vec3(.15, -.55, -.25), vec3(0, 10, 45), vec3(.3, .6, .15), color(color2));

    sphereReset();
}

void roboKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 'a':
		robo_position.z -= 0.5f;
		break;
	case 'd':
		robo_position.z += 0.5f;
		break;
	case 's':
		robo_position.x -= 0.5f;
		break;
	case 'w':
		robo_position.x += 0.5f;
		break;
	case 'q':
		robo_rotate.y += 2;
		break;
	case 'e':
		robo_rotate.y -= 2;
		break;
	default:
		break;
	}
}