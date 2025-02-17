 //include core engine

#include "core/openGL.h"		// open gl and utilities
#include "core/camera.h"		// camera
#include "core/environment.h"	// environment
#include "core/ui.h"			// user interface

 //include objects

#include "objects/cube.h"		
#include "objects/shelf.h"		

#include <cmath>
#include <cstring>



void introScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);
	rasterText(vec3(0, 0, 0), "Render Engine");
	glColor3f(0.0, 0.0, 1.0);

	//glFlush();
	//glutSwapBuffers();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	introScreen();

	drawAxes();

	drawShelf(vec3(1, 1, 1), vec3(0, 90, 0), vec3(1, .5f, 1));

	drawShelf(vec3(-2, -4, 4), vec3(0, 0, 0), vec3(1, .5f, 1));


	glEnable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

bool stopIdle = FALSE;

void idle()
{
	if (stopIdle)
		return;
	glutPostRedisplay();
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(.02f, timer, value++);
}

void input(unsigned char key, int mouseX, int mouseY)
{
	shelfKeyboard(key, mouseX, mouseY);

	if (key == 27)
		exit(0);
}

void mouseInput(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON
		&& state == GLUT_UP)
	{
		stopIdle = !stopIdle;
	}
}


void resharp(int w, int h)
{
	setupCamera(w, h, 0.1f, 1000);


	glutReshapeWindow(w, h);
	glViewport(0, 0, w, h);
}


bool leftMouseButtonDown = false;
int lastMouseX, lastMouseY;

void mouse(int button, int state, int x, int y)
{
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
	{
		cameraMotion(x, y, lastMouseX, lastMouseY);
	}
}

void initialize_before_display()
{
	initEnvironment();
	initCube();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
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