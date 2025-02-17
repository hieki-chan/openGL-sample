#pragma once
#include "openGL.h"

class light
{
public:
	vec3 lightPos;
	color3 lightColor;

public:
	light(const vec3& position, const color3& color) : lightPos(position), lightColor(color)
	{

	}

	light()
	{
		lightPos = vec3(5, 10, 5);
		lightColor = color3(1, 1, 1);
	}

	void setPosition(vec3 position);
};

light addLight(const vec3& position, const color3& color);

void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName,
	const char* viewPositionName, const vec3& cameraPosition);