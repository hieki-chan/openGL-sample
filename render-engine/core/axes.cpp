#include "core/axes.h"
#include "core/camera.h"

const color xColor = color(1, 0, 0, 1);		
const color yColor = color(0, 1, 0, 1);		
const color zColor = color(0, 0, 1, 1);

const float axis_length = 5;

const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 vertexColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() 
{
    vertexColor = aColor;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
in vec3 vertexColor;
out vec4 FragColor;

void main()
{
    FragColor = vec4(vertexColor, 1.0);
}
)";

GLuint axes_program;
GLuint transform_location;
GLuint axes_VAO, axes_VBO[2], axes_EBO;

void engine::initAxes()
{
	const float axis_vertices[] = {
		// Vị trí
		-5, 0, 0,  // (X-)
		 5, 0, 0,  // (X+)
		 0,-5, 0,  // (Y-)
		 0, 5, 0,  // (Y+)
		 0, 0,-5,  // (Z-)
		 0, 0, 5   // (Z+)
	};
	const float axis_colors[] = {
		1, 0, 0,  // X Axis
		1, 0, 0,
		0, 1, 0,  // Y Axis 
		0, 1, 0,
		0, 0, 1,  // Z Axis
		0, 0, 1
	};
	const unsigned int axis_indices[] = {
		0, 1,  // X
		2, 3,  // Y
		4, 5   // Z
	};

	glGenVertexArrays(1, &axes_VAO);
	glBindVertexArray(axes_VAO);

	// VBO - Vị trí
	glGenBuffers(2, axes_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, axes_VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axis_vertices), axis_vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(0);

	// VBO - Màu sắc
	glBindBuffer(GL_ARRAY_BUFFER, axes_VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(axis_colors), axis_colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
	glEnableVertexAttribArray(1);

	// EBO - Chỉ mục
	glGenBuffers(1, &axes_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, axes_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(axis_indices), axis_indices, GL_STATIC_DRAW);

	// Unbind VAO
	glBindVertexArray(0);


	//compile shader
	GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
	GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	axes_program = initProgram(vertexShader, fragmentShader);
	glUseProgram(axes_program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


	GLuint loc_v = glGetAttribLocation(axes_program, "aPos");
	transform_location = glGetUniformLocation(axes_program, "transform");
	glEnableVertexAttribArray(loc_v);
	//
	glVertexAttribPointer(loc_v, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void drawLine(const vec3& dir, float length, const color& color)
{
	//setVec3(axes_program, "transform", dir * length);


	//glUseProgram(axes_program);
	//setUniformVec4(axes_program, "color", color);

	glUniformMatrix4fv(transform_location, 1, GL_TRUE, Scale(dir * length));

	glBindVertexArray(axes_VAO);


	glDrawArrays(GL_LINES, 0, 2);

	//glUseProgram(0);
	//glBindVertexArray(0);
}

void engine::drawAxes()
{
	glUseProgram(axes_program);
	glBindVertexArray(axes_VAO);


	GLuint mloc = glGetUniformLocation(axes_program, "model");
	GLuint vloc = glGetUniformLocation(axes_program, "view");
	GLuint ploc = glGetUniformLocation(axes_program, "projection");

	useCameraMatrix(vloc, ploc);

	glUniformMatrix4fv(mloc, 1, GL_TRUE, Scale(100));

	glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glUseProgram(0);
}