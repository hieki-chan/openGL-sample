#pragma once

#include "core/openGL.h"
#include "core/shaders.h"
#include "core/camera.h"
#include "core/lighting.h"

void initSign();

void drawSign(const vec3& position, const vec3& rotation, const vec3& scale,
	const color& mainColor,
	engine::shader shader = engine::defaultShader);