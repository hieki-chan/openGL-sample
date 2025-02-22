#include "core/shaders.h"

using namespace engine;

shader engine::defaultShader;
shader engine::emissionShader;

void engine::initDefaultShaders()
{
	engine::defaultShader.initShader("objects/cube/cube_vshader.glsl", "objects/cube/cube_fshader.glsl");
	engine::emissionShader.initShader("objects/vShader.glsl", "objects/fShader.glsl");
}