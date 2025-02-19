#include "core/lighting.h"


//LIGHT CLASS
void light::setPosition(vec3 position)
{
	this->lightPos = position;
}

//=======================================\\

light lights = light();

directionalLight dLight = directionalLight();

pointLight pLight = pointLight();

light addLight(const vec3& position, const color3& color)
{
	light l = light();
	l.lightPos = position;
	l.lightColor = color;

	lights = l;

	return l;
}

directionalLight addDirectionalLight(const vec3& position, const vec3& direction, const color3& color)
{
	directionalLight l = directionalLight();
	l.lightPos = position;
	l.lightColor = color;
	l.lightDir = direction;

	dLight = l;

	return l;
}

pointLight addPointLight(const vec3& position, const color3& color)
{
	pointLight l = pointLight();
	l.lightPos = position;
	l.lightColor = color;

	pLight = l;

	return l;
}

void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName, 
	const char* viewPositionName, const vec3& cameraPosition)
{
	//std::cout << lights.lightPos;
	setUniformVec3(shader_program, lightPositionName, pLight.lightPos);
	setUniformVec3(shader_program, lightColorName, pLight.lightColor);

	setUniformVec3(shader_program, viewPositionName, cameraPosition);

	setUniformFloat(shader_program, "constant", &pLight.constant);
	setUniformFloat(shader_program, "linear", &pLight.linear);
	setUniformFloat(shader_program, "quadratic", &pLight.quadratic);
}