#include "objects/testObject.h"
#include "objects/chair.h"

color frameColor = color(0.6, 0.4, 0.2, 1); // Màu khung cửa (màu gỗ)

void drawTestObject(vec3 position, vec3 rotation, vec3 scale)
{

    //mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
    //cubeTransform(position, rotation, scale);
    //// **Thanh dọc**
    //for (int i = 0; i <= 5; i++) {
    //    float zOffset = i * 0.71428;
    //    drawCube(vec3(9.785, 0.5, 0.864 + zOffset), vec3(0, 0, 0), vec3(0.1, 4, 0.1), frameColor);
    //}

    //// **Thanh ngang**
    //for (int i = 0; i <= 3; i++) {
    //    float zOffset = i * 1.428;
    //    drawCube(vec3(9.785, -0.5, 0.507 + zOffset), vec3(0, 0, 0), vec3(0.1, 0.1, 0.714), frameColor);
    //    drawCube(vec3(9.785, 1.5, 0.507 + zOffset), vec3(0, 0, 0), vec3(0.1, 0.1, 0.714), frameColor);
    //}

    //// **Thanh ngang giữa**
    //drawCube(vec3(9.785, 0.5, 1.221), vec3(0, 0, 0), vec3(0.1, 0.1, 0.714), frameColor);
    //drawCube(vec3(9.785, 0.5, 4.078), vec3(0, 0, 0), vec3(0.1, 0.1, 0.714), frameColor);
    color bodyColor = color(0.7, 0.2, 0.2, 1);  // Màu thân máy bay
    color wingColor = color(0.2, 0.2, 0.8, 1);  // Màu cánh máy bay
    color tailColor = color(0.2, 0.8, 0.2, 1);  // Màu đuôi máy bay

    // **1. Thân máy bay**
    drawCube(vec3(0, 0, 0), vec3(0, 0, 0), vec3(2.0, 0.5, 0.5), bodyColor);

    // **2. Cánh máy bay**
    drawCube(vec3(0, 0, 0.5), vec3(0, 0, 0), vec3(3.0, 0.1, 0.2), wingColor);
    drawCube(vec3(0, 0, -0.5), vec3(0, 0, 0), vec3(3.0, 0.1, 0.2), wingColor);

    // **3. Đuôi máy bay**
    drawCube(vec3(-1.0, 0.3, 0), vec3(0, 0, 0), vec3(0.5, 0.8, 0.1), tailColor);


}