#include "openGL.h"

#include "cube.h"


void resize(int w, int h)
{
	glutInitWindowSize(w, h);
}



void display()
{

	//glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT);

	//drawTriangle();

	drawCube(vec3(), vec3(), vec3(1, 1, 1), color(0, 1, 1, 1));

	//drawRectangle();
	//drawPyramid();

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
	//glutPostRedisplay();
	glutTimerFunc(.02f, timer, value++);
}

void input(unsigned char key, int mouseX, int mouseY)
{
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

	initCube();
	//initPyramid();

	//table table = createTable();

	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	glutTimerFunc(200, timer, 0);
	glutKeyboardFunc(input);
	glutMouseFunc(mouseInput);
	
	glutMainLoop();

	//deleteTriangle();
	//deleteCube();

	return 0;
}