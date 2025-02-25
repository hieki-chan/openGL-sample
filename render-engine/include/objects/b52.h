#pragma once
#include "core/openGL.h"

#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "plane2.h"
#include "sphere.h"

void drawB52(vec3 position, vec3 rotation, vec3 scale, bool enableInput = false);

void b52Keyboard(unsigned char key, int mouseX, int mouseY);
