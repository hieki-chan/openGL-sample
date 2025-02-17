#version 400

out vec4 fColor;
in vec4 color;

uniform vec4 mainColor;

void main()
{
	vec3 lightColor = vec3(1, 1, 1);
	float ambientStrength = 0.4;
    vec3 ambient = ambientStrength * lightColor;
	vec3 result = ambient * mainColor.xyz;

	fColor = vec4(result, mainColor.w);
	//fColor = mainColor;
	//fColor = vec4(0, 0, 1, 1);
}