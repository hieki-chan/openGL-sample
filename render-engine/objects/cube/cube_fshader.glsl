#version 400

out vec4 fColor;

struct DirectionalLight
{
	//vec3 position;
	vec3 direction;
	
	//vec3 color;
	vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

#define MAX_POINT_LIGHTS 10

struct PointLight
{
	vec3 position;

	//vec3 color;
	vec3 ambient;
    vec3 diffuse;
    vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

in vec4 color;
in vec3 FragPos;
in vec3 Normal;

//camera
uniform vec3 viewPosition;

// >> directional light(s)
uniform DirectionalLight directionalLight;

// >> point lights
uniform PointLight pointLights[MAX_POINT_LIGHTS];
uniform int pointLightCount;

//color
uniform vec4 mainColor;

//function prototype
vec3 calculateDirectionalLights(DirectionalLight dlight);
vec3 calculatePointLights(PointLight plight);
vec3 shading(vec3 lightDir, vec3 lightColor, vec3 lightDiffuse, vec3 lightSpecular);

void main()
{
	//final color
	vec3 result = vec3(0, 0, 0);

	//calculate directional light
	result += calculateDirectionalLights(directionalLight);

	//calculate point lights
	for(int i = 0; i < pointLightCount; i++)
	{
		PointLight light = pointLights[i];
		result += calculatePointLights(light);
	}
  
	fColor = vec4(result, mainColor.w);
	//fColor = mainColor;
	//fColor = vec4(0, 0, 1, 1);
}

vec3 calculateDirectionalLights(DirectionalLight dlight)
{
	return shading(normalize(-dlight.direction), dlight.ambient, dlight.diffuse, dlight.specular);
}

vec3 calculatePointLights(PointLight plight)
{
	vec3 lightDir = normalize(plight.position - FragPos);
	vec3 result = shading(lightDir, plight.ambient, plight.diffuse, plight.specular);

	float distance = length(plight.position - FragPos);
	float attenuation = 1.0 / (plight.constant + plight.linear * distance +  plight.quadratic * (distance * distance));    
	return result * attenuation;
}

vec3 shading(vec3 lightDir, vec3 lightColor, vec3 lightDiffuse, vec3 lightSpecular)
{
	//lightColor = vec3(1, 1, 1);
	//lightPosition = vec3(0, 1, 1);
	
	// ambient
	float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

	// diffuse
	vec3 normal = normalize(Normal);
	float kDiff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = kDiff * lightDiffuse;

	// specular
	vec3 viewDir = normalize(viewPosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, normal); 

	float specularStrength = 0.5f;
	float shininess = 64;
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = specularStrength * spec * lightSpecular;  

	// final color
	vec3 result = (ambient + diffuse + specular) * mainColor.xyz;
	return result;
}