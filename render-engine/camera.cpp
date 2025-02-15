#include "camera.h"

/// <summary>
/// Perspective Camera
/// </summary>
namespace camera
{
	static int window_width;
	static int window_height;

	//Camera coordinate
	static vec4 eye_position = vec4(1, 1, 1, 1);
	static vec4 target_position = vec4(0, 0, 0, 1);
	static vec4 up_direction = vec4(0, 1, 0, 1);

	float zNear = 0.1f;
	float zFar = 1000.0f;
}

void setupCamera(int window_width, int window_height, float zNear, float zFar)
{
	camera::window_height = window_height;
	camera::window_width = window_width;
	camera::zNear = zNear;
	camera::zFar = zFar;
}

void setCameraPos(vec4 position)
{
	camera::eye_position = position;
}

void useCameraMatrix(GLuint view_location, GLuint projection_location)
{
	auto camView = LookAt(camera::eye_position, camera::target_position, camera::up_direction);
	glUniformMatrix4fv(view_location, 1, GL_TRUE, camView);

	//auto projection = Frustum(-3, 3, -3, 3, zN, 1000);

	auto projection = Perspective(60, camera::window_width / camera::window_height, camera::zNear, camera::zFar);

	glUniformMatrix4fv(projection_location, 1, GL_TRUE, projection);
}