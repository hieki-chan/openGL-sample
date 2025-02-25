#include "objects/biplane.h"

vec3 biplane_rotate;

color biplane_wingColor = color(1, 1, 1, 1);

void biplaneWing(float y, float z);

void drawPillar(float x);

void drawFontGear(float x, float rot, color gColor = color(.38f, .38f, .38f, 1));

float properller_rotation = 0;

void drawBiplane(vec3 position, vec3 rotation, vec3 scale, bool enableInput)
{
	if (enableInput)
		rotation += biplane_rotate;

	mat4 globalTransform = cylinderTransform(position, rotation, scale);
	cubeTransform(position, rotation, scale);
	plane2Transform(position, rotation, scale);
	sphereTransform(position, rotation, scale);

	//body
	float bSize = 1.75f;
	drawCylinder(vec3(), vec3(90, 0, 0), vec3(bSize, 4, bSize), color(1, 0, 0, 1));
	drawSphere(vec3(0, 0.5f, -.75f), vec3(0, 0, 0), vec3(1.2f, 1.2f, 2), color(0, 0, 0, 1));
	drawCylinder(vec3(0, 0, -2.5f), vec3(90, 0, 0), vec3(bSize - .15f, 1, bSize - .15f), color(1, 0, 0, 1));
	drawCylinder(vec3(0, 0, -3.5f), vec3(90, 0, 0), vec3(bSize - .25f, 1, bSize - .25f), color(1, 0, 0, 1));
	drawCylinder(vec3(0, 0, -2.0f), vec3(90, 0, 0), vec3(bSize + .05f, .1f, bSize + .05f), color(0, 0, 0, 1));
	drawCylinder(vec3(0, 0, -3.05f), vec3(90, 0, 0), vec3(bSize -.2f + .05f, .1f, bSize -.2f + .05f), color(0, 0, 0, 1));

	//tail
	drawPlane2(vec3((.9f), .5f, -3.5f), vec3(0, -90, 0), vec3(1.0f, .075f, 1.75f), biplane_wingColor);
	drawPlane2(vec3(-(.9f), .5f, -3.5f), vec3(0, 90, 0), vec3(1.0f, .075f, 1.75f), biplane_wingColor);
	drawPlane2(vec3(0, .65f, -3.5f), vec3(90, 0, 90), vec3(1.0f, .5f, 1.75f), color(1, 0, 0, 1));
	// >> back gears
	color gColor = color(.38f, .38f, .38f, 1);
	drawCylinder(vec3(0, -.75f, -3.5f), vec3(0, 0, 90), vec3(.2f, 1.5f, .2f), gColor);
	drawCylinder(vec3(-.75f, -.75f, -3.5f), vec3(0, 0, 90), vec3(.5f, .2f, .5f), gColor);
	drawCylinder(vec3(.75f, -.75f, -3.5f), vec3(0, 0, 90), vec3(.5f, .2f, .5f), gColor);

	// >> font gears
	drawFontGear(1.0f, 60);
	drawFontGear(-1.0f, -60);

	//head
	drawCylinder(vec3(0, 0, 2 + .25f / 2), vec3(90, 0, 0), vec3(bSize, .25f, bSize), color(0, 0, 0, 1));
	
	//properller
	properller_rotation += 4;
	cylinderTransformMatrix(globalTransform * RotateZ(properller_rotation));
	color pColor = color(155, 149, 227, 255) / 255.0f;
	drawSphere(vec3(0, 0, 2.3f), vec3(0, 0, 0), vec3(.5f, .5f, .5f), pColor);
	drawCylinder(vec3(0.9f, 0, 2.35f), vec3(90, 0, 90), vec3(.15f, 1.5f, .25f), pColor);
	drawCylinder(vec3(-0.9f, 0, 2.35f), vec3(90, 0, 90), vec3(.15f, 1.5f, .25f), pColor);
	cylinderTransformMatrix(globalTransform);	//restore

	//lights
	color lColor = color(1, 1, 0, 1);
	drawCube(vec3(-.8f, .5f, 2.0f), vec3(0, 0, 0), vec3(.25f, .25f, .25f), lColor, engine::emissionShader);
	drawCube(vec3(+.8f, .5f, 2.0f), vec3(0, 0, 0), vec3(.25f, .25f, .25f), lColor, engine::emissionShader);


	//wings
	biplaneWing(1.25f, 0);
	biplaneWing(-.75f, 0);
	drawPillar(3.4f);
	drawPillar(-3.4f);
	

	cylinderReset();
	sphereReset();
	plane2Reset();
	cubeReset();
}

void biplaneWing(float y, float z)
{
	float wingX = 7;
	drawCube(vec3(0, y, z), vec3(0, 0, 0), vec3(wingX, .1f, 1.4f), biplane_wingColor);
	drawPlane2(vec3((wingX / 2 + 1.4f / 4 - 0.1f), y, z), vec3(0, -90, 0), vec3(1.4f, .1f, .5f), biplane_wingColor);
	drawPlane2(vec3(-(wingX / 2 + 1.4f / 4 - 0.1f), y, z), vec3(0, 90, 0), vec3(1.4f, .1f, .5f), biplane_wingColor);
}

void drawPillar(float x)
{
	color pillarColor = color(0, 0, 0, 1);
	drawCylinder(vec3(x, .25f, -.4f), vec3(0, 0, 0), vec3(.1f, 2.0f, .1f), pillarColor);
	drawCylinder(vec3(x, .25f, +.4f), vec3(0, 0, 0), vec3(.1f, 2.0f, .1f), pillarColor);
	drawCylinder(vec3(x, .25f, 0), vec3(25, 0, 0), vec3(.1f, 2.25f, .1f), pillarColor);
}

void drawFontGear(float x, float rot, color gColor)
{
	drawCylinder(vec3(x - .5f * (x > 0 ? 1 : -1), -.5f, 1.15f), vec3(0, 0, rot), vec3(.2f, 1.0f, .2f), gColor);
	drawPlane2(vec3(x, -.75f, 1.15f), vec3(90, 0, 90), vec3(0.85f, .3f, .3f), color(1, 0, 0, 1));
	drawCylinder(vec3(x, -1.0f, 1.15f), vec3(0, 0, 90), vec3(.75f, .25f, .75f), gColor);
}

void biplaneKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 'q':
		biplane_rotate.y += 5;
		break;
	case 'e':
		biplane_rotate.y -= 5;
		break;
	default:
		break;
	}
}