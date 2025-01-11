#version core 300

layout (location = 0) in vec3 vPosition;

int main()
{
	gl_Position = vec4(aPos, 1.0);
}