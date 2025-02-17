#include "objects/cube.h"

#include "core/camera.h"
#include "core/lighting.h"

#include<iostream>

const int CUBE_VERTEX_COUNT = 36;

point4 cube_points[CUBE_VERTEX_COUNT];
point4 cube_vertices[8];
vec3 cube_normals[CUBE_VERTEX_COUNT];
GLuint cube_program;


void createCube()
{
	cube_vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);
	cube_vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);
	cube_vertices[2] = point4(0.5, 0.5, 0.5, 1.0);
	cube_vertices[3] = point4(0.5, -0.5, 0.5, 1.0);
	cube_vertices[4] = point4(-0.5, -0.5, -0.5, 1.0);
	cube_vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);
	cube_vertices[6] = point4(0.5, 0.5, -0.5, 1.0);
	cube_vertices[7] = point4(0.5, -0.5, -0.5, 1.0);
}
int Index = 0;
void quad(int a, int b, int c, int d)
{
	vec4 u = cube_vertices[b] - cube_vertices[a];
	vec4 v = cube_vertices[c] - cube_vertices[b];
	vec3 normal = normalize(cross(u, v));

	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[a]; Index++;
	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[b]; Index++;
	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[c]; Index++;
	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[a]; Index++;
	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[c]; Index++;
	cube_normals[Index] = normal; cube_points[Index] = cube_vertices[d]; Index++;
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


GLuint cube_mloc, cube_vloc, cube_ploc;
GLuint cube_VAO, cube_VBO;

void initCubeBuffers()
{
	//vertex array object
	cube_VAO = initVAO();

	//vertex buffer object
	cube_VBO = initVBO(sizeof(cube_points) + sizeof(cube_normals), cube_points, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(cube_points), sizeof(cube_normals), cube_normals);


	//program
	cube_program = InitShader("objects/cube/cube_vshader.glsl", "objects/cube/cube_fshader.glsl");

	// v position
	GLuint loc_vPos = glGetAttribLocation(cube_program, "vPosition");

	//normal location
	GLuint loc_vNormal = glGetAttribLocation(cube_program, "vNormal");
	glEnableVertexAttribArray(loc_vNormal);
	glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(cube_points)));

	glEnableVertexAttribArray(loc_vPos);
	glVertexAttribPointer(loc_vPos, sizeof(float), GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	/*GLuint loc_vColor = glGetAttribLocation(program, "vColor");
	glEnableVertexAttribArray(loc_vColor);
	glVertexAttribPointer(loc_vColor, 4, GL_FLOAT, GL_FALSE, 0,
		BUFFER_OFFSET(sizeof(points)));*/

	cube_mloc = glGetUniformLocation(cube_program, "model");
	cube_vloc = glGetUniformLocation(cube_program, "view");
	cube_ploc = glGetUniformLocation(cube_program, "projection");


	glEnable(GL_DEPTH_TEST);

	glUseProgram(cube_program);
}

void initCube()
{
	createCube();
	makeColorCube();
	initCubeBuffers();
}

mat4 cubeModelMatrix;


void drawCube(vec3 position, vec3 rotation, vec3 scale, color color)
{
	//unbind VAO and program
	bind(cube_program, cube_VAO);

	//use camera matrix
	useCameraMatrix(cube_vloc, cube_ploc);

	//model matrix
	mat4 instance = TRS(position, rotation, scale);
	glUniformMatrix4fv(cube_mloc, 1, GL_TRUE, cubeModelMatrix * instance);

	//set object color
	setUniformVec4(cube_program, "mainColor", color);

	//set light position, light color and camera position
	useLights(cube_program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);

	glDrawArrays(GL_TRIANGLES, 0, CUBE_VERTEX_COUNT);

	//unbind VAO and program
	unbind();
}


mat4 cubeTransformMatrix(mat4 matrix)
{
	return cubeModelMatrix = matrix;
}

mat4 cubeTransform(const vec3& position, const vec3& rotation, const vec3& scale)
{
	return cubeModelMatrix = TRS(position, rotation, scale);
}

void cubeReset()
{
	cubeModelMatrix = identity();
}

