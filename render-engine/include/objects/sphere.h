#pragma once
#include "core/openGL.h"

void initSphere();

void drawSphere(vec3 position, vec3 rotation, vec3 scale, color color);

mat4 sphereTransformMatrix(mat4 matrix);

mat4 sphereTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void sphereReset();
