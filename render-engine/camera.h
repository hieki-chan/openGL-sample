#pragma once

#include "openGL.h"

void setupCamera(int window_width, int window_height, float zNear, float zFar);

void setCameraPos(vec4 position);

void useCameraMatrix(GLuint view_location, GLuint projection_location);
