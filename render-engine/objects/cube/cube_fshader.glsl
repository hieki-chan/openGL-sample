#version 400

out vec4 fColor;
in vec4 color;

uniform vec4 mainColor;

void main()
{
	fColor = mainColor;
	//fColor = vec4(0, 0, 1, 1);
}