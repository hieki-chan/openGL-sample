#pragma once

#include "core/openGL.h"
#include "core/shaders.h"

void initCylinder();

void drawCylinder(const vec3& position, const vec3& rotation, const vec3& scale,
	const color& mainColor,
	engine::shader shader = engine::defaultShader);

mat4 cylinderTransformMatrix(mat4 matrix);

mat4 cylinderTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void cylinderReset();
