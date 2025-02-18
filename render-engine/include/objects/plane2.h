#pragma once

#include "core/openGL.h"

void initPlane2();

void drawPlane2(vec3 position, vec3 rotation, vec3 scale, color color);

mat4 plane2TransformMatrix(mat4 matrix);

mat4 plane2Transform(const vec3& position, const vec3& rotation, const vec3& scale);

void plane2Reset();