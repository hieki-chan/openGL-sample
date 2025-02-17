#pragma once


#include "core/openGL.h"

void initCube();

//void drawCube();

void drawCube(vec3 position, vec3 rotation, vec3 scale, color color);

mat4 cubeTransformMatrix(mat4 matrix);

mat4 cubeTransform(const vec3& position, const vec3& rotation, const vec3& scale);

void cubeReset();
