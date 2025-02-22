#pragma once

#include "core/openGL.h"
#include "core/shaders.h"

void initCube();

//void drawCube();

void drawCube(const vec3& position, const vec3& rotation, const vec3& scale, 
	const color& color,
	engine::shader shader = engine::defaultShader);

mat4 cubeTransformMatrix(mat4 matrix);

mat4 cubeTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void cubeReset();
