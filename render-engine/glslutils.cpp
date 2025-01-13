#include "glslutils.h";


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