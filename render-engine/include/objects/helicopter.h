#pragma once

#include "core/openGL.h"

#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "plane2.h"

void drawHelicopter(vec3 position, vec3 rotation, vec3 scale, bool colorPlane, bool enableInput = false);

void helicopterKeyboard(unsigned char key, int mouseX, int mouseY);
