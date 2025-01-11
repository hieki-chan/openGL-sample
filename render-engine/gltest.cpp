#include<GL\glew.h>
#include<GL\freeglut.h>
#include<iostream>
#include "ShaderCompilier.h"
GLuint VAO, VBO;

float vertices[] =
{
	-.5f, -.5f,
	.5f, -.5f,
	.0f, .5f,
};


void initBuffers()
{
	//vertex array object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//vertex buffer object
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindVertexArray(0);
}

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos, 1.0);
}
)";


const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0, 0.5, 0.2, 1.0);
}
)";


void shader()
{
	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	initProgram(vertexShader, fragmentShader);
}

void display()
{

	glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);

	glutSwapBuffers();
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
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Render");

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "GLEW Init Error: " << glewGetErrorString(err) << std::endl;
        return -1;
    }

	initBuffers();
	shader();

	glutDisplayFunc(display);
	glutKeyboardFunc(input);

	glutMainLoop();

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	return 0;
}