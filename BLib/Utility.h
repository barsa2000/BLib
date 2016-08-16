#ifndef UTILITY
#define UTILITY

#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <conio.h>
#include <time.h>
#include <vector>

#ifndef DECLARE
	#define DECLARE __declspec(dllexport)
#endif

//mouse buttons definition/////////////
//
#define MOUSE_LEFT_BUTTON        0x01
#define MOUSE_RIGHT_BUTTON       0x02
#define MOUSE_MIDDLE_BUTTON      0x04
//
///////////////////////////////////////

//special keys code definition/////////
//
#define CANC                     0x53
#define INS                      0x52
#define END                      0x4F
#define PAG_UP                   0x49
#define PAG_DOWN                 0x51

#define ARROW_UP                 0x48
#define ARROW_DOWN               0x50
#define ARROW_RIGHT              0x4D
#define ARROW_LEFT               0x4B

#define F1                       0x3B
#define F2                       0x3C
#define F3                       0x3D
#define F4                       0x3E
#define F5                       0x3F
#define F6                       0x40
#define F7                       0x41
#define F8                       0x42
#define F9                       0x43
#define F10                      0x43
#define F12                      0x86
//
///////////////////////////////////////

//ascii keys code definition///////////
//
#define RETURN                   0x0D
#define ESC                      0x1B
#define BACKSPACE                0x08
#define SPACE                    0x20
#define TAB                      0x09
//
//the code of the other characters is their ASCII value
///////////////////////////////////////

namespace BUtils
{
	DECLARE inline void sleepMilliS(long milliseconds);

	DECLARE inline void sleepSec(long seconds);

	DECLARE inline void sleepMin(long minutes);

	DECLARE inline void sleepHour(long hours);

	DECLARE inline int getCurrentYear();

	DECLARE inline int getCurrentMonth();

	DECLARE inline int getCurrentDay();

	DECLARE inline int getCurrentHour();

	DECLARE inline int getCurrentMinute();

	DECLARE inline int getCurrentSecond();

	DECLARE void setMousePosition(COORD pos);
	DECLARE inline void setMousePosition(int x, int y);

	DECLARE POINT getMousePosition();

	DECLARE void mouseClick(BYTE button, COORD pos);

	DECLARE inline int getAsciiKey();

	DECLARE inline int getSpecialKey();

	DECLARE bool toClipboard(std::string s);

	DECLARE void clearClipboard();

	DECLARE char* getClipboard();

	class DECLARE Stopwatch
	{
	public:
		void start();
		long long getElapsed();

	private:
		LARGE_INTEGER frequency;
		LARGE_INTEGER s, e;
	};
	
	class DECLARE Menu
	{
	public:
		Menu() {};

		Menu(std::vector<std::string> str, char* rightSideChar = ">", char* leftSideChar = "<", int textColor = 8, int backGroundColor = 0);

		void addChoose(char* choiceName);

		void setSideChars(char* left = ">", char* right = "<");

		void setTextColor(int color = 8);

		void setBackgroundColor(int color = 0);

		void resetChoise();

		void clearChoices();

		int update();

		void print();

		int getChoose();

	private:
#pragma warning(push)
#pragma warning(disable : 4251)
		std::vector<std::string> names;
		int index = 0;
		int choice = -1;
		char* right, *left;
		int textColor = 8, backgroundColor = 0;
		bool empty = true;
#pragma warning(pop)

	};


}

#endif
