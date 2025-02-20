#include "objects/chair.h"

void drawChair(vec3 position, vec3 rotation, vec3 scale)
{

	mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);
	cubeTransform(position, rotation, scale);

	color woodColor = color(0.7, 0.5, 0.3, 1); // Màu gỗ tự nhiên
	color cushionColor = color(0.3, 0.2, 0.2, 1); // Màu đệm ghế

	// **1. Mặt ghế cong nhẹ & có đệm dày hơn**
	drawCylinder(vec3(0, 0.55, 0), vec3(0, 0, 0), vec3(0.6, 0.05, 0.6), woodColor); // Gỗ dày hơn
	drawCylinder(vec3(0, 0.6, 0), vec3(0, 0, 0), vec3(0.7, 0.03, 0.7), cushionColor); // Đệm êm hơn
	drawCube(vec3(0, 0.55, 0), vec3(0, 0, 0), vec3(0.8, 0.06, 0.8), woodColor); // Mặt ghế gỗ (hình hộp)


	// **2. Chân ghế trụ tròn**
	float legOffset = 0.38;
	drawCylinder(vec3(legOffset, 0.3, legOffset), vec3(0, 0, 0), vec3(0.06, 0.6, 0.06), woodColor);
	drawCylinder(vec3(-legOffset, 0.3, legOffset), vec3(0, 0, 0), vec3(0.06, 0.6, 0.06), woodColor);
	drawCylinder(vec3(legOffset, 0.3, -legOffset), vec3(0, 0, 0), vec3(0.06, 0.6, 0.06), woodColor);
	drawCylinder(vec3(-legOffset, 0.3, -legOffset), vec3(0, 0, 0), vec3(0.06, 0.6, 0.06), woodColor);

	// **3. Thanh ngang nối chân ghế**
	drawCube(vec3(0, 0.2, legOffset), vec3(0, 0, 0), vec3(0.75, 0.04, 0.06), woodColor);
	drawCube(vec3(0, 0.2, -legOffset), vec3(0, 0, 0), vec3(0.75, 0.04, 0.06), woodColor);
	drawCube(vec3(legOffset, 0.2, 0), vec3(0, 0, 0), vec3(0.06, 0.04, 0.75), woodColor);
	drawCube(vec3(-legOffset, 0.2, 0), vec3(0, 0, 0), vec3(0.06, 0.04, 0.75), woodColor);

	// **4. Tựa lưng cao & bo viền cong**
	float backHeight = 1.2;
	drawCube(vec3(0, 1.0, -0.4), vec3(0, 0, 0), vec3(0.55, 0.06, 0.06), woodColor); // Thanh ngang trên
	drawCube(vec3(0, 0.8, -0.4), vec3(0, 0, 0), vec3(0.55, 0.06, 0.06), woodColor); // Thanh ngang giữa

	// **5. Thanh dọc tựa lưng cao**
	for (int i = -2; i <= 2; i++) {
		float x = i * 0.13;
		drawCube(vec3(x, 0.9, -0.4), vec3(0, 0, 0), vec3(0.06, backHeight, 0.06), woodColor);
	}

	// **6. Chân sau kéo dài làm tựa lưng chắc chắn**
	drawCylinder(vec3(-legOffset, 0.85, -0.4), vec3(0, 0, 0), vec3(0.06, 1.1, 0.06), woodColor);
	drawCylinder(vec3(legOffset, 0.85, -0.4), vec3(0, 0, 0), vec3(0.06, 1.1, 0.06), woodColor);

}

