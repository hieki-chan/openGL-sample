#include "openGL.h"

GLuint initVAO()
{
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	return VAO;
}

GLuint initVBO(GLsizeiptr size, const void* data, GLenum usage)
{
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);

	return VBO;
}

GLuint initEBO(GLsizeiptr size, const void* data, GLenum usage)
{
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);

	return EBO;
}

void vertexAttribPointer(GLuint index, GLint size, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(index);
}

void unbind(GLuint VAO, GLuint VBO)
{

}