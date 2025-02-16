#pragma once

#include "openGL.h"


/// <summary>
/// Perspective Camera
/// </summary>
struct camera
{
	int window_width;
	int window_height;

	//Camera coordinate
	vec4 eye_position = vec4(0, 0, 1, 1);
	vec4 target_position = vec4(0, 0, 0, 1);
	vec4 up_direction = vec4(0, 1, 0, 1);

	//frustum
	float zNear = 0.1f;
	float zFar = 1000.0f;

	//zoom
	float zoomSpeed = 0.12f;

	//motion speed
	float motionSpeed = 0.5f;
};

extern camera mainCamera;


void setupCamera(int window_width, int window_height, float zNear, float zFar);

void setCameraPos(const vec4& position);

void zoomCamera(float value);

void setZoomSpeed(float speed);

void setCameraSpeed(float speed);

void cameraMotion(int mouseX, int mouseY, int& lastMouseX, int& lastMouseY);

void useCameraMatrix(GLuint view_location, GLuint projection_location);
