#include "objects/airplaneOfDuyen.h"

vec3 airPlaneOfDuyen_rotate;

void drawAirplaneOfDuyen(vec3 position, vec3 rotation, vec3 scale)
{
    color bodyColor = color(0.33, 0.27, 0.93, 1);
    mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);
    cylinderTransform(position, rotation, scale);

    // Thân trực thăng
    drawCube(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0.5, 0.25, 0.25), bodyColor);

    // Đầu trực thăng
    drawCube(vec3(-0.25, 0, 0), vec3(0, 0, 45), vec3(0.18, 0.18, 0.25), bodyColor);

    // Cửa sổ trực thăng
    drawCube(vec3(-0.1, 0.01, 0.125), vec3(0, 0, 0), vec3(0.11, 0.15, 0.005), WHITE);
    drawCube(vec3(-0.1, 0.01, -0.125), vec3(0, 0, 0), vec3(0.11, 0.15, 0.005), WHITE);
    drawCube(vec3(0.1, 0.01, 0.125), vec3(0, 0, 0), vec3(0.11, 0.15, 0.005), WHITE);
    drawCube(vec3(0.1, 0.01, -0.125), vec3(0, 0, 0), vec3(0.11, 0.15, 0.005), WHITE);
    drawCube(vec3(-0.315, 0.065, 0), vec3(0, 0, -45), vec3(0.005, 0.1, 0.19), WHITE);

    // Trụ trên và dưới
    drawPlane2(vec3(0, 0.125, 0), vec3(90, 0, 0), vec3(0.35, 0.125, 0.125), vec4(0.91, 0.36, 0.39, 1));
    drawCylinder(vec3(0, 0.2, 0), vec3(0, 0, 0), vec3(0.035, 0.1, 0.035), bodyColor);
    drawCylinder(vec3(0, 0.25, 0), vec3(0, 0, 0), vec3(0.1, 0.025, 0.1), bodyColor);

    // Đuôi trực thăng
    drawPlane2(vec3(0.5, -0.025, 0), vec3(0, -90, 0), vec3(.075, 0.075, 0.5), bodyColor);
    drawCube(vec3(0.6, -0.035, 0), vec3(0, 0, 0), vec3(0.075, 0.005, 0.25), bodyColor);
    drawPlane(vec3(0.75, 0.035, 0), vec3(-90, 200, 0), vec3(0.1, 0.035, 0.15), bodyColor);
    drawPlane(vec3(0.75, -0.0625, 0), vec3(90, -160, 0), vec3(0.1, 0.035, 0.15), bodyColor);

    // Chân đáp
    drawCylinder(vec3(0.1, -0.15, 0.075), vec3(0, 0, 0), vec3(0.025, 0.15, 0.025), WHITE);
    drawCylinder(vec3(-0.1, -0.15, 0.075), vec3(0, 0, 0), vec3(0.025, 0.15, 0.025), WHITE);
    drawCube(vec3(0, -0.225, 0.075), vec3(0, 0, 0), vec3(0.35, 0.025, 0.025), vec4(0.91, 0.36, 0.39, 1));
    drawPlane2(vec3(-.19, -0.215, 0.075), vec3(90, 60, 0), vec3(0.025, 0.025, 0.05), vec4(0.91, 0.36, 0.39, 1));
    drawCylinder(vec3(0.1, -0.15, -0.075), vec3(0, 0, 0), vec3(0.025, 0.15, 0.025), WHITE);
    drawCylinder(vec3(-0.1, -0.15, -0.075), vec3(0, 0, 0), vec3(0.025, 0.15, 0.025), WHITE);
    drawCube(vec3(0, -0.225, -0.075), vec3(0, 0, 0), vec3(0.35, 0.025, 0.025), vec4(0.91, 0.36, 0.39, 1));
    drawPlane2(vec3(-.19, -0.215, -0.075), vec3(90, 60, 0), vec3(0.025, 0.025, 0.05), vec4(0.91, 0.36, 0.39, 1));

    mat4 currentModelMatrix = cubeTransformMatrix(globalTransformMatrix * Angel::RotateY(airPlaneOfDuyen_rotate.y));
    // Cánh quạt
    drawCube(vec3(0, 0.25, 0), vec3(0, 0, 0), vec3(1, 0.01, 0.0625), WHITE);
    drawCube(vec3(0, 0.25, 0), vec3(0, 90, 0), vec3(1, 0.01, 0.0625), WHITE);
}

void airplaneOfDuyenKeyboard(unsigned char key, int mouseX, int mouseY)
{
    switch (key)
    {
    case 'x':
        airPlaneOfDuyen_rotate.y -= 5;
        break;
    case 'X':
        airPlaneOfDuyen_rotate.y -= 5;
        break;
    default:
        break;
    }
}