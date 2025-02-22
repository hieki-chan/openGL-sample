#include "objects/plane2.h"

#include "core/camera.h"
#include "core/lighting.h"

const int PLANE2_VERTEX_COUNT = 36;

point4 plane2_points[PLANE2_VERTEX_COUNT];
point4 plane2_vertices[8];
vec3 plane2_normals[PLANE2_VERTEX_COUNT];

void createPlane2()
{
	plane2_vertices[0] = point4(-0.5, -0.5, 0.5, 1.0);  // Bottom-left front
	plane2_vertices[1] = point4(-0.5, 0.5, 0.5, 1.0);   // Top-left front
	plane2_vertices[2] = point4(0.5, 0.5, 0.5, 1.0);    // Top-right front
	plane2_vertices[3] = point4(0.5, -0.5, 0.5, 1.0);   // Bottom-right front

	plane2_vertices[4] = point4(-0.2, -0.5, -0.5, 1.0); // Bottom-left back
	plane2_vertices[5] = point4(-0.2, 0.5, -0.5, 1.0);  // Top-left back
	plane2_vertices[6] = point4(0.2, 0.5, -0.5, 1.0);   // Top-right back
	plane2_vertices[7] = point4(0.2, -0.5, -0.5, 1.0);  // Bottom-right back
}

int plane2_index = 0;
void plane2_quad(int a, int b, int c, int d)
{
	vec4 u = plane2_vertices[b] - plane2_vertices[a];
	vec4 v = plane2_vertices[c] - plane2_vertices[b];
	vec3 normal = normalize(cross(u, v));

	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[a]; plane2_index++;
	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[b]; plane2_index++;
	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[c]; plane2_index++;
	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[a]; plane2_index++;
	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[c]; plane2_index++;
	plane2_normals[plane2_index] = normal; plane2_points[plane2_index] = plane2_vertices[d]; plane2_index++;
}

void makeColorPlane2()
{
	plane2_quad(1, 0, 3, 2);
	plane2_quad(2, 3, 7, 6);
	plane2_quad(3, 0, 4, 7);
	plane2_quad(6, 5, 1, 2);
	plane2_quad(4, 5, 6, 7);
	plane2_quad(5, 4, 0, 1);
}

GLuint plane2_VAO, plane2_VBO;

void initPlane2Buffers()
{
	plane2_VAO = initVAO();
	plane2_VBO = initVBO(sizeof(plane2_points) + sizeof(plane2_normals), plane2_points, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(plane2_points), sizeof(plane2_normals), plane2_normals);

	GLuint plane2_program = engine::defaultShader.program;

	GLuint loc_vPos = glGetAttribLocation(plane2_program, "vPosition");
	GLuint loc_vNormal = glGetAttribLocation(plane2_program, "vNormal");
	glEnableVertexAttribArray(loc_vNormal);
	glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(plane2_points)));

	glEnableVertexAttribArray(loc_vPos);
	glVertexAttribPointer(loc_vPos, sizeof(float), GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void initPlane2()
{
	createPlane2();
	makeColorPlane2();
	initPlane2Buffers();
}

mat4 plane2ModelMatrix;

void drawPlane2(const vec3& position, const vec3& rotation, const vec3& scale, const color& mainColor, engine::shader shader)
{
	bind(shader.program, plane2_VAO);
	useCameraMatrix(shader.vloc, shader.ploc);

	mat4 instance = TRS(position, rotation, scale);
	glUniformMatrix4fv(shader.mloc, 1, GL_TRUE, plane2ModelMatrix * instance);

	setUniformVec4(shader.program, "mainColor", mainColor);
	useLights(shader.program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);

	glDrawArrays(GL_TRIANGLES, 0, PLANE2_VERTEX_COUNT);
	unbind();
}

mat4 plane2TransformMatrix(mat4 matrix)
{
	return plane2ModelMatrix = matrix;
}

mat4 plane2Transform(const vec3& position, const vec3& rotation, const vec3& scale)
{
	return plane2ModelMatrix = TRS(position, rotation, scale);
}

void plane2Reset()
{
	plane2ModelMatrix = identity();
}
