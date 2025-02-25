#include "core/camera.h"

using namespace engine;

camera engine::mainCamera;

#pragma region CAMERA LOCAL TRANSFORM

vec3 camera::forward()
{
	vec4 forward4 = (mainCamera.target_position - mainCamera.eye_position);
	return vec3(forward4.x, forward4.y, forward4.z);
}

vec3 camera::up()
{
	vec3 globalCamRight = normalize(cross(mainCamera.up_direction, normalize(CAM_FORWARD)));

	vec3 camUp = normalize(cross(normalize(CAM_FORWARD), globalCamRight));

	return camUp;
}

vec3 camera::right()
{
	vec3 camRight = normalize(cross(CAM_UP, normalize(CAM_FORWARD)));

	return camRight;
}

#pragma endregion


void engine::setupCamera(int window_width, int window_height, float zNear, float zFar)
{
	mainCamera.window_width = window_width;
	mainCamera.window_height = window_height;
	mainCamera.zNear = zNear;
	mainCamera.zFar = zFar;
}

void engine::setCameraPos(const vec4& position)
{
	mainCamera.eye_position = position;
}

void engine::setTargetPos(const vec4& position)
{
	mainCamera.target_position = position;
}

void engine::zoomCamera(float value)
{
	if (value > 0) // Scroll up
	{
		setCameraPos(CAM_POS_4 + CAM_DIR_4 * mainCamera.zoomSpeed);
	}
	else if (value < 0) // Scroll down
	{
		setCameraPos(CAM_POS_4 - CAM_DIR_4 * mainCamera.zoomSpeed);
	}
}

void engine::setZoomSpeed(float speed)
{
	mainCamera.zoomSpeed = speed;
}

void engine::setCameraSpeed(float speed)
{
	mainCamera.motionSpeed = speed;
}

float yawAngle = 0;
float pitchAngle = 0;

/// <summary>
/// Rodrigues
/// </summary>
vec3 rotateAxis(const vec3& position, float angle, const vec3& axis)
{
	vec3 a = normalize(axis);
	float cosTheta = std::cos(angle);
	float sinTheta = std::sin(angle);
	return position * cosTheta + cross(a, position) * sinTheta + a * (dot(a, position) * (1 - cosTheta));
}

void engine::cameraMotion(int mouseX, int mouseY, int& lastMouseX, int& lastMouseY)
{
	int deltaX = mouseX - lastMouseX;
	int deltaY = mouseY - lastMouseY;

	float rotationSpeed = mainCamera.motionSpeed;

	float yaw = deltaX * rotationSpeed;
	float pitch = deltaY * rotationSpeed;
	//float rool = ;

	// HORIZONTAL ROTATION
	if (pitchAngle >= 80 || pitchAngle <= -80)
		yaw *= 0.05f;
	yawAngle += yaw;
	mat4 yawRot = Angel::RotateY(-yaw);
	setCameraPos(yawRot * vec4(CAM_POS_4));

	//VERTICAL ROTATION
	//std::cout << pitch * Deg2Rad << std::endl;
	pitchAngle += pitch;
	if (pitchAngle > 85)
	{
		pitchAngle = 85;
		return;
	}

	if (pitchAngle < -85)
	{
		pitchAngle = -85;
		return;
	}

	vec3 vertical = rotateAxis(CAM_POS_3, pitch * Deg2Rad, CAM_RIGHT);

	//std::cout << pitchAngle << std::endl;
	setCameraPos(vertical);

	//std::cout << CAM_POS_4 << std::endl;
	
	lastMouseX = mouseX;
	lastMouseY = mouseY;
}

void engine::useCameraMatrix(GLuint view_location, GLuint projection_location)
{
	auto camView = LookAt(mainCamera.eye_position, mainCamera.target_position, mainCamera.up_direction);
	glUniformMatrix4fv(view_location, 1, GL_TRUE, camView);

	auto projection = Perspective(60, (float)mainCamera.window_width / mainCamera.window_height, mainCamera.zNear, mainCamera.zFar);
	glUniformMatrix4fv(projection_location, 1, GL_TRUE, projection);
}
