#include "objects/lamp.h"

void drawLamp(vec3 position, vec3 rotation, vec3 scale)
{
    color metalColor = color(0.8, 0.8, 0.8, 1);  // Kim loại bạc sáng
    color lampColor = color(0.2, 0.2, 0.2, 1);   // Chao đèn màu xám đậm
    color bulbColor = color(1.0, 0.9, 0.6, 1);   // Màu bóng đèn phát sáng nhẹ
    color glowColor = color(1.0, 0.9, 0.6, 0.3); // Ánh sáng bán trong suốt

    mat4 transform = cylinderTransform(position, rotation, scale);
    sphereTransform(position, rotation, scale);
    plane2Transform(position, rotation, scale);
    cubeTransform(position, rotation, scale);

    drawCylinder(vec3(0, 2.5, 0), vec3(0, 0, 0), vec3(0.4, 0.1, 0.4), metalColor);
    drawCylinder(vec3(0, 2.55, 0), vec3(0, 0, 0), vec3(0.45, 0.02, 0.45), color(0.5, 0.5, 0.5, 1));

    drawCylinder(vec3(0, 1.8, 0), vec3(0, 0, 0), vec3(0.05, 1.5, 0.05), metalColor);
    drawSphere(vec3(0, 1.05, 0), vec3(), vec3(0.08, 0.08, 0.08), metalColor); 

    drawCylinder(vec3(0, 0.85, 0), vec3(0, 0, 0), vec3(0.35, 0.4, 0.35), lampColor); 
    drawCylinder(vec3(0, 0.4, 0), vec3(0, 0, 0), vec3(0.38, 0.025, 0.38), color(0.1, 0.1, 0.1, 1)); 

    drawSphere(vec3(0, 0.5, 0), vec3(), vec3(0.2, 0.2, 0.2), bulbColor);

    drawCylinder(vec3(0, 0.52, 0), vec3(90, 0, 0), vec3(0.02, 0.1, 0.02), color(1, 0.8, 0.4, 1)); 
    drawSphere(vec3(0, 0.58, 0), vec3(), vec3(0.03, 0.03, 0.03), color(1, 0.7, 0.3, 1)); 

    drawSphere(vec3(0, 0.5, 0), vec3(), vec3(0.6, 0.6, 0.6), glowColor); 

    drawCube(vec3(0, 1.2, 0), vec3(0, 0, 0), vec3(.4, .1, .4), vec4(0, 0, 0, 1));
    drawPlane2(vec3(0, .8, .41), vec3(60, 0, 0), vec3(1, .1, 1), vec4(0, 0, 0, 1));
    drawPlane2(vec3(0, .8, -.41), vec3(120, 0, 0), vec3(1, .1, 1), vec4(0, 0, 0, 1));
    drawPlane2(vec3(-.41, .8, 0), vec3(90, -30, 90), vec3(1, .1, 1), vec4(0, 0, 0, 1));
    drawPlane2(vec3(.41, .8, 0), vec3(90, 30, 90), vec3(1, .1, 1), vec4(0, 0, 0, 1));

}

