#pragma once

#include "core/openGL.h"
#include "core/shaders.h"

void initPlane2();

void drawPlane2(const vec3& position, const vec3& rotation, const vec3& scale,
	const color& mainColor,
	engine::shader shader = engine::defaultShader);

mat4 plane2TransformMatrix(mat4 matrix);

mat4 plane2Transform(const vec3& position, const vec3& rotation, const vec3& scale);

void plane2Reset();