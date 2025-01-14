#include<GL\glew.h>
#include<GL\freeglut.h>
#include<iostream>

#include "cube.h"
#include "triangle.h"
#include "rectangle.h"


void initBuffers()
{
	
}


void shader()
{
	
}

void display()
{

	//glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);

	//drawTriangle();
	drawCube();

	//drawRectangle();

	glutSwapBuffers();
}

void idle()
{
	display();
	glutPostRedisplay();
}

void input(unsigned char c, int a, int b)
{
	if (c == 27)
		exit(0);
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

	initBuffers();
	shader();

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(input);
	
	glutMainLoop();

	//deleteTriangle();
	deleteCube();

	return 0;
}