#include "core/ui.h"

int ui::window_width, ui::window_height;


void ui::enable2d()
{
	// PROJECTION
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, window_width, 0, window_height);

	// MODEL
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	// DISABLE 3d
	glDisable(GL_DEPTH_TEST);
}

void ui::disable2d()
{
	// REENABLE 3d
	glEnable(GL_DEPTH_TEST);

	// RESTORE 
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}

void ui::screenChange(int width, int height)
{
	ui::window_width = width;
	ui::window_height = height;
}

void ui::text2D(const char* text, int fontSize, int x, int y, color color)
{
	void* font = GLUT_BITMAP_TIMES_ROMAN_24;
	if (fontSize <= 8)
		font = GLUT_BITMAP_8_BY_13;
	else if (fontSize <= 10)
		font = GLUT_BITMAP_TIMES_ROMAN_10;
	else if (fontSize <= 12)
		font = GLUT_BITMAP_HELVETICA_12;
	else if (fontSize <= 15)
		font = GLUT_BITMAP_9_BY_15;
	else if (fontSize <= 18)
		font = GLUT_BITMAP_HELVETICA_18;
	else if (fontSize <= 24)
		font = GLUT_BITMAP_TIMES_ROMAN_24;
	else
		font = GLUT_BITMAP_TIMES_ROMAN_24;

	enable2d();

	glColor4f(color.x, color.y, color.z, color.w);
	// TEXT position
	glRasterPos2i(x, y);

	// render text
	for (const char* c = text; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}

	disable2d();
}

ui::button ui::button2D(const char* text, int fontSize, int sizeX, int sizeY, int x, int y, color buttonColor, color textColor)
{
	enable2d();

	glLineWidth(1);

	// Draw the button background using the provided color
	glColor4f(buttonColor.x, buttonColor.y, buttonColor.z, buttonColor.w);
	glBegin(GL_QUADS);
	// Bottom-left vertex
	glVertex2i(x, y);
	// Bottom-right vertex
	glVertex2i(x + sizeX, y);
	// Top-right vertex
	glVertex2i(x + sizeX, y + sizeY);
	// Top-left vertex
	glVertex2i(x, y + sizeY);
	glEnd();

	// Draw the button border in white
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x + sizeX, y);
	glVertex2i(x + sizeX, y + sizeY);
	glVertex2i(x, y + sizeY);
	glEnd();

	// Calculate the position for centering the text within the button
	int len = (int)strlen(text);
	int approxCharWidth = fontSize * 0.6;  // Approximate width per character
	int textWidth = len * approxCharWidth;
	int centerX = x + (sizeX - textWidth) / 2;
	int centerY = y + (sizeY - fontSize) / 2;  // Approximate vertical centering

	// Draw the text on the button
	text2D(text, fontSize, centerX, centerY, textColor);

	button btn = button();
	btn.x = x;
	btn.y = y;
	btn.width = sizeX;
	btn.height = sizeY;

	disable2d();

	return btn;
}


void ui::button::onEvent(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && isInside(x, y))
	{
		if (callback) 
		{

			callback();
		}
	}
}

bool ui::button::isInside(int mouseX, int mouseY) const
{
	mouseY = window_height - mouseY;

	return (mouseX >= x && mouseX <= (x + width) &&
		mouseY >= y && mouseY <= (y + height));
}

