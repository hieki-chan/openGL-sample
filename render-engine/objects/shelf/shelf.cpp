#include "objects/shelf.h"

void drawShelf(vec3 position, vec3 rotation, vec3 scale)
{
	//ap dung pos, rot, scale cho cube, tra ve global model matrix
	mat4 globalTransformMatrix = cubeTransform(position, rotation, scale);

	drawCube(vec3(), vec3(), vec3(1, 1, 1), color(1, 1, 1, 1));

	
	//mo hinh phan cap, goi ham nay de thay doi transform cho nhung cube sau
	//tra ve current model matrix
	mat4 currentModelMatrix = cubeTransformMatrix(globalTransformMatrix * Angel::Scale(2) * Angel::RotateY(100));

	drawCube(vec3(1, 1, 1), vec3(), vec3(.2, .2, 3), color(1, 1, 1, 1));

	//cube sau la con cua cube truoc (3cap) nen lay current model matrix
	mat4 childModelMatrix = cubeTransformMatrix(currentModelMatrix * Angel::RotateY(50));

	drawCube(vec3(1, 0, 1), vec3(), vec3(1, 1, 3), color(1, 1, 1, 1));

	//tro ve cap 2
	//cubeTransformMatrix(currentModelMatrix);
	// tro ve cap 1
	//cubeTransformMatrix(globalTransformMatrix);

	//reset cube neu ko se bi loi khi draw nhieu objects khac
	cubeReset();
}
