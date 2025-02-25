#pragma once

#include "core/openGL.h"

#include "objects/cube.h"

void drawCabinet(vec3 position, vec3 rotation, vec3 scale, bool enableInput = false);

void cabinetKeyboard(unsigned char key, int mouseX, int mouseY);

