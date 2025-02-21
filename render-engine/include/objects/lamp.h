#pragma once

#include "core/openGL.h"
#include "core/lighting.h"

#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "plane2.h"
#include "sphere.h"

void drawLamp(vec3 position, vec3 rotation, vec3 scale, pointLight* lamp_light);

void lampKeyboard(unsigned char key, int mouseX, int mouseY);