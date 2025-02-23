#include "objects/b52.h"
void drawB52(vec3 position, vec3 rotation, vec3 scale)
{
    color bodyPlane = color(0.3, 0.3, 0.3, 1);
    color wingPlane = color(0.4, 0.4, 0.4, 1);

    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    cubeTransform(position, rotation, scale);
    planeTransform(position, rotation, scale);
    sphereTransform(position, rotation, scale);

    //than may bay
    drawCylinder(vec3(0, 0, 0), vec3(90, 0, 90), vec3(1, 4.5, 1.2), bodyPlane);
    drawCylinder(vec3(3, -.035, 0), vec3(90, 10, 90), vec3(.8, 2, .8), bodyPlane);
    drawCylinder(vec3(3, .2, 0), vec3(90, 0, 90), vec3(.8, 2, .8), bodyPlane);
    drawCylinder(vec3(3, .1, 0), vec3(90, 5, 90), vec3(.9, 2, .9), bodyPlane);
    drawCylinder(vec3(4, .3, 0), vec3(90, 2, 90), vec3(.6, 2, .6), bodyPlane);
    drawPlane(vec3(5, .2, 0), vec3(90, -88, 0), vec3(.75, .3, 2), bodyPlane);

    //dau may bay
    drawSphere(vec3(-2.4, -.1, 0), vec3(0, 0, 0), vec3(3, 1, 1), bodyPlane);
    drawSphere(vec3(-2.25, .095, 0), vec3(0, 0, 0), vec3(1.65, 1, .95), bodyPlane);

    //canh phai
    drawPlane(vec3(.5, .2, -2.5), vec3(0, -30, 0), vec3(1.5, .1, 6), wingPlane);

    drawPlane(vec3(-.7, 0, -2), vec3(-90, 80, 0), vec3(.3, .05, .8), wingPlane);

    drawCylinder(vec3(-1.1, 0, -2.18), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(-.5, 0, -2.18), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-1.38, 0, -2.18), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-1.1, 0, -2.18), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawCylinder(vec3(-1.1, 0, -1.83), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(-.5, 0, -1.83), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-1.38, 0, -1.83), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-1.1, 0, -1.83), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawPlane(vec3(0, 0, -3.5), vec3(-90, 80, 0), vec3(.3, .05, .8), wingPlane);

    drawCylinder(vec3(-.2, 0, -3.68), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(.4, 0, -3.68), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-.48, 0, -3.68), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-.2, 0, -3.68), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawCylinder(vec3(-.2, 0, -3.33), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(.4, 0, -3.33), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-.48, 0, -3.33), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-.2, 0, -3.33), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawSphere(vec3(.8, 0, -4.5), vec3(-90, 80, 0), vec3(.3, .25, 1), wingPlane);

    //canh trai
    drawPlane(vec3(.5, .2, 2.5), vec3(180, -30, 0), vec3(1.5, .1, 6), wingPlane);

    drawPlane(vec3(-.7, 0, 2), vec3(-90, 80, 0), vec3(.3, .05, .8), wingPlane);

    drawCylinder(vec3(-1.1, 0, 2.18), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(-.5, 0, 2.18), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-1.38, 0, 2.18), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-1.1, 0, 2.18), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawCylinder(vec3(-1.1, 0, 1.83), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(-.5, 0, 1.83), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-1.38, 0, 1.83), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-1.1, 0, 1.83), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawPlane(vec3(0, 0, 3.5), vec3(-90, 80, 0), vec3(.3, .05, .8), wingPlane);

    drawCylinder(vec3(-.2, 0, 3.68), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(.4, 0, 3.68), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-.48, 0, 3.68), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-.2, 0, 3.68), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawCylinder(vec3(-.2, 0, 3.33), vec3(0, 0, 90), vec3(.35, .6, .35), wingPlane);
    drawCylinder(vec3(.4, 0, 3.33), vec3(0, 0, 90), vec3(.3, .6, .3), wingPlane);
    drawCylinder(vec3(-.48, 0, 3.33), vec3(0, 0, 90), vec3(.3, .05, .3), wingPlane);
    drawSphere(vec3(-.2, 0, 3.33), vec3(0, 0, 90), vec3(.3, 1, .3), wingPlane);

    drawSphere(vec3(.8, 0, 4.5), vec3(-90, 80, 0), vec3(.3, .25, 1), wingPlane);

    //duoi may bay
    drawPlane(vec3(5, .2, -1), vec3(0, 0, 180), vec3(1, .1, 2), color(0.2, 0.2, 0.2, 1));
    drawPlane(vec3(5, .2, 1), vec3(180, 0, 0), vec3(1, .1, 2), color(0.2, 0.2, 0.2, 1));
    drawPlane(vec3(5, 1, 0), vec3(90, 0, 180), vec3(1, .1, 2), color(0.2, 0.2, 0.2, 1));

}