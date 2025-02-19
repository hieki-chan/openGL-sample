#pragma warning(disable : 4244)		//disable truncated double to float (currently we dont care about performace :D )

//include core engine

#include "core/openGL.h"		// open gl and utilities
#include "core/camera.h"		// camera
#include "core/environment.h"	// environment
#include "core/lighting.h"		// lighting
#include "core/ui.h"			// user interface

 //include objects

#include "objects/cube.h"		
#include "objects/plane.h"
#include "objects/plane2.h"
#include "objects/cylinder.h"		
#include "objects/sphere.h"		
#include "objects/shelf.h"	
#include "objects/computer.h"	
#include "objects/cabinet.h"	
#include "objects/table.h"	
#include "objects/airplaneOfTien.h"	

#include "objects/airplane.h"


ui::button btnAxes;
bool enableAxes = true;

void toggleAxes()
{
	enableAxes = !enableAxes;
}

void onGUI()
{
	glColor3f(1.0, 1.0, 1.0);

	ui::text2D("Render Engine", 10, 10, ui::window_height - 20, color(1, 1, 0, 1));

	ui::text2D("middle mouse - zoom in/out", 14, 10, ui::window_height - 50);
	ui::text2D("left mouse - rotate camera", 14, 10, ui::window_height - 70);

	//ui::renderText2D("s - move right", 10, 10, ui::window_height - 60);
	//ui::renderText2D("d - move right", 10, 10, ui::window_height - 70);
	//ui::renderText2D("w - move right", 10, 10, ui::window_height - 80);

	btnAxes = ui::button2D("Axes", 14, 80, 40, ui::window_width - 90, ui::window_height - 50, color(1, 1, 0, 1), color(0, 0, 0, 1));
	btnAxes.callback = toggleAxes;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);


	if(enableAxes) drawAxes();

	//drawShelf(vec3(1, 1, 1), vec3(0, 90, 0), vec3(1, .5f, 1));

	//drawPlane(vec3(2, 0, 0), vec3(0, 0, 0), vec3(1.25f, 0.25f, 2), color(0, 1, 1, 1));

	//drawPlane2(vec3(4, 0, 0), vec3(0, 0, 0), vec3(1.25f, 0.25f, 2), color(0, 0.2, 1, 1));

	//drawCylinder(vec3(), vec3(), vec3(1, 1, 1), color(1, 0, 0, 1));

	//drawAirplane(vec3(0, 5, 0), vec3(), vec3(.5, .5, .5));

	//drawCabinet(vec3(), vec3(), vec3(1, 1, 1));

	//drawTable(vec3(), vec3(), vec3(1, 1, 1));

	//drawComputer(vec3(), vec3(), vec3(1, 1, 1));

	//drawCylinder(vec3(), vec3(), vec3(1, .1, 1), WHITE);
	
	//drawAirplaneOfTien(vec3(0, 2, 1), vec3(), vec3(1, 1, 1));

	drawSphere(vec3(0, 0, 1), vec3(), vec3(1, 1, 1), WHITE);

	drawSphere(vec3(4, -2, 1), vec3(), vec3(1, 1, 1), WHITE);

	drawSphere(vec3(-2, 2, 5), vec3(), vec3(1, 1, 1), WHITE);

	onGUI();


	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}


void idle()
{
	glutPostRedisplay();
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(200, timer, value++);
}

void input(unsigned char key, int mouseX, int mouseY)
{
	shelfKeyboard(key, mouseX, mouseY);

	cabinetKeyboard(key, mouseX, mouseY);

	if (key == 27)
		exit(0);
	glutPostRedisplay();
}


void resharp(int w, int h)
{
	setupCamera(w, h, 0.1f, 1000);
	ui::screenChange(w, h);

	glutReshapeWindow(w, h);
	glViewport(0, 0, w, h);
}


bool leftMouseButtonDown = false;
int lastMouseX, lastMouseY;

void mouse(int button, int state, int x, int y)
{
	btnAxes.onEvent(button, state, x, y);

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

void initLights()
{
	light l = addDirectionalLight(vec3(1, 10, 2), vec3(20), color3(1, 1, 1));

	addPointLight(vec3(0, 1, 0), color3(1, 1, 1));
}

void initialize_before_display()
{
	initEnvironment();
	initLights();
	initCube();
	initPlane();
	initPlane2();
	initCylinder();
	initSphere();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
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
	glutTimerFunc(200, timer, 0);
	glutKeyboardFunc(input);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);



	initialize_before_display();


	glutMainLoop();

	return 0;
}