#pragma once
#include "core/openGL.h"
#include "core/shaders.h"

void initSphere();

void drawSphere(const vec3& position, const vec3& rotation, const vec3& scale, 
	const color& mainColor,
	engine::shader shader = engine::defaultShader);

mat4 sphereTransformMatrix(mat4 matrix);

mat4 sphereTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void sphereReset();
