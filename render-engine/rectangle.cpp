#include "rectangle.h"

void drawRectangle()
{
	float vertices[] =
	{
		-0.5f, -0.5f, 1.0f,	//bottom left
		0.5f, -0.5f, 1.0f,	//bottom right
		0.5f, 0.5f, 1.0f,	//top right
		-0.5f, 0.5f, 1.0f,	//top left
	};


	unsigned int triangles[]
	{
		0, 1, 3, 
		1, 2, 3
	};

	GLuint VAO, VBO, EBO;

	//vao
	VAO = initVAO();

	//vbo
	VBO = initVBO(sizeof(vertices), vertices, GL_STATIC_DRAW);

	//ebo
	EBO = initEBO(sizeof(triangles), triangles, GL_STATIC_DRAW);

	//pointer	
	vertexAttribPointer(0, 3, sizeof(float) * 3, BUFFER_OFFSET(0));


	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 6);
}