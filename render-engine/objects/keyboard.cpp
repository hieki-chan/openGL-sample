#include "objects/keyboard.h"

void drawKeyboard(vec3 position, vec3 rotation, vec3 scale)
{
    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    cubeTransform(position, rotation, scale);

    color color1 = color(.2, .2, .2, 1);
    color color2 = color(.7, .7, .7, 1);

    drawCube(vec3(0, 0, 0), vec3(), vec3(2, .1, .8), color(color1));

    drawCube(vec3(.8, .05, 0), vec3(), vec3(.3, .04, .6), color(color2));
    drawCube(vec3(-.4, .05, 0), vec3(), vec3(1, .04, .3), color(color2));
    drawCube(vec3(-.4, .05, -.25), vec3(), vec3(1, .04, .1), color(color2));
    drawCube(vec3(-.45, .05, .25), vec3(), vec3(.6, .04, .1), color(color2));
    drawCube(vec3(-.85, .05, .25), vec3(), vec3(.1, .04, .1), color(color2));
    drawCube(vec3(0, .05, .25), vec3(), vec3(.2, .04, .1), color(color2));
    drawCube(vec3(.4, .05, .25), vec3(), vec3(.3, .04, .08), color(color2));
    drawCube(vec3(.4, .05, -.15), vec3(), vec3(.3, .04, .3), color(color2));
    drawCube(vec3(.4, .05, .2), vec3(), vec3(.08, .04, .15), color(color2));
}

