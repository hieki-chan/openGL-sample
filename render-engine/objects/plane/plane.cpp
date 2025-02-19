#include "objects/plane.h"

#include "core/camera.h"
#include "core/lighting.h"

const int PLANE_VERTEX_COUNT = 36;

point4 plane_points[PLANE_VERTEX_COUNT];
point4 plane_vertices[8];
vec3 plane_normals[PLANE_VERTEX_COUNT];
GLuint plane_program;

void createPlane()
{
	plane_vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);  // Bottom-left front
	plane_vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);   // Top-left front
	plane_vertices[2] = point4(0.5, 0.5, 0.5, 1.0);    // Top-right front
	plane_vertices[3] = point4(0.5, -0.5, 0.5, 1.0);   // Bottom-right front

	plane_vertices[4] = point4(-0.5, -0.5, -0.5, 1.0); // Bottom-left back
	plane_vertices[5] = point4(-0.5, 0.5, -0.5, 1.0);  // Top-left back
	plane_vertices[6] = point4(0.0, 0.5, -0.5, 1.0);   // Top-right back
	plane_vertices[7] = point4(0.0, -0.5, -0.5, 1.0);  // Bottom-right back

}

int plane_index = 0;
void plane_quad(int a, int b, int c, int d)
{
	vec4 u = plane_vertices[b] - plane_vertices[a];
	vec4 v = plane_vertices[c] - plane_vertices[b];
	vec3 normal = normalize(cross(u, v));

	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[a]; plane_index++;
	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[b]; plane_index++;
	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[c]; plane_index++;
	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[a]; plane_index++;
	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[c]; plane_index++;
	plane_normals[plane_index] = normal; plane_points[plane_index] = plane_vertices[d]; plane_index++;
}

void makeColorPlane()
{
	plane_quad(1, 0, 3, 2);
	plane_quad(2, 3, 7, 6);
	plane_quad(3, 0, 4, 7);
	plane_quad(6, 5, 1, 2);
	plane_quad(4, 5, 6, 7);
	plane_quad(5, 4, 0, 1);
}

GLuint plane_mloc, plane_vloc, plane_ploc;
GLuint plane_VAO, plane_VBO;

void initPlaneBuffers()
{
	plane_VAO = initVAO();
	plane_VBO = initVBO(sizeof(plane_points) + sizeof(plane_normals), plane_points, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(plane_points), sizeof(plane_normals), plane_normals);

	plane_program = InitShader("objects/cube/cube_vshader.glsl", "objects/cube/cube_fshader.glsl");

	GLuint loc_vPos = glGetAttribLocation(plane_program, "vPosition");
	GLuint loc_vNormal = glGetAttribLocation(plane_program, "vNormal");
	glEnableVertexAttribArray(loc_vNormal);
	glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(plane_points)));

	glEnableVertexAttribArray(loc_vPos);
	glVertexAttribPointer(loc_vPos, sizeof(float), GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	plane_mloc = glGetUniformLocation(plane_program, "model");
	plane_vloc = glGetUniformLocation(plane_program, "view");
	plane_ploc = glGetUniformLocation(plane_program, "projection");

	glEnable(GL_DEPTH_TEST);
	glUseProgram(plane_program);
}

void initPlane()
{
	createPlane();
	makeColorPlane();
	initPlaneBuffers();
}

mat4 planeModelMatrix;

void drawPlane(vec3 position, vec3 rotation, vec3 scale, color color)
{
	bind(plane_program, plane_VAO);
	useCameraMatrix(plane_vloc, plane_ploc);

	mat4 instance = TRS(position, rotation, scale);
	glUniformMatrix4fv(plane_mloc, 1, GL_TRUE, planeModelMatrix * instance);

	setUniformVec4(plane_program, "mainColor", color);
	useLights(plane_program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);

	glDrawArrays(GL_TRIANGLES, 0, PLANE_VERTEX_COUNT);
	unbind();
}

mat4 planeTransformMatrix(mat4 matrix)
{
	return planeModelMatrix = matrix;
}

mat4 planeTransform(const vec3& position, const vec3& rotation, const vec3& scale)
{
	return planeModelMatrix = TRS(position, rotation, scale);
}

void planeReset()
{
	planeModelMatrix = identity();
}