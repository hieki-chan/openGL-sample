#pragma once
#include "openGL.h"

namespace engine
{
	struct light
	{
	public:
		vec3 lightPos = vec3(0, 0, 0);

		//color3 lightColor = color3(1, 1, 1);

		color3 ambient = color3(1, 1, 1);
		color3 diffuse = color3(1, 1, 1);
		color3 specular = color3(1, 1, 1);



		void setPosition(vec3 position);

		void setTransformMatrix(mat4 matrix);
	};

	struct directionalLight : public light
	{
	public:
		vec3 lightDir;
	};


	struct pointLight : public light
	{
	public:
		float constant = 1.0f;
		float linear = 0.032f;
		float quadratic = 0.012f;
		float radius = 10.0f;
	};

	directionalLight* oneDirectionalLight(const vec3& position, const vec3& direction);

	pointLight* addPointLight(const vec3& position);

	void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName,
		const char* viewPositionName, const vec3& cameraPosition);

	void disposeLights();
}
