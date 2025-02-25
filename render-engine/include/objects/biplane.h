#pragma once
#include "core/openGL.h"

#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "plane2.h"
#include "sphere.h"

void drawBiplane(vec3 position, vec3 rotation, vec3 scale, bool enableInput = false);

void biplaneKeyboard(unsigned char key, int mouseX, int mouseY);
