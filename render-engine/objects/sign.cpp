#include "objects/sign.h"

#define STB_IMAGE_IMPLEMENTATION
#include "core/stb_image.h"		//stb image

GLuint 
	sign_VAO,
	sign_texture;

void initSign()
{
	float vertices[] = {
		// positions          // colors           // tex coords   // normals
		 0.5f,  0.5f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   0.0f, 0.0f, 1.0f,  // top right
		 0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   0.0f, 0.0f, 1.0f,  // bottom left
		-0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f,   0.0f, 0.0f, 1.0f   // top left 
	};
	unsigned int indices[] = {
		0, 1, 3, // first triangle
		1, 2, 3  // second triangle
	};
	unsigned int VBO, EBO;
	glGenVertexArrays(1, &sign_VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	shader ourShader = engine::defaultShader;
	bind(ourShader.program, sign_VAO);


	glBindVertexArray(sign_VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// VPOS
	GLuint loc_vPos = glGetAttribLocation(ourShader.program, "vPosition");
	glVertexAttribPointer(loc_vPos, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(loc_vPos);

	// VCOLOR
	GLuint loc_vColor = glGetAttribLocation(ourShader.program, "vColor");
	glVertexAttribPointer(loc_vColor, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(loc_vColor);

	// VTEXTCOORD
	GLuint textCoord_loc = glGetAttribLocation(ourShader.program, "vTextCoord");
	glVertexAttribPointer(textCoord_loc, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(textCoord_loc);

	// VNORMAL
	GLuint loc_vNormal = glGetAttribLocation(ourShader.program, "vNormal");
	glVertexAttribPointer(loc_vNormal, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(loc_vNormal);

	// load and create a texture 
	// -------------------------
	glGenTextures(1, &sign_texture);
	glBindTexture(GL_TEXTURE_2D, sign_texture); 
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//border
	float borderColor[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// load image, create texture and generate mipmaps
	int width, height, nrChannels;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load("plane_sign.jpg", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

mat4 signModelMatrix;

void drawSign(const vec3& position, const vec3& rotation, const vec3& scale, const color& mainColor, engine::shader shader)
{
	bind(shader.program, sign_VAO);

	// render container

	glBindTexture(GL_TEXTURE_2D, sign_texture);

	//use camera matrix
	useCameraMatrix(shader.vloc, shader.ploc);

	//model matrix
	mat4 instance = TRS(position, rotation, scale);
	glUniformMatrix4fv(shader.mloc, 1, GL_TRUE, signModelMatrix * instance);

	//set object color
	setUniformVec4(shader.program, "mainColor", mainColor);

	//set light position, light color and camera position
	useLights(shader.program, "lightPosition", "lightColor", "viewPosition", CAM_POS_3);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	unbind();
}