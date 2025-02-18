#pragma once

#include "core/openGL.h"

void initPlane();

void drawPlane(vec3 position, vec3 rotation, vec3 scale, color color);

mat4 planeTransformMatrix(mat4 matrix);

mat4 planeTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void planeReset();
