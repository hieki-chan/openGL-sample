#include "core/lighting.h"


//LIGHT CLASS
void light::setPosition(vec3 position)
{
	this->lightPos = position;
}

//=======================================\\

light lights = light();

light addLight(const vec3& position, const color3& color)
{
	light l = light(position, color);

	lights = l;

	return l;
}

void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName, 
	const char* viewPositionName, const vec3& cameraPosition)
{
	//std::cout << lights.lightPos;
	setUniformVec3(shader_program, lightPositionName, lights.lightPos);
	setUniformVec3(shader_program, lightColorName, lights.lightColor);

	setUniformVec3(shader_program, viewPositionName, cameraPosition);
}