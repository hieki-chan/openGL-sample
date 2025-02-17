#include "objects/shelf.h"

void drawShelf(vec3 position, vec3 rotation, vec3 scale)
{
	drawCube(vec3(), vec3(), vec3(1, 1, 1), color(1, 0, 1, 1));

	drawCube(vec3(1, 1, 1), vec3(), vec3(.2, .2, 3), color(1, 0, 0, 1));
}
