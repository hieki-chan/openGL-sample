#pragma once

#include "core/openGL.h"

namespace engine
{
	namespace ui
	{
		extern int window_width, window_height;

		struct button
		{
			int x, y;
			int width, height;
			void (*onClick)();

			void onEvent(int button, int state, int x, int y);

			bool isInside(int mouseX, int mouseY) const;
		};

		void screenChange(int width, int height);

		void enable2d();

		void disable2d();

		void text2D(const char* text, int fontSize, int x, int y, color color = Angel::vec4(1, 1, 1, 1));

		button button2D(const char* text, int fontSize, int sizeX, int sizeY, int x, int y, color buttonColor = Angel::vec4(0, 0, 1, 1), color textColor = Angel::vec4(1, 1, 1, 1));
	}

}
