#pragma once


#include "core/openGL.h"

void initCylinder();

void drawCylinder(vec3 position, vec3 rotation, vec3 scale, color color);

mat4 cylinderTransformMatrix(mat4 matrix);

mat4 cylinderTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void cylinderReset();
