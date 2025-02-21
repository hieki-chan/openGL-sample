#include "objects/testObject.h"
#include "objects/chair.h"

void drawLeftDoor() {
    color doorColor = color(0.5, 0.3, 0.2, 1);  // Màu cửa tủ gỗ
    color handleColor = color(1, 0.973, 0.863, 1); // Màu tay cầm

    // **Cánh Trái (rộng hơn vì tủ dài)**
    drawCube(vec3(-3, 0, 4.2), vec3(0, 0, 0), vec3(5.8, 4.2, 0.2), doorColor);

    // **Tay cầm cửa trái**
    drawCube(vec3(-1.7, 0, 4.3), vec3(0, 0, 0), vec3(0.2, 0.4, 0.2), handleColor);
}

void drawRightDoor() {
    color doorColor = color(0.5, 0.3, 0.2, 1);  // Màu cửa tủ gỗ
    color handleColor = color(1, 0.973, 0.863, 1); // Màu tay cầm

    // **Cánh Phải (rộng hơn vì tủ dài)**
    drawCube(vec3(3, 0, 4.2), vec3(0, 0, 0), vec3(5.8, 4.2, 0.2), doorColor);

    // **Tay cầm cửa phải**
    drawCube(vec3(1.7, 0, 4.3), vec3(0, 0, 0), vec3(0.2, 0.4, 0.2), handleColor);
}

void drawTV() {
    color screenColor = color(1, 1, 1, 1);  // Màn hình trắng
    color frameColor = color(0.2, 0.2, 0.2, 1);  // Khung TV xám đậm
    color mountColor = color(0.1, 0.1, 0.1, 1); // Giá đỡ màu đen

    // **Kích thước TV**
    vec3 tvSize = vec3(7, 4.5, 0.2);   // Kích thước màn hình
    vec3 frameSize = vec3(7.2, 4.6, 0.2); // Kích thước khung

    // **Vị trí gắn tường**
    float tvHeight = 7;  // Treo cao hơn
    float wallOffset = -0.15;  // Cách tường một chút để có không gian gắn giá đỡ

    // **1. Màn hình TV**
    drawCube(vec3(0, tvHeight, wallOffset), vec3(0, 0, 0), tvSize, screenColor);

    // **2. Khung TV**
    drawCube(vec3(0, tvHeight, wallOffset - 0.01), vec3(0, 0, 0), frameSize, frameColor);

    // **3. Giá treo tường**
    // Thanh ngang gắn vào tường
    drawCube(vec3(0, tvHeight, -0.3), vec3(0, 0, 0), vec3(6, 0.2, 0.1), mountColor);

    // Hai thanh dọc nối với TV
    drawCube(vec3(-2.5, tvHeight - 1, -0.2), vec3(0, 0, 0), vec3(0.2, 3, 0.1), mountColor);
    drawCube(vec3(2.5, tvHeight - 1, -0.2), vec3(0, 0, 0), vec3(0.2, 3, 0.1), mountColor);
}
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
    drawTV();

    color cabinetColor = color(0.5, 0.3, 0.2, 1);  // Màu tủ gỗ
    color handleColor = color(1, 0.973, 0.863, 1); // Màu tay cầm

    // **1. Mặt sau tủ (Kéo dài từ 9 → 12)**
    drawCube(vec3(0, 0, 0), vec3(0, 0, 0), vec3(12, 4, 0.2), cabinetColor);

    // **2. Các mặt bên**
    drawCube(vec3(5.9, 0, 2.1), vec3(0, 0, 0), vec3(0.2, 4, 4), cabinetColor);  // Bên phải (Dịch sang phải hơn)
    drawCube(vec3(-5.9, 0, 2.1), vec3(0, 0, 0), vec3(0.2, 4, 4), cabinetColor); // Bên trái (Dịch sang trái hơn)
    drawCube(vec3(0, 0, 2.1), vec3(0, 0, 0), vec3(0.2, 4, 4), cabinetColor);    // Ở giữa (Giữ nguyên)

    // **3. Mặt trên và dưới (Kéo dài từ 9 → 12)**
    drawCube(vec3(0, 2, 2), vec3(0, 0, 0), vec3(12, 0.2, 4.2), cabinetColor);  // Trên
    drawCube(vec3(0, -2, 2), vec3(0, 0, 0), vec3(12, 0.2, 4.2), cabinetColor); // Dưới

    // **4. Chân tủ (Dời ra xa do tủ dài hơn)**
    drawCube(vec3(5.75, -2.5, 3.85), vec3(0, 0, 0), vec3(0.5, 1, 0.5), cabinetColor);
    drawCube(vec3(5.75, -2.5, 0.15), vec3(0, 0, 0), vec3(0.5, 1, 0.5), cabinetColor);
    drawCube(vec3(-5.75, -2.5, 0.15), vec3(0, 0, 0), vec3(0.5, 1, 0.5), cabinetColor);
    drawCube(vec3(-5.75, -2.5, 3.85), vec3(0, 0, 0), vec3(0.5, 1, 0.5), cabinetColor);

    // **5. Cửa tủ**
    drawLeftDoor();
    drawRightDoor();
}