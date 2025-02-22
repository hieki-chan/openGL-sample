// include file object.h
#include "objects/airplane.h"

void drawWing(color color, mat4 matrix)
{
	plane2TransformMatrix(matrix);

	drawPlane2(vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, .1, 3), color);

	drawPlane2(vec3(0, 0, .5), vec3(0, 0, 0), vec3(.9, .175, .1), color);
	drawPlane2(vec3(0, 0, 1.45), vec3(0, 0, 0), vec3(1.125, .175, .1), color);
	drawPlane2(vec3(0, 0, -.5), vec3(0, 0, 0), vec3(.7, .175, .1), color);
	drawPlane2(vec3(0, 0, -1.49), vec3(0, 0, 0), vec3(.5, .175, .1), color);

	cylinderTransformMatrix(matrix);
	drawCylinder(vec3(0, -0.25, -.25), vec3(0, 0, 90), vec3(.6, .75, .6), color);
	drawCylinder(vec3(0, -0.25, -.25), vec3(0, 0, 90), vec3(.5, 1, .5), color);
}

void drawAirplane(vec3 position, vec3 rotation, vec3 scale)
{
	color bodyColor = WHITE;

	mat4 globalTransformMatrix = cylinderTransform(position, rotation, scale);

	plane2Transform(position, rotation, scale);

	//cubeTransform(position, rotation, scale);

	//body
	drawCylinder(vec3(0, 0, 0), vec3(90, 0, 0), vec3(1, 4, 1), bodyColor);
	drawCylinder(vec3(0, 0, 1), vec3(90, 0, 0), vec3(1.1, .1, 1.1), bodyColor);
	drawCylinder(vec3(0, 0, -1), vec3(90, 0, 0), vec3(1.1, .1, 1.1), bodyColor);
	drawCylinder(vec3(0, 0, 2), vec3(90, 0, 0), vec3(.95, 1, .95), bodyColor);
	drawCylinder(vec3(0, 0, -2), vec3(90, 0, 0), vec3(.95, 1, .95), bodyColor);

	// wings
	mat4 wingMatrix = plane2TransformMatrix(globalTransformMatrix * Translate(0, 0.2, 0));
	// >> left
	drawWing(bodyColor, wingMatrix * Translate(-2, 0, 0) * RotateY(90));
	// >> right
	drawWing(bodyColor, wingMatrix * Translate(2, 0, 0) * RotateY(-90));

	// tail
	plane2TransformMatrix(globalTransformMatrix);

	drawPlane2(vec3(0, 1, -2), vec3(90, 0, 90), vec3(1, .1, 1), bodyColor);
	drawPlane2(vec3(1, 0, -2), vec3(0, -90, 0), vec3(1, .1, 1), bodyColor);
	drawPlane2(vec3(-1, 0, -2), vec3(0, 90, 0), vec3(1, .1, 1), bodyColor);

	//head
	drawPlane2(vec3(0, 0, 2.8), vec3(180, 0, 90), vec3(.75, .75, .75), bodyColor);

	// gear

	drawCube(vec3(2, 2, 4), vec3(0, 0, 0), vec3(2, 10, 2), bodyColor);
	drawCube(vec3(-2, 2, 4), vec3(0, 0, 0), vec3(2, 10, 2), bodyColor);
}

