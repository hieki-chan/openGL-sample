#version 400

out vec4 fColor;

in vec4 color;
in vec3 FragPos;
in vec3 Normal;

//light
uniform vec3 lightPosition;
uniform vec3 lightColor;

uniform float constant;
uniform float linear;
uniform float quadratic;

//camera
uniform vec3 viewPosition;

uniform vec4 mainColor;

void main()
{
	//lightColor = vec3(1, 1, 1);
	//lightPosition = vec3(0, 1, 1);
	
	//ambient
	float ambientStrength = 0.2;
    vec3 ambient = ambientStrength * lightColor;

	//diffuse
	vec3 normal = normalize(Normal);
	vec3 lightDir = normalize(lightPosition - FragPos);
	float kDiff = max(dot(normal, lightDir), 0.0);
	vec3 diffuse = kDiff * lightColor;

	//specular
	vec3 viewDir = normalize(viewPosition - FragPos);
	vec3 reflectDir = reflect(-lightDir, normal); 

	float specularStrength = 0.5f;
	float shininess = 64;
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
	vec3 specular = specularStrength * spec * lightColor;  


	//point light
	float distance = length(lightPosition - FragPos);
	float attenuation = 1.0 / (constant + linear * distance + 
    		    quadratic * (distance * distance));    

	//final color
	vec3 result = (ambient + diffuse + specular) * attenuation * mainColor.xyz;


	fColor = vec4(result, mainColor.w);
	//fColor = mainColor;
	//fColor = vec4(0, 0, 1, 1);
}