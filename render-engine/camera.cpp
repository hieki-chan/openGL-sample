#include "camera.h"

camera mainCamera;

void setupCamera(int window_width, int window_height, float zNear, float zFar)
{
    mainCamera.window_width = window_width;
    mainCamera.window_height = window_height;
    mainCamera.zNear = zNear;
    mainCamera.zFar = zFar;
}

void setCameraPos(vec4 position)
{
    mainCamera.eye_position = position;
}

void zoomCamera(float value)
{
    if (value > 0) // Scroll up
    {
        setCameraPos(CAMERA_POS + CAMERA_DIR * mainCamera.zoomSpeed);
    }
    else if (value < 0) // Scroll down
    {
        setCameraPos(CAMERA_POS - CAMERA_DIR * mainCamera.zoomSpeed);
    }
}

void setZoomSpeed(float speed)
{
    mainCamera.zoomSpeed = speed;
}

void setCameraSpeed(float speed)
{
	mainCamera.motionSpeed = speed;
}

float currentAngle = 0;
float camV = 0;

void cameraMotion(int mouseX, int mouseY, int& lastMouseX, int& lastMouseY)
{
	int deltaX = mouseX - lastMouseX;
	int deltaY = mouseY - lastMouseY;

	
	float rotationSpeed = mainCamera.motionSpeed;

	float yaw = deltaX * rotationSpeed;

	float rotV = deltaY * rotationSpeed;

	
	vec2 camXZ = vec2(CAMERA_POS.x, CAMERA_POS.z);

	vec4 direction = vec4(mainCamera.target_position) - vec3(camXZ.x, 0, camXZ.y);;
	vec4 camUp = mainCamera.up_direction;
	vec3 camRight = normalize(cross(mainCamera.up_direction, CAMERA_DIR));

	vec4 camForward = normalize(direction);

	float radius = length(direction);

	//float currentAngle = atan2(ndirection.z, ndirection.x);

	currentAngle = currentAngle + Deg2Rad * yaw;


	//std::cout << "radius" << radius<<"\n";
	//std::cout << "newange" << currentAngle <<"\n";

	vec4 n1 = mainCamera.eye_position - mainCamera.target_position;
	n1.w = 0;
	vec4 n = normalize(n1);
	vec4 u = normalize(vec4(cross(mainCamera.up_direction, n), 0));
	vec4 v = normalize(vec4(cross(n, u), 0));


	vec4 pos = mainCamera.eye_position + (normalize(v) + normalize(n)) * rotV * 0.5f;


	setCameraPos(pos);
	//setCameraPos(vec3(radius * cos(currentAngle), mainCamera.eye_position.y, radius * sin(currentAngle)));

	lastMouseX = mouseX;
	lastMouseY = mouseY;
}

void useCameraMatrix(GLuint view_location, GLuint projection_location)
{
    auto camView = LookAt(mainCamera.eye_position, mainCamera.target_position, mainCamera.up_direction);
    glUniformMatrix4fv(view_location, 1, GL_TRUE, camView);

    auto projection = Perspective(60, (float)mainCamera.window_width / mainCamera.window_height, mainCamera.zNear, mainCamera.zFar);
    glUniformMatrix4fv(projection_location, 1, GL_TRUE, projection);
}
