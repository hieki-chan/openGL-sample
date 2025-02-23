#include "objects/chair1.h"

void drawChair1(vec3 position, vec3 rotation, vec3 scale)
{
    mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    cubeTransform(position, rotation, scale);

    color chairColor = color(0.1, 0.1, 0.1, 1);  // Màu ghế đen
    color metalColor = color(0.5, 0.5, 0.5, 1); // Màu kim loại bạc

    // **1. Chân ghế (trụ chính và chân đế 5 cạnh)**
    drawCylinder(vec3(0, -0.3, 0), vec3(0, 0, 0), vec3(0.1, 0.4, 0.1), metalColor); // Trụ trung tâm
    for (int i = 0; i < 5; i++) {
        float angle = i * (360.0 / 5);
        float x = cos(angle * 3.14159265359 / 180.0) * 0.2;
        float z = sin(angle * 3.14159265359 / 180.0) * 0.2;
        drawCube(vec3(0, -.5, 0), vec3(0, angle, 0), vec3(0.75, 0.05, 0.1), metalColor); // Thanh ngang
    }

    // **2. Mặt ghế**
    drawCube(vec3(0, 0, 0), vec3(0, 0, 0), vec3(0.6, 0.1, 0.6), chairColor);

    // **3. Lưng ghế (hơi cong hỗ trợ cổ)**
    drawCube(vec3(0, 0.6, -0.3), vec3(-10, 0, 0), vec3(0.65, 0.9, 0.1), chairColor);
    drawCube(vec3(0, 1.1, -0.3), vec3(0, 0, 0), vec3(0.4, 0.2, 0.1), chairColor); // Phần hỗ trợ cổ

    // **4. Tay vịn (bo tròn thoải mái)**
    drawCube(vec3(-0.35, 0.2, 0), vec3(0, 0, 0), vec3(0.1, 0.3, 0.5), chairColor);
    drawCube(vec3(0.35, 0.2, 0), vec3(0, 0, 0), vec3(0.1, 0.3, 0.5), chairColor);

    // **5. Trụ đỡ ngồi**
    drawCylinder(vec3(0, -0.15, 0), vec3(0, 0, 0), vec3(0.2, 0.3, 0.2), metalColor);
}

