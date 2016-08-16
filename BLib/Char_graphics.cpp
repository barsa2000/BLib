#include "Char_graphics.h"

namespace non_public_Cg
{
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const HWND hwnd = GetConsoleWindow();

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	CONSOLE_FONT_INFOEX cfi = { sizeof(CONSOLE_FONT_INFOEX) };
	CHAR_INFO* ci = new CHAR_INFO[1];
	CONSOLE_CURSOR_INFO cci;
}

inline void BCGraphics::gotoXY(int x, int y)
{
	SetConsoleCursorPosition(non_public_Cg::hOut, { (short)x, (short)y });
}

inline void BCGraphics::gotoXY(COORD pos)
{
	SetConsoleCursorPosition(non_public_Cg::hOut, { pos.X, pos.Y });
}

void BCGraphics::writetoXY(COORD pos, char text, int textColor, int backgroundColor)
{
	if ((pos.X == TEXT_CENTERED_X || pos.X >= 0) || (pos.Y == TEXT_CENTERED_Y || pos.Y >= 0) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 15))
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		if (pos.X == TEXT_CENTERED_X)
			pos.X = (non_public_Cg::csbi.srWindow.Right + 1) / 2;

		if (pos.Y == TEXT_CENTERED_Y)
			pos.Y = (non_public_Cg::csbi.srWindow.Bottom + 1) / 2;

		SetConsoleCursorPosition(non_public_Cg::hOut, pos);

		SetConsoleTextAttribute(non_public_Cg::hOut, backgroundColor << 4 | textColor | (non_public_Cg::csbi.wAttributes >> 8 << 8));
		std::cout << text;

		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
	}
}

void BCGraphics::writetoXY(COORD pos, char* text, int textColor, int backgroundColor)
{
	if ((pos.X == TEXT_CENTERED_X || pos.X >= 0) || (pos.Y == TEXT_CENTERED_Y || pos.Y >= 0) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 15))
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		if (pos.X == TEXT_CENTERED_X)
			pos.X = (non_public_Cg::csbi.srWindow.Right + 1) / 2 - (short)strlen(text) / 2;

		if (pos.Y == TEXT_CENTERED_Y)
			pos.Y = (non_public_Cg::csbi.srWindow.Bottom + 1) / 2;

		SetConsoleCursorPosition(non_public_Cg::hOut, pos);

		SetConsoleTextAttribute(non_public_Cg::hOut, backgroundColor << 4 | textColor | (non_public_Cg::csbi.wAttributes >> 8 << 8));
		std::cout << text;

		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
	}
}

void BCGraphics::writetoXY(COORD pos, double text, int textColor, int backgroundColor)
{
	if ((pos.X == TEXT_CENTERED_X || pos.X >= 0) || (pos.Y == TEXT_CENTERED_Y || pos.Y >= 0) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 15))
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		if (pos.X == TEXT_CENTERED_X)
		{
			std::stringstream ss; ss << text;

			pos.X = (non_public_Cg::csbi.srWindow.Right + 1) / 2 - (short)strlen(ss.str().c_str()) / 2;
		}
		if (pos.Y == TEXT_CENTERED_Y)
			pos.Y = (non_public_Cg::csbi.srWindow.Bottom + 1) / 2;

		SetConsoleCursorPosition(non_public_Cg::hOut, pos);

		SetConsoleTextAttribute(non_public_Cg::hOut, backgroundColor << 4 | textColor | (non_public_Cg::csbi.wAttributes >> 8 << 8));
		std::cout << text;

		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
	}
}

void BCGraphics::writetoXY(COORD pos, long long text, int textColor, int backgroundColor)
{
	if ((pos.X == TEXT_CENTERED_X || pos.X >= 0) || (pos.Y == TEXT_CENTERED_Y || pos.Y >= 0) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 15))
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		if (pos.X == TEXT_CENTERED_X)
		{
			std::stringstream ss; ss << text;

			pos.X = (non_public_Cg::csbi.srWindow.Right + 1) / 2 - (short)strlen(ss.str().c_str()) / 2;
		}
		if (pos.Y == TEXT_CENTERED_Y)
			pos.Y = (non_public_Cg::csbi.srWindow.Bottom + 1) / 2;

		SetConsoleCursorPosition(non_public_Cg::hOut, pos);

		SetConsoleTextAttribute(non_public_Cg::hOut, backgroundColor << 4 | textColor | (non_public_Cg::csbi.wAttributes >> 8 << 8));
		std::cout << text;

		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
	}
}

inline void BCGraphics::writetoXY(int x, int y, char text, int textColor, int backgroundColor)
{
	return writetoXY({ (short)x,(short)y }, text, textColor, backgroundColor);
}

inline void BCGraphics::writetoXY(int x, int y, char* text, int textColor, int backgroundColor)
{
	writetoXY({ (short)x,(short)y }, text, textColor, backgroundColor);
}

inline void BCGraphics::writetoXY(int x, int y, double text, int textColor, int backgroundColor)
{
	writetoXY({ (short)x,(short)y }, text, textColor, backgroundColor);
}

inline void BCGraphics::writetoXY(int x, int y, long long text, int textColor, int backgroundColor)
{
	writetoXY({ (short)x,(short)y }, text, textColor, backgroundColor);
}

void BCGraphics::setTextColor(int color)
{
	if (color >= 0 && color <= 15)
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
		SetConsoleTextAttribute(non_public_Cg::hOut, (non_public_Cg::csbi.wAttributes >> 4 << 4) | color);
	}
}

void BCGraphics::resetTextColor()
{
	setTextColor(DEFAULT_FOREGROUND_COLOR);
}


void BCGraphics::setBackgroundColor(int color)
{

	if (color >= 0 && color <= 15)
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
		SetConsoleTextAttribute(non_public_Cg::hOut, (non_public_Cg::csbi.wAttributes >> 8 << 8) | (color << 4) | (non_public_Cg::csbi.wAttributes - (non_public_Cg::csbi.wAttributes >> 4 << 4)));
	}
}

void BCGraphics::resetBackGroundColor()
{
	setBackgroundColor(DEFAULT_BACKGROUND_COLOR);
}

void BCGraphics::setWindowPos(COORD pos, bool onTop)
{
	if ((pos.X >= 0 && pos.X <= GetSystemMetrics(SM_CXSCREEN) || pos.X == WINDOW_POS_CENTERED_X) && (pos.Y >= 0 && pos.Y <= GetSystemMetrics(SM_CYSCREEN) || pos.Y == WINDOW_POS_CENTERED_Y))
	{
		if (pos.X == WINDOW_POS_CENTERED_X || pos.Y == WINDOW_POS_CENTERED_Y)
		{
			GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
			GetCurrentConsoleFontEx(non_public_Cg::hOut, 0, &non_public_Cg::cfi);

			if (pos.X == WINDOW_POS_CENTERED_X)
				pos.X = (GetSystemMetrics(SM_CXSCREEN) - 1) / 2 - (non_public_Cg::csbi.srWindow.Right + 1) * non_public_Cg::cfi.dwFontSize.X / 2;
			if (pos.Y WINDOW_POS_CENTERED_Y)
				pos.Y = (GetSystemMetrics(SM_CYSCREEN) - 1) / 2 - (non_public_Cg::csbi.srWindow.Bottom + 1) * non_public_Cg::cfi.dwFontSize.Y / 2;
		}
		SetWindowPos(GetConsoleWindow(), (onTop) ? HWND_TOPMOST : 0, pos.X, pos.Y, 0, 0, SWP_NOSIZE);
	}
}

inline void BCGraphics::setWindowPos(int x, int y, bool onTop)
{
	setWindowPos({ (short)x,(short)y }, onTop);
}

void BCGraphics::setConsoleSize(int width, int height)
{
	if (width > 0 && height > 0)
	{
		SetConsoleScreenBufferSize(non_public_Cg::hOut, { (short)width, (short)height });
		SetConsoleWindowInfo(non_public_Cg::hOut, 1, new SMALL_RECT{ 0, 0,(short)width - 1, (short)height - 1 });
	}
}

void BCGraphics::setConsoleBufferSize(int width, int height)
{
	if (width != 0 && height != 0)
		SetConsoleScreenBufferSize(non_public_Cg::hOut, { (short)width, (short)height });
}

void BCGraphics::drawCharLine(COORD first, COORD second, char c, int textColor, int backgroundColor)
{
	if (first.X == second.X || first.Y == second.Y)
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		SetConsoleTextAttribute(non_public_Cg::hOut, (non_public_Cg::csbi.wAttributes >> 8 << 8) | backgroundColor << 4 | textColor);
		SetConsoleCursorPosition(non_public_Cg::hOut, first);
		if (first.X == second.X && first.Y == second.Y)
			std::cout << c;
		else if (first.X == second.X)
		{
			if (first.Y < second.Y)
				for (first.Y; first.Y <= second.Y; first.Y++)
					std::cout << c;
			else if (first.Y > second.Y)
				for (first.Y; first.Y >= second.Y; first.Y--)
					std::cout << c;
		}
		else if (first.Y == second.Y)
		{
			if (first.X < second.X)
				for (first.X; first.X <= second.X; first.X++)
					std::cout << c;
			else if (first.X > second.X)
				for (first.X; first.X >= second.X; first.X--)
					std::cout << c;
		}
		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
	}
}

void BCGraphics::drawCharLine(int firstX, int firstY, int secondX, int secondY, char c, int textColor, int backgroundColor)
{
	drawCharLine({ (short)firstX, (short)firstY }, { (short)secondX, (short)secondY }, c, textColor, backgroundColor);
}

void BCGraphics::drawCharHollowRect(COORD first, COORD second, char c, int textColor, int backgroundColor)
{
	if ((first.X == second.X || first.Y == second.Y) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 10))
	{
		drawCharLine(first, { second.X,first.Y }, c, textColor, backgroundColor);
		drawCharLine({ second.X,first.Y }, second, c, textColor, backgroundColor);
		drawCharLine(second, { first.X,second.Y }, c, textColor, backgroundColor);
		drawCharLine({ first.X,second.Y }, first, c, textColor, backgroundColor);
	}
}

void BCGraphics::drawCharFilledRect(COORD first, COORD second, char c, int textColor, int backgroundColor)
{
	if ((first.X != second.X && first.Y != second.Y) && (textColor >= 0 && textColor <= 15) && (backgroundColor >= 0 && backgroundColor <= 10))
	{
		if (first.Y < second.Y)
			for (first.Y; first.Y <= second.Y; first.Y++)
				drawCharLine(first, { second.X, first.Y }, c, textColor, backgroundColor);
		else
			for (first.Y; first.Y >= second.Y; first.Y--)
				drawCharLine(first, { second.X, first.Y }, c, textColor, backgroundColor);
	}
}

void BCGraphics::drawCharTitledRect(COORD first, COORD second, char * text, char rectChar, int textColor, int backgroundColor, int rectTextColor, int rectBackgroundColor)
{
	if (std::abs(second.X - first.X) - 4 >= (int)strlen(text))
	{
		GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);

		if (rectBackgroundColor == -1)
			rectBackgroundColor = backgroundColor;
		if (rectTextColor == -1)
			rectTextColor = textColor;
		drawCharHollowRect(first, second, rectChar, rectTextColor, rectBackgroundColor);

		SetConsoleTextAttribute(non_public_Cg::hOut, (non_public_Cg::hOut, non_public_Cg::csbi.wAttributes >> 8 << 8) | backgroundColor << 4 | textColor);
		if (second.X > first.X)
			SetConsoleCursorPosition(non_public_Cg::hOut, { (short)(first.X + ((second.X - first.X) / 2 - (strlen(text) + 1) / 2)), first.Y });
		else
			SetConsoleCursorPosition(non_public_Cg::hOut, { (short)(second.X + ((first.X - second.X) / 2 - (strlen(text) + 1) / 2)), second.Y });
		std::cout << " " << text << " ";

		SetConsoleCursorPosition(non_public_Cg::hOut, non_public_Cg::csbi.dwCursorPosition);
		SetConsoleTextAttribute(non_public_Cg::hOut, non_public_Cg::csbi.wAttributes);
	}
}

inline void BCGraphics::drawCharFrame(char rectChar, int rectTextColor, int rectBackgroundColor)
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	drawCharHollowRect({ 0,0 }, { non_public_Cg::csbi.srWindow.Right, non_public_Cg::csbi.srWindow.Bottom }, rectChar, rectTextColor, rectBackgroundColor);

}

inline void BCGraphics::drawCharFrameTitled(char * text, char rectChar, int textColor, int backgroundColor, int rectTextColor, int rectBackgroundColor)
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return drawCharTitledRect({ 0,0 }, { non_public_Cg::csbi.srWindow.Right, non_public_Cg::csbi.srWindow.Bottom }, text, rectChar, textColor, backgroundColor, rectTextColor, rectBackgroundColor);

}

void BCGraphics::setCursorVisibility(bool flag)
{
	GetConsoleCursorInfo(non_public_Cg::hOut, &non_public_Cg::cci);
	non_public_Cg::cci.bVisible = flag;
	SetConsoleCursorInfo(non_public_Cg::hOut, &non_public_Cg::cci);
}

void BCGraphics::setFontSize(int size)
{
	if (size > 0)
	{
		GetCurrentConsoleFontEx(non_public_Cg::hOut, 0, &non_public_Cg::cfi);
		non_public_Cg::cfi.dwFontSize.Y = size;
		SetCurrentConsoleFontEx(non_public_Cg::hOut, 0, &non_public_Cg::cfi);
	}
}

inline void BCGraphics::resetFontSize()
{
	setFontSize(DEFAULT_FONT_SIZE);
}

int BCGraphics::getFontSize()
{
	GetCurrentConsoleFontEx(non_public_Cg::hOut, 0, &non_public_Cg::cfi);
	return non_public_Cg::cfi.dwFontSize.Y;
}

COORD BCGraphics::getCursorPosition()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return non_public_Cg::csbi.dwCursorPosition;
}

unsigned int BCGraphics::getCurrentTextColor()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return non_public_Cg::csbi.wAttributes - (non_public_Cg::csbi.wAttributes >> 4 << 4);
}

unsigned int BCGraphics::getCurrentBackgroundColor()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return (non_public_Cg::csbi.wAttributes - (non_public_Cg::csbi.wAttributes >> 8 << 8)) >> 4;
}

COORD BCGraphics::getWindowPos()
{
	RECT window;
	GetWindowRect(GetConsoleWindow(), &window);
	return{ (short)window.left , (short)window.top };
}

COORD BCGraphics::getWindowSize()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	GetCurrentConsoleFontEx(non_public_Cg::hOut, 0, &non_public_Cg::cfi);
	return{ (non_public_Cg::csbi.srWindow.Right + 1) * non_public_Cg::cfi.dwFontSize.X, (non_public_Cg::csbi.srWindow.Bottom + 1) * non_public_Cg::cfi.dwFontSize.Y };
}

COORD BCGraphics::getWindowSizeChar()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return{ non_public_Cg::csbi.srWindow.Right + 1, non_public_Cg::csbi.srWindow.Bottom + 1 };
}

COORD BCGraphics::getConsoleBufferSize()
{
	GetConsoleScreenBufferInfo(non_public_Cg::hOut, &non_public_Cg::csbi);
	return non_public_Cg::csbi.dwSize;
}

unsigned int BCGraphics::getTextColor(COORD pos)
{
	ReadConsoleOutput(non_public_Cg::hOut, non_public_Cg::ci, { 1,1 }, { 0,0 }, new SMALL_RECT{ pos.X, pos.Y, pos.X, pos.Y });
	return non_public_Cg::ci[0].Attributes - (non_public_Cg::ci[0].Attributes >> 4 << 4);
}

inline unsigned int BCGraphics::getTextColor(int x, int y)
{
	return getTextColor({ (short)x, (short)y });
}

unsigned int BCGraphics::getBackgroundColor(COORD pos)
{
	ReadConsoleOutput(non_public_Cg::hOut, non_public_Cg::ci, { 1,1 }, { 0,0 }, new SMALL_RECT{ pos.X, pos.Y, pos.X, pos.Y });
	return (non_public_Cg::ci[0].Attributes - (non_public_Cg::ci[0].Attributes >> 8 << 8)) >> 4;
}

unsigned int BCGraphics::getBackgroundColor(int x, int y)
{
	return getBackgroundColor({ (short)x, (short)y });
}

char BCGraphics::getConsoleChar(COORD pos)
{
	ReadConsoleOutput(non_public_Cg::hOut, non_public_Cg::ci, { 1,1 }, { 0,0 }, new SMALL_RECT{ pos.X, pos.Y, pos.X, pos.Y });

	return non_public_Cg::ci[0].Char.AsciiChar;
}

inline char BCGraphics::getConsoleChar(int x, int y)
{
	return getConsoleChar({ (short)x, (short)y });
}

char * BCGraphics::getRangeConsoleChar(COORD pos, int width, int height)
{
	delete non_public_Cg::ci;
	non_public_Cg::ci = new CHAR_INFO[height * width];
	char* chars = new char[height * width]{ 0 };

	ReadConsoleOutput(non_public_Cg::hOut, non_public_Cg::ci, { (short)width,(short)height }, { 0,0 }, new SMALL_RECT{ pos.X, pos.Y, pos.X + (short)width - 1, pos.Y + (short)height - 1 });

	for (int i = 0; i < height*width - 1; i++)
		chars[i] = non_public_Cg::ci[i].Char.AsciiChar;

	delete non_public_Cg::ci;
	non_public_Cg::ci = new CHAR_INFO[1];

	return chars;
}

char * BCGraphics::getRangeConsoleChar(int x, int y, int width, int height)
{
	return getRangeConsoleChar({ (short)x,(short)y }, width, height);
}

char * BCGraphics::getRangeConsoleChar(COORD first, COORD second)
{
	return getRangeConsoleChar({ first.X,first.Y }, second.X - first.X, second.Y - first.Y);
}
