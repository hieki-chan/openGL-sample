#pragma once

#include "core/openGL.h"
#include "core/shaders.h"

void initPlane();

void drawPlane(const vec3& position, const vec3& rotation, const vec3& scale,
	const color& mainColor,
	engine::shader shader = engine::defaultShader);

mat4 planeTransformMatrix(mat4 matrix);

mat4 planeTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void planeReset();
