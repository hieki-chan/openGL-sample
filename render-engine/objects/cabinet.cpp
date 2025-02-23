#include "objects/cabinet.h"

//dung cho input
vec3 cabinet_position;
vec3 cabinetLeft_position;
vec3 cabinetRight_position;

void drawCabinet(vec3 position, vec3 rotation, vec3 scale)
{
	color color1 = color(.8, .8, .8, 1);
	color color2 = color(.5, .5, .5, 1);
	//ap dung pos, rot, scale cho cube, tra ve global model matrix
	position += cabinet_position;	//cong them cube input
	mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

	drawCube(vec3(), vec3(), vec3(1.2, .05, .5), color1);

	drawCube(vec3(0, -.4, 0), vec3(), vec3(1.2, .05, .5), color1);

	drawCube(vec3(0, -.2, -.21), vec3(), vec3(1.1, .4, .05), color1);
	drawCube(vec3(0, -.2, 0), vec3(), vec3(.05, .4, .4), color1);
	drawCube(vec3(.56, -.2, .01), vec3(), vec3(.05, .4, .42), color1);
	drawCube(vec3(-.56, -.2, .01), vec3(), vec3(.05, .4, .42), color1);

	drawCube(vec3(0, .5, 0), vec3(), vec3(1.1, .05, .4), color2);
	drawCube(vec3(0, 1, 0), vec3(), vec3(1.1, .05, .4), color2);
	drawCube(vec3(0, 1.5, 0), vec3(), vec3(1.1, .05, .4), color2);
	drawCube(vec3(0, .8, -.21), vec3(), vec3(1.16, 1.6, .05), color1);
	drawCube(vec3(0, .75, 0), vec3(), vec3(.05, 1.5, .45), color1);
	drawCube(vec3(-.56, .8, .01), vec3(), vec3(.04, 1.6, .42), color1);
	drawCube(vec3(.56, .8, .01), vec3(), vec3(.04, 1.6, .42), color1);

	//mo hinh phan cap, goi ham nay de thay doi transform cho nhung cube sau
	//tra ve current model matrix
	mat4 currentModelMatrix = cubeTransformMatrix(globalTransformMatrix * Angel::Translate(cabinetLeft_position));
	drawCube(vec3(-.278, -.35, 0), vec3(), vec3(.45, .025, .35), color2);
	drawCube(vec3(-.278, -.238, -.1635), vec3(), vec3(.45, .2, .025), color2);
	drawCube(vec3(-.48, -.238, 0), vec3(), vec3(.025, .2, .35), color2);
	drawCube(vec3(-.075, -.238, 0), vec3(), vec3(.025, .2, .35), color2);
	drawCube(vec3(-.278, -.2, .18), vec3(), vec3(.5, .34, .04), color1);
	drawCube(vec3(-.278, -.15, .2), vec3(), vec3(.08, .035, .04), color2);

	//mo hinh phan cap, goi ham nay de thay doi transform cho nhung cube sau
	//tra ve current model matrix
	currentModelMatrix = cubeTransformMatrix(globalTransformMatrix * Angel::Translate(cabinetRight_position));
	drawCube(vec3(.278, -.35, 0), vec3(), vec3(.45, .025, .35), color2);
	drawCube(vec3(.278, -.238, -.1635), vec3(), vec3(.45, .2, .025), color2);
	drawCube(vec3(.48, -.238, 0), vec3(), vec3(.025, .2, .35), color2);
	drawCube(vec3(.075, -.238, 0), vec3(), vec3(.025, .2, .35), color2);
	drawCube(vec3(.278, -.2, .18), vec3(), vec3(.5, .34, .04), color1);
	drawCube(vec3(.278, -.15, .2), vec3(), vec3(.08, .035, .04), color2);

	cubeReset();
}

void cabinetKeyboard(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 't':
		cabinetLeft_position.z -= 0.05f;
		if (cabinetLeft_position.z < 0) cabinetLeft_position.z = 0;
		break;
	case 'T':
		cabinetLeft_position.z += 0.05f;
		if (cabinetLeft_position.z > 0.35) cabinetLeft_position.z = 0.35;
		break;
	case 'p':
		cabinetRight_position.z -= 0.05f;
		if (cabinetRight_position.z < 0) cabinetRight_position.z = 0;
		break;
	case 'P':
		cabinetRight_position.z += 0.05f;
		if (cabinetRight_position.z > 0.35) cabinetRight_position.z = 0.35;
		break;
	default:
		break;
	}
}
