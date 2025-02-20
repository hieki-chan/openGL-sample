#pragma once

#include "openGL.h"

namespace engine
{
	struct shader
	{
		GLuint mloc;
		GLuint vloc;
		GLuint ploc;

		GLuint program;

		void initShader(const char* vShaderName, const char* fShaderName)
		{
			program = InitShader(vShaderName, fShaderName);

			mloc = glGetUniformLocation(program, "model");
			vloc = glGetUniformLocation(program, "view");
			ploc = glGetUniformLocation(program, "projection");
		}
	};

	extern shader defaultShader;
	extern shader emissionShader;


	void initDefaultShaders();
}

