#pragma warning(disable : 4244)		//disable truncated double to float (currently we dont care about performace :D )

//include core engine

#include <core/openGL.h>		// open gl and utilities
#include <core/camera.h>		// camera
#include <core/shaders.h>		// shaders
#include <core/environment.h>	// environment
#include <core/lighting.h>		// lighting
#include <core/ui.h>			// user interface

//include objects
#include <objects/cube.h>		
#include <objects/plane.h>
#include <objects/plane2.h>
#include <objects/cylinder.h>		
#include <objects/sphere.h>

//air planes
#include "objects/airplane.h"
#include "objects/airplaneOfTien.h"	
#include "objects/airplaneOfDuyen.h"
#include "objects/biplane.h"

//scene objects
#include "objects/shelf.h"	
#include "objects/computer.h"	
#include "objects/cabinet.h"	
#include "objects/table.h"	
#include "objects/lamp.h"
#include "objects/chair.h"
#include "objects/chair1.h"
#include "objects/sign.h"

using namespace engine;
using namespace std;

ui::button btnDay;
ui::button btnNight;
ui::button btnSunset;
ui::button btnAxes;
bool enableAxes = true;

void toggleAxes()
{
	enableAxes = !enableAxes;
}

//DAY TIME PROTOTYPE FUNCS
void day();

void night();

void sunset();


bool leftMouseButtonDown = false;
int lastMouseX, lastMouseY;

const char* defaultSelectedInfo = ">> None (Press to select) ";
const char* selectedInfo = defaultSelectedInfo;
int selectedIndex = -1;

void onGUI()
{
	glColor3f(1.0, 1.0, 1.0);

	ui::text2D("Render Engine", 10, 10, ui::window_height - 20, color(1, 1, 0, 1));

	ui::text2D("middle mouse - zoom in/out", 14, 10, ui::window_height - 50);
	ui::text2D("left mouse - rotate camera", 14, 10, ui::window_height - 70);

	//ui::text2D("s - move right", 10, 10, ui::window_height - 60);
	//ui::text2D("d - move right", 10, 10, ui::window_height - 70);
	//ui::text2D("w - move right", 10, 10, ui::window_height - 80);

	btnAxes = ui::button2D("Axes", 14, 80, 40, ui::window_width - 90, ui::window_height - 50, color(1, 1, 0, 1), color(0, 0, 0, 1));
	btnDay = ui::button2D("Day", 14, 80, 40, ui::window_width - 90, ui::window_height - 100, color(.9f, .9f, .9f, 1), color(0, 0, 0, 1));
	btnNight = ui::button2D("Night", 14, 80, 40, ui::window_width - 90, ui::window_height - 150, color(.1f, .1f, .1f, 1), color(1, 1, 1, 1));
	btnSunset = ui::button2D("Sunset", 14, 80, 40, ui::window_width - 90, ui::window_height - 200, color(.1f, .1f, .1f, 1), color(1, 1, 1, 1));
	btnAxes.onClick = toggleAxes;
	btnDay.onClick = day;
	btnNight.onClick = night;
	btnSunset.onClick = sunset;

	ui::text2D(selectedInfo, 14, 10, ui::window_height - 100);
	ui::text2D("1 - airplane", 14, 15, ui::window_height - 120);
	ui::text2D("2 - biplane", 14, 15, ui::window_height - 140);
	ui::text2D("3", 14, 15, ui::window_height - 160);
	ui::text2D("4", 14, 15, ui::window_height - 180);
	ui::text2D("5", 14, 15, ui::window_height - 200);
	ui::text2D("6 - None", 14, 15, ui::window_height - 220);
}

//LIGHTING

directionalLight* sun_light;
pointLight* lamp_light_1;
pointLight* lamp_light_2;

void setupLights()
{
	sun_light = oneDirectionalLight(vec3(1, 10, 2), vec3(-.5, -1, -.5));
	sun_light->ambient =
		sun_light->diffuse =
		sun_light->specular = color3(.15f, .15f, .15f);

	lamp_light_1 = addPointLight(vec3());
	lamp_light_1->ambient = color3(1, 1, 1);
	lamp_light_1->diffuse =
		lamp_light_1->specular = color3(1, 1, 0);

	lamp_light_2 = addPointLight(vec3());
	lamp_light_2->ambient = color3(1, 1, 1);
	lamp_light_2->diffuse =
		lamp_light_2->specular = color3(0, 1, 1);
}

void day()
{
	sun_light->ambient =
	sun_light->diffuse =
	sun_light->specular = color3(.9f, .9f, .9f);
}

void night()
{
	sun_light->ambient =
	sun_light->diffuse =
	sun_light->specular = color3(.1f, .1f, .1f);
}

void sunset()
{
	sun_light->ambient = color3(1, 1, 1);
	sun_light->diffuse = 
	sun_light->specular = color3(.8f, .2f, .0f);
}

void setUpCam()
{
	int mX = 0;
	int mY = 0;
	for (int i = 0; i < 50; i++)
	{
		lastMouseX = 0;
		lastMouseY = 0;
		cameraMotion(-1, 1, lastMouseX, lastMouseY);
	}

	for(int i = 0; i < 13; i++)
		zoomCamera(-0.1f);
}

void initialize_before_display()
{
	engine::initEnvironment();
	engine::initDefaultShaders();
	setupLights();
	setUpCam();
	initCube();
	initPlane();
	initPlane2();
	initCylinder();
	initSphere();
	initSign();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	if(enableAxes) drawAxes();

	drawLamp(vec3(-2, 2, 0), vec3(), vec3(1, 1, 1), lamp_light_1);

	drawLamp(vec3(2, 2, 0), vec3(), vec3(1, 1, 1), lamp_light_2);

	//drawAirplane(vec3(0, 2, 0), vec3(), vec3(1, 1, 1));
	drawBiplane(vec3(0, 0, 0), vec3(), vec3(.75f, .75f, .75f));

	//drawSign(vec3(0, 1, 0), vec3(0, 0, 0), vec3(3, 1, 1), color(1, 1, 1, 1));

	onGUI();

	glutSwapBuffers();
}


void idle()
{
	glutPostRedisplay();
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(20, timer, value++);
}

void input(unsigned char key, int mouseX, int mouseY)
{
	shelfKeyboard(key, mouseX, mouseY);

	cabinetKeyboard(key, mouseX, mouseY);

	lampKeyboard(key, mouseX, mouseY);

	switch (key)
	{
	case '1':
		selectedInfo = ">> airplane";
		selectedIndex = 1;
		break;
	case '2':
		selectedInfo = ">> biplane";
		selectedIndex = 2;
		break;
	case '3':
		selectedInfo = ">> ";
		selectedIndex = 3;
		break;
	case '4':
		selectedInfo = ">> ";
		selectedIndex = 4;
		break;
	case '5':
		selectedInfo = ">> ";
		selectedIndex = 5;
		break;
	case '6':
		selectedInfo = defaultSelectedInfo;
		selectedIndex = -1;
		break;
	case 27:
		exit(0);
		break;
	}

	switch (selectedIndex)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	default:
		break;
	}

	glutPostRedisplay();
}


void resharp(int w, int h)
{
	setupCamera(w, h, 0.1f, 1000);
	ui::screenChange(w, h);

	glutReshapeWindow(w, h);
	glViewport(0, 0, w, h);
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	btnAxes.onEvent(button, state, x, y);
	btnDay.onEvent(button, state, x, y);
	btnNight.onEvent(button, state, x, y);
	btnSunset.onEvent(button, state, x, y);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		leftMouseButtonDown = true;
		lastMouseX = x;
		lastMouseY = y;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		leftMouseButtonDown = false;
	}
	else if (button == 3) // Scroll up
	{
		zoomCamera(1);
	}
	else if (button == 4) // Scroll down
	{
		zoomCamera(-1);
	}
}

void motion(int x, int y)
{
	if (leftMouseButtonDown)
		cameraMotion(x, y, lastMouseX, lastMouseY);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glEnable(GL_MULTISAMPLE);
	glutInitWindowSize(840, 600);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Render Engine");

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		std::cerr << "GLEW Init Error: " << glewGetErrorString(err) << std::endl;
		return -1;
	}

	glutDisplayFunc(display);
	glutReshapeFunc(resharp);
	glutIdleFunc(idle);
	glutTimerFunc(20, timer, 0);
	glutKeyboardFunc(input);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);



	initialize_before_display();


	glutMainLoop();

	disposeLights();

	return 0;
}