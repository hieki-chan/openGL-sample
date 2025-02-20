#include "core/openGL.h"

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

void bind(GLuint program, GLuint VAO)
{
	glUseProgram(program);
	glBindVertexArray(VAO);
}


void unbind(GLuint VAO, GLuint program)
{
	glBindVertexArray(VAO);
	glUseProgram(program);
}


mat4 TRS(const vec3& position, const vec3& rotation, const vec3& scale)
{
	return Translate(position) * RotateX(rotation.x) * RotateY(rotation.y) * RotateZ(rotation.z) * Scale(scale);
}



#pragma region SHADERS

GLuint compileShader(GLenum glShaderType, const char* shaderSource)
{
	GLuint shader = glCreateShader(glShaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	//check for errors
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		char infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "Compile shader error: " << infoLog << std::endl;
	}

	return shader;
}

GLuint initProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//check for errors
	int status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (!status)
	{
		char infoLog[512];
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << infoLog << std::endl;
	}

	return shaderProgram;
}

GLuint initProgram(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	GLuint program;

	return 1;
}

void setUniformInt(GLuint program, const std::string& name, const int* value)
{
	glUniform1iv(glGetUniformLocation(program, name.c_str()), 1, value);
}

void setUniformFloat(GLuint program, const std::string& name, const float* value)
{
	glUniform1fv(glGetUniformLocation(program, name.c_str()), 1, value);
}

void setUniformVec3(GLuint program, const std::string& name, const vec3& value)
{
	glUniform3fv(glGetUniformLocation(program, name.c_str()), 1, value);
}

void setUniformVec4(GLuint program, const std::string& name, const vec4& value)
{
	glUniform4fv(glGetUniformLocation(program, name.c_str()), 1, value);
}
#pragma endregion
