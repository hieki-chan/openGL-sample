#include "objects/mouse.h"

void drawMouse(vec3 position, vec3 rotation, vec3 scale)
{
    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    cubeTransform(position, rotation, scale);

    color color1 = color(.2, .2, .2, 1);
    color color2 = color(.7, .7, .7, 1);

    drawCube(vec3(0, 0, 0), vec3(), vec3(.3, .1, .5), color(color1));
    drawCube(vec3(0, .05, 0), vec3(), vec3(.25, .1, .45), color(color1));

    drawCube(vec3(-.06, .065, -.1), vec3(), vec3(.07, .1, .12), color(color2));
    drawCube(vec3(.06, .065, -.1), vec3(), vec3(.07, .1, .12), color(color2));
}

