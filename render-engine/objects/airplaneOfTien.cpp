#include "objects/airplaneOfTien.h"

void drawWingOfTien(color color, mat4 matrix)
{
	plane2TransformMatrix(matrix);

	drawPlane2(vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, .1, 3), color);

	drawPlane2(vec3(0, 0, .5), vec3(0, 0, 0), vec3(.9, .175, .1), vec4(0.91, 0.36, 0.39, 1));
	drawPlane2(vec3(0, 0, 1.45), vec3(0, 0, 0), vec3(1.125, .175, .1), vec4(0.91, 0.36, 0.39, 1));
	drawPlane2(vec3(0, 0, -.5), vec3(0, 0, 0), vec3(.7, .175, .1), vec4(0.91, 0.36, 0.39, 1));
	drawPlane2(vec3(0, 0, -1.49), vec3(0, 0, 0), vec3(.5, .175, .1), color);

	cylinderTransformMatrix(matrix);
	drawCylinder(vec3(0, -0.25, -.25), vec3(0, 0, 90), vec3(.6, .75, .6), color);
	drawCylinder(vec3(0, -0.25, -.25), vec3(0, 0, 90), vec3(.5, 1, .5), vec4(0.91, 0.36, 0.39, 1));
}

void drawAirplaneOfTien(vec3 position, vec3 rotation, vec3 scale)
{
	color bodyColor = WHITE;

	mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);

	plane2Transform(position, rotation, scale);

	//cubeTransform(position, rotation, scale);

	////body
	drawCylinder(vec3(0, 0, 0), vec3(90, 0, 0), vec3(1.5, 3, 1.5), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, -1.7), vec3(90, 0, 0), vec3(1.35, .5, 1.35), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, -2), vec3(90, 0, 0), vec3(1.15, .5, 1.15), color(0.33, 0.27, 0.93, 1));

	//head
	drawCylinder(vec3(0, 0, 1), vec3(90, 0, 0), vec3(1.6, 1.5, 1.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 1.7), vec3(90, 0, 0), vec3(1.4, .5, 1.4), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 2), vec3(90, 0, 0), vec3(1.3, .5, 1.3), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 1.8), vec3(90, 0, 0), vec3(1.6, .1, 1.6), color(0.92, 0.77, 0.59, 1));
	drawCylinder(vec3(0, 0, 2), vec3(0, 0, 0), vec3(1.5, .5, 2.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 2), vec3(0, 0, 25), vec3(1.5, .5, 2.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 2), vec3(0, 0, -25), vec3(1.5, .5, 2.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 2), vec3(0, 0, 60), vec3(1.5, .5, 2.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 2), vec3(0, 0, -60), vec3(1.5, .5, 2.6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(0, 0, 1.7), vec3(0, 0, 90), vec3(1.5, .5, 3.5), color(0.33, 0.27, 0.93, 1));

	// wings
	mat4 wingMatrix = plane2TransformMatrix(globalTransformMatrix * Translate(0, 0.2, 0));
	// >> left
	drawWingOfTien(color(0.33, 0.27, 0.93, 1), wingMatrix * Translate(-2, -.35, .5) * RotateY(90));
	// >> right
	drawWingOfTien(color(0.33, 0.27, 0.93, 1), wingMatrix * Translate(2, -.35, .5) * RotateY(-90));

	drawPlane2(vec3(-1, .5, 1), vec3(0, 0, 0), vec3(1, .1, 1), vec4(0.91, 0.36, 0.39, 1));
	drawCylinder(vec3(-1, 0.5, .5), vec3(0, 0, 90), vec3(.6, .75, .6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(-1, 0.5, .5), vec3(0, 0, 90), vec3(.5, 1, .5), vec4(0.91, 0.36, 0.39, 1));

	drawPlane2(vec3(-1, .5, 3), vec3(0, 180, 0), vec3(1, .1, 1), vec4(0.91, 0.36, 0.39, 1));
	drawCylinder(vec3(-1, 0.5, 3.5), vec3(0, 0, 90), vec3(.6, .75, .6), color(0.33, 0.27, 0.93, 1));
	drawCylinder(vec3(-1, 0.5, 3.5), vec3(0, 0, 90), vec3(.5, 1, .5), vec4(0.91, 0.36, 0.39, 1));

	// tail
	plane2TransformMatrix(globalTransformMatrix);

	drawPlane(vec3(0, 1, -1.5), vec3(90, 0, 90), vec3(1, .1, 1.5), vec4(0.92, 0.77, 0.59, 1));
	drawPlane(vec3(.5, 1, -1.64), vec3(0, -90, 0), vec3(.7, .1, 1), vec4(0.91, 0.36, 0.39, 1));
	drawPlane(vec3(-.5, 1, -1.64), vec3(0, 90, -180), vec3(.7, .1, 1), vec4(0.91, 0.36, 0.39, 1));

	
}

