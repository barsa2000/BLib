#ifndef PROVA_DLL
#define PROVA_DLL

#include <Windows.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <conio.h>
#include <time.h>
#include <vector>

#define COLOR_BLACK              0x00
#define COLOR_BLUE               0x01
#define COLOR_GREEN              0x02
#define COLOR_AQUA               0x03
#define COLOR_RED                0x04
#define COLOR_PURPLE             0x05
#define COLOR_YELLOW             0x06
#define COLOR_WHITE              0x07
#define COLOR_GRAY               0x08
#define COLOR_LIGHT_BLUE         0x09
#define COLOR_LIGHT_GREEN        0x0A
#define COLOR_LIGHT_AQUA         0x0B
#define COLOR_LIGHT_RED          0x0C
#define COLOR_LIGHT_PURPLE       0x0D
#define COLOR_LIGHT_YELLOW       0x0E
#define COLOR_BRIGHT_WHITE       0x0F
//
///////////////////////////////////////

//definition of standards//////////////
//
#define DEFAULT_FOREGROUND_COLOR 0x08
#define DEFAULT_BACKGROUND_COLOR 0x00

#define DEFAULT_FONT_SIZE        16

#define WINDOW_POS_CENTERED_X    -1
#define WINDOW_POS_CENTERED_Y    -1

#define TEXT_CENTERED_X          -1
#define TEXT_CENTERED_Y          -1
//
///////////////////////////////////////

#ifndef DECLARE
	#define DECLARE __declspec(dllexport)
#endif

namespace BCGraphics
{
	DECLARE inline void gotoXY(int x, int y);
	DECLARE inline void gotoXY(COORD pos);

	DECLARE void writetoXY(COORD pos, char text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE void writetoXY(COORD pos, char* text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE void writetoXY(COORD pos, double text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE void writetoXY(COORD pos, long long text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE inline void writetoXY(int x, int y, char text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE inline void writetoXY(int x, int y, char* text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE inline void writetoXY(int x, int y, double text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE inline void writetoXY(int x, int y, long long text, int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE void setTextColor(int color);
	DECLARE inline void resetTextColor();

	DECLARE void setBackgroundColor(int color);
	DECLARE inline void resetBackGroundColor();

	DECLARE void setWindowPos(COORD pos, bool onTop = false);
	DECLARE inline void setWindowPos(int x, int y, bool onTop = false);

	DECLARE void setConsoleSize(int width, int height);

	DECLARE void setConsoleBufferSize(int width, int height);

	DECLARE void drawCharLine(COORD first, COORD second, char c = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);
	DECLARE inline void drawCharLine(int firstX, int firstY, int secondX, int secondY, char c = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE void drawCharHollowRect(COORD first, COORD second, char c = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE void drawCharFilledRect(COORD first, COORD second, char c = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE void drawCharTitledRect(COORD first, COORD second, char* text, char rectChar = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR, int rectTextColor = -1, int rectBackgroundColor = -1);

	DECLARE inline void drawCharFrame(char rectChar = '*', int rectTextColor = DEFAULT_FOREGROUND_COLOR, int rectBackgroundColor = DEFAULT_BACKGROUND_COLOR);

	DECLARE inline void drawCharFrameTitled(char* text, char rectChar = '*', int textColor = DEFAULT_FOREGROUND_COLOR, int backgroundColor = DEFAULT_BACKGROUND_COLOR, int rectTextColor = -1, int rectBackgroundColor = -1);

	DECLARE void setCursorVisibility(bool flag);

	DECLARE void setFontSize(int size);

	DECLARE inline void resetFontSize();



	DECLARE int getFontSize();

	DECLARE COORD getCursorPosition();

	DECLARE unsigned int getCurrentTextColor();

	DECLARE unsigned int getCurrentBackgroundColor();

	DECLARE COORD getWindowPos();

	DECLARE COORD getWindowSize();

	DECLARE COORD getWindowSizeChar();

	DECLARE COORD getConsoleBufferSize();

	DECLARE unsigned int getTextColor(COORD pos);
	DECLARE inline unsigned int getTextColor(int x, int y);

	DECLARE unsigned int getBackgroundColor(COORD pos);
	DECLARE inline unsigned int getBackgroundColor(int x, int y);

	DECLARE	char getConsoleChar(COORD pos);
	DECLARE inline char getConsoleChar(int x, int y);

	DECLARE char* getRangeConsoleChar(COORD pos, int width, int height);
	DECLARE inline char* getRangeConsoleChar(int x, int y, int width, int height);
	DECLARE inline char * getRangeConsoleChar(COORD first, COORD second);
}

#endif