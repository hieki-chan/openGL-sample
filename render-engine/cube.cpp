#include "cube.h"
#include "camera.h"
#include<iostream>

const int CUBE_VERTEX_COUNT = 36;

point4 points[CUBE_VERTEX_COUNT];
point4 vertices[8];
GLuint program;

mat4 ctm;


void createCube()
{
	vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
	vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
	vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
	vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
	vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
	vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
	vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
	vertices[7] = point4(0.5, -0.5, -0.5, 1.0);
}
int Index = 0;
void quad(int a, int b, int c, int d)
{
	points[Index] = vertices[a]; Index++;
	points[Index] = vertices[b]; Index++;
	points[Index] = vertices[c]; Index++;
	points[Index] = vertices[a]; Index++;
	points[Index] = vertices[c]; Index++;
	points[Index] = vertices[d]; Index++;
}
void makeColorCube()
{
	quad(1, 0, 3, 2);
	quad(2, 3, 7, 6);
	quad(3, 0, 4, 7);
	quad(6, 5, 1, 2);
	quad(4, 5, 6, 7);
	quad(5, 4, 0, 1);
}
void generateGeometry()
{
	createCube();
	makeColorCube();
}

float rotX = 10l;

GLuint mloc, vloc, ploc;


void initCubeBuffers()
{
	GLuint VAO, VBO;
	//vertex array object
	VAO = initVAO();

	//vertex buffer object
	VBO = initVBO(sizeof(points), points, GL_STATIC_DRAW);

	//program
	program = InitShader("cube_vshader.glsl", "cube_fshader.glsl");

	// v position
	GLuint loc_vPos = glGetAttribLocation(program, "vPosition");

	glEnableVertexAttribArray(loc_vPos);
	glVertexAttribPointer(loc_vPos, sizeof(float), GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	/*GLuint loc_vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(loc_vColor);
	glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(sizeof(points)));*/

	mloc = glGetUniformLocation(program, "model");
	vloc = glGetUniformLocation(program, "view");
	ploc = glGetUniformLocation(program, "projection");


	glEnable(GL_DEPTH_TEST);

	glUseProgram(program);
}

void initCube()
{
	generateGeometry();
	initCubeBuffers();
}


void drawCube()
{
	rotX += .02f;
	mat4 instance = Translate(0, 0, 0) * Scale(1, 0.8f, 1) * Angel::RotateY(rotX) * RotateX(rotX);
	glUniformMatrix4fv(mloc, 1, GL_TRUE, instance);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, CUBE_VERTEX_COUNT);
}

void deleteCube()
{

}

void setVec4(const std::string& name, vec4 value)
{
	glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, &value[0]);
}

void drawCube(vec3 position, vec3 rotation, vec3 scale, color color)
{

	setVec4("mainColor", color);


	useCameraMatrix(vloc, ploc);


	rotX += .02f;
	mat4 instance = Translate(position) * Scale(scale) * RotateX(rotX);
	glUniformMatrix4fv(mloc, 1, GL_TRUE, instance);



	glDrawArrays(GL_TRIANGLES, 0, CUBE_VERTEX_COUNT);
}

