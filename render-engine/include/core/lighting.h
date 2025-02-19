#pragma once
#include "openGL.h"

class light
{
public:
	vec3 lightPos = vec3(5, 10, 5);
	color3 lightColor = color3(1, 1, 1);

	void setPosition(vec3 position);
};

class directionalLight : public light
{
public:
	vec3 lightDir;
};


class pointLight : public light
{
public:
	float constant = 1.0f;
	float linear = 0.09f;
	float quadratic = 0.032f;
};

light addLight(const vec3& position, const color3& color);

directionalLight addDirectionalLight(const vec3& position, const vec3& direction, const color3& color);

pointLight addPointLight(const vec3& position, const color3& color);

void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName,
	const char* viewPositionName, const vec3& cameraPosition);