#version 400
in vec4 vPosition;
in vec4 vColor;
in vec3 vNormal;

out vec4 color;

out vec3 FragPos;
out vec3 Normal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vPosition;
    //gl_Position = model * vPosition;
	color=vColor;

    //Normal = vNormal;
    Normal = mat3(transpose(inverse(model))) * vNormal;
    FragPos = vec3(model * vPosition);
}