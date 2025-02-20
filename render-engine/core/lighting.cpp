#include "core/lighting.h"
//#include<vector>
#include<string>

//LIGHT CLASS
void light::setPosition(vec3 position)
{
	this->lightPos = position;
}

void light::setTransformMatrix(mat4 matrix)
{
	vec4 transform = matrix * vec4(0, 0, 0, 1);
	this->lightPos = vec3(transform.x, transform.y, transform.z);

	//std::cout << this->lightPos;
}

//=======================================\\


directionalLight* dirLight = new directionalLight();

#define MAX_POINT_LIGHT_COUNT 10
//std::vector<pointLight> pointLights = {}
pointLight* pointLights;

int pointLightCount;

directionalLight* oneDirectionalLight(const vec3& position, const vec3& direction)
{
	directionalLight* dl = new directionalLight();
	dl->lightPos = position;
	dl->lightDir = direction;

	return 	dirLight = dl;
}

pointLight* addPointLight(const vec3& position)
{
	if (pointLights == nullptr)
	{
		pointLights = new pointLight[MAX_POINT_LIGHT_COUNT];
	}

	if (pointLightCount >= MAX_POINT_LIGHT_COUNT)
	{
		std::cerr << "Max point light count reached!" << std::endl;
		return nullptr;
	}

	pointLights[pointLightCount].lightPos = position;

	return &pointLights[pointLightCount++];
}


void useLights(GLuint shader_program, const char* lightPositionName, const char* lightColorName,
	const char* viewPositionName, const vec3& cameraPosition)
{
	setUniformVec3(shader_program, viewPositionName, cameraPosition);

	//directional light(s)
	std::string dlightName = "directionalLight.";
	setUniformVec3(shader_program, dlightName + "direction", (dirLight)->lightDir);
	//setUniformVec3(shader_program, dlightName + "color", (dirLight)->lightColor);
	setUniformVec3(shader_program, dlightName + "ambient", (dirLight)->ambient);
	setUniformVec3(shader_program, dlightName + "specular", (dirLight)->specular);

	//int pointLightCount = pointLights.size();
	setUniformInt(shader_program, "pointLightCount", &pointLightCount);

	//point lights
	for (int i = 0; i < pointLightCount; i++)
	{
		//std::cout << (pointLights + i)->lightPos << std::endl;
		std::string pointLightIndex = std::string("pointLights[") + std::to_string(i) + "].";

		//setUniformVec3(shader_program, lightPositionName, pointLights[i].lightPos);
		//setUniformVec3(shader_program, lightColorName, pointLights[i].lightColor);

		setUniformVec3(shader_program, pointLightIndex + "position", (pointLights + i)->lightPos);

		//setUniformVec3(shader_program, pointLightIndex + "color", (pointLights + i)->lightColor);
		setUniformVec3(shader_program, pointLightIndex + "ambient", (pointLights + i)->ambient);
		setUniformVec3(shader_program, pointLightIndex + "diffuse", (pointLights + i)->diffuse);
		setUniformVec3(shader_program, pointLightIndex + "specular", (pointLights + i)->specular);

		setUniformFloat(shader_program, pointLightIndex + "constant", &pointLights[i].constant);
		setUniformFloat(shader_program, pointLightIndex + "linear", &(pointLights + i)->linear);
		setUniformFloat(shader_program, pointLightIndex + "quadratic", &(pointLights + i)->quadratic);
	}
}

void disposeLights()
{
	delete[] pointLights;
}