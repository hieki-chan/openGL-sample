#include "pyramid.h"

GLuint loc_m;


void initPyramid()
{
	vec4 vertices[] =
	{
		vec4(-0.5f, -0.5f, 0.5f, 1.0f)  ,//1
		vec4(0.5f, -0.5f, 0.5f, 1.0f),	//2
		vec4(-0.5f, -0.5f, -0.5f, 1.0f),//4

		vec4(0.5f, -0.5f, 0.5f, 1.0f), //2
		vec4(0.5f, -0.5f, -0.5f, 1.0f),//3
		vec4(-0.5f, -0.5f, -0.5f, 1.0f),//4

		vec4(-0.5f, -0.5f, -0.5f, 1.0f),//4
		vec4(0.0f, 0.5f, 0.0f, 1.0f),	//5
		vec4(-0.5f, -0.5f, 0.5f, 1.0f),	//1

		vec4(-0.5f, -0.5f, 0.5f, 1.0f),	//1
		vec4(0.0f, 0.5f, 0.0f, 1.0f),	//5
		vec4(0.5f, -0.5f, 0.5f, 1.0f), //2

		vec4(0.5f, -0.5f, 0.5f, 1.0f), //2
		vec4(0.0f, 0.5f, 0.0f, 1.0f),	//5
		vec4(0.5f, -0.5f, -0.5f, 1.0f),//3

		vec4(0.5f, -0.5f, -0.5f, 1.0f),//3
		vec4(0.0f, 0.5f, 0.0f, 1.0f),	//5
		vec4(-0.5f, -0.5f, -0.5f, 1.0f),//4
	};


	GLuint VAO, VBO;

	VAO = initVAO();
	VBO = initVBO(sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLuint programShader = INIT_PROGRAM("p_vshader.glsl", "p_fshader.glsl");


	GLuint loc_v = glGetAttribLocation(programShader, "vPosition");

	loc_m = glGetUniformLocation(programShader, "matrix");

	glEnableVertexAttribArray(loc_v);
	//
	glVertexAttribPointer(loc_v, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	glUseProgram(programShader);

	glEnable(GL_DEPTH_TEST);
}

float angle = 0;

void drawPyramid()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	//tao goc xoay
	angle += 0.02f;
	mat4 m = RotateX(angle) * RotateY(angle);

	glUniformMatrix4fv(loc_m, 1, GL_TRUE, m);

	glDrawArrays(GL_LINE_LOOP, 0, 24);
}