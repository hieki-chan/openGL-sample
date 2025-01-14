#include "cube.h"
#include<iostream>

const int CUBE_VERTEX_COUNT = 36;
typedef vec4 point4;
typedef vec4 c4;

point4 points[CUBE_VERTEX_COUNT];
c4 colors[CUBE_VERTEX_COUNT];
point4 vertices[8];
c4 vertex_colors[8];
GLuint program, loc_modelMatrix;

mat4 ctm;


void initCube()
{
	
	vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
	vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
	vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
	vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
	vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
	vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
	vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
	vertices[7] = point4(0.5, -0.5, -0.5, 1.0);

	vertex_colors[0] = c4(0.0, 0.0, 0.0, 1.0); // black 
	vertex_colors[1] = c4(1.0, 0.0, 0.0, 1.0); // red 
	vertex_colors[2] = c4(1.0, 1.0, 0.0, 1.0); // yellow 
	vertex_colors[3] = c4(0.0, 1.0, 0.0, 1.0); // green 
	vertex_colors[4] = c4(0.0, 0.0, 1.0, 1.0); // blue 
	vertex_colors[5] = c4(1.0, 0.0, 1.0, 1.0); // magenta 
	vertex_colors[6] = c4(1.0, 0.8, 0.0, 1.0); // orange 
	vertex_colors[7] = c4(0.0, 1.0, 1.0, 1.0); // cyan 
}
int Index = 0;
void quad(int a, int b, int c, int d)  
{
	colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[b]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[c]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[c]; Index++;
	colors[Index] = vertex_colors[a]; points[Index] = vertices[d]; Index++;
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
	initCube();
	makeColorCube();
}

float rotX = 10l;

void initCubeBuffers()
{
	GLuint VAO, VBO;
	//vertex array object
	VAO = initVAO();

	//vertex buffer object
	VBO = initVBO(sizeof(points) + sizeof(colors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);

	//program
	GLuint program = InitShader("cube_vshader.glsl", "cube_fshader.glsl");

	// v position
	GLuint loc_vPos = glGetAttribLocation(program, "vPosition");

	glEnableVertexAttribArray(loc_vPos);
	glVertexAttribPointer(loc_vPos, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

	GLuint loc_vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(loc_vColor);
	glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(sizeof(points)));


	auto loc_modelMatrix = glGetUniformLocation(program, "model");
	std::cout << loc_vPos;
	std::cout << loc_modelMatrix;
	glEnable(GL_DEPTH_TEST);

	glUseProgram(program);
}

void initCubeBuff()
{
	generateGeometry();
	initCubeBuffers();	
}


void drawCube()
{
	rotX += .02f;
	mat4 instance = Translate(0, 0, 0) * Scale(1, 0.8f, 1) * Angel::RotateY(rotX) * RotateX(rotX);
	glUniformMatrix4fv(loc_modelMatrix, 1, GL_TRUE, instance);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawArrays(GL_TRIANGLES, 0, CUBE_VERTEX_COUNT);
}

void deleteCube()
{
	
}