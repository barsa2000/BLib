#include "Utility.h"

namespace non_public_U
{
	const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	const HWND hwnd = GetConsoleWindow();

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	CONSOLE_CURSOR_INFO cci;
	INPUT input = { 0 };
	time_t now;
}

inline void BUtils::sleepMilliS(long milliseconds)
{
	Sleep(milliseconds);
}

inline void BUtils::sleepSec(long seconds)
{
	Sleep(seconds * 1000);
}

inline void BUtils::sleepMin(long minutes)
{
	Sleep(minutes * 60000);
}

inline void BUtils::sleepHour(long hours)
{
	Sleep(hours * 3600000);
}

int BUtils::getCurrentYear()
{
	non_public_U::now = time(0);
	return 1900 + localtime(&non_public_U::now)->tm_year;
}

int BUtils::getCurrentMonth()
{

	non_public_U::now = time(0);
	return 1 + localtime(&non_public_U::now)->tm_mon;
}

int BUtils::getCurrentDay()
{
	non_public_U::now = time(0);
	return localtime(&non_public_U::now)->tm_mday;
}

int BUtils::getCurrentHour()
{
	non_public_U::now = time(0);
	if (localtime(&non_public_U::now)->tm_isdst == 0)
		return 1 + localtime(&non_public_U::now)->tm_hour;
	else
		if (localtime(&non_public_U::now)->tm_hour == 0)
			return 24;
		else
			return localtime(&non_public_U::now)->tm_hour;
}

int BUtils::getCurrentMinute()
{
	non_public_U::now = time(0);
	return 1 + localtime(&non_public_U::now)->tm_min;
}

int BUtils::getCurrentSecond()
{
	non_public_U::now = time(0);
	return 1 + localtime(&non_public_U::now)->tm_sec;
}

void BUtils::setMousePosition(COORD pos)
{
#pragma warning(push)
#pragma warning(disable : 4244)
	ZeroMemory(&non_public_U::input, sizeof(INPUT));
	non_public_U::input.type = INPUT_MOUSE;
	non_public_U::input.mi.dx = pos.X*(65535.0f / (GetSystemMetrics(SM_CXSCREEN) - 1));
	non_public_U::input.mi.dy = pos.Y*(65535.0f / (GetSystemMetrics(SM_CYSCREEN) - 1));
	non_public_U::input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	SendInput(1, &non_public_U::input, sizeof(INPUT));
#pragma warning(pop)
}

inline void BUtils::setMousePosition(int x, int y)
{
	setMousePosition({ (short)x,(short)y });
}

POINT BUtils::getMousePosition()
{
	POINT mousePos;
	GetCursorPos(&mousePos);
	return{ mousePos.x,mousePos.y };
}

void BUtils::mouseClick(BYTE button, COORD pos)
{
	if (button == MOUSE_LEFT_BUTTON || button == MOUSE_RIGHT_BUTTON || button == MOUSE_MIDDLE_BUTTON)
	{
#pragma warning(push)
#pragma warning(disable : 4244)
		POINT prevPos;
		GetCursorPos(&prevPos);

		ZeroMemory(&non_public_U::input, sizeof(INPUT));
		non_public_U::input.type = INPUT_MOUSE;
		non_public_U::input.mi.dx = pos.X*(65535.0f / (GetSystemMetrics(SM_CXSCREEN) - 1));
		non_public_U::input.mi.dy = pos.Y*(65535.0f / (GetSystemMetrics(SM_CYSCREEN) - 1));
		non_public_U::input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
		SendInput(1, &non_public_U::input, sizeof(INPUT));

		ZeroMemory(&non_public_U::input, sizeof(INPUT));
		non_public_U::input.type = INPUT_MOUSE;
		switch (button)
		{
		case 0b0001:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN; break;
		case 0b0010:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN; break;
		case 0b0100:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN; break;
		}
		SendInput(1, &non_public_U::input, sizeof(INPUT));

		ZeroMemory(&non_public_U::input, sizeof(INPUT));
		non_public_U::input.type = INPUT_MOUSE;
		switch (button)
		{
		case 0b0001:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_LEFTUP; break;
		case 0b0010:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_RIGHTUP; break;
		case 0b0100:
			non_public_U::input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP; break;
		}
		SendInput(1, &non_public_U::input, sizeof(INPUT));

		ZeroMemory(&non_public_U::input, sizeof(INPUT));
		non_public_U::input.type = INPUT_MOUSE;
		non_public_U::input.mi.dx = prevPos.x*(65535.0f / (GetSystemMetrics(SM_CXSCREEN) - 1));
		non_public_U::input.mi.dy = prevPos.y*(65535.0f / (GetSystemMetrics(SM_CYSCREEN) - 1));
		non_public_U::input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
		SendInput(1, &non_public_U::input, sizeof(INPUT));
#pragma warning(pop)
	}
}

inline int BUtils::getAsciiKey()
{
	int c = (_kbhit()) ? _getch() : 0;

	return (c == 224 || c == 0) ? 0 : c;
}

inline int BUtils::getSpecialKey()
{
	int c = (_kbhit()) ? _getch() : -1;

	return (c == 224 || c == 0) ? _getch() : 0;
}

bool BUtils::toClipboard(std::string s)
{
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
	if (!hg) 
	{
		CloseClipboard();
		return false;
	}
	memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
	return true;
}

void BUtils::clearClipboard()
{
	OpenClipboard(0);
	EmptyClipboard();
	CloseClipboard();
}

char * BUtils::getClipboard()
{
	if (!OpenClipboard(0))
		return 0;
	HANDLE h = GetClipboardData(CF_TEXT);
	CloseClipboard();
	return (h != nullptr) ? (char*)h : "";
}

void BUtils::Stopwatch::start()
{
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&s);
}

long long BUtils::Stopwatch::getElapsed()
{
	QueryPerformanceCounter(&e);
	return (e.QuadPart - s.QuadPart) * 1000 / frequency.QuadPart;
}

BUtils::Menu::Menu(std::vector<std::string> str, char * rightSideChar, char * leftSideChar, int textColor, int backGroundColor)
{
	for (unsigned int i = 0; i < str.size(); i++)
		addChoose((char*)str[i].c_str());
	setSideChars(rightSideChar, leftSideChar);
	this->textColor = textColor;
	this->backgroundColor = backGroundColor;
}

void BUtils::Menu::addChoose(char * choiceName)
{
	std::stringstream ss;
	if (this->right != 0 && this->left != 0)
		ss << std::string(strlen(left), ' ') << choiceName << std::string(strlen(right), ' ');
	else
		ss << choiceName;
	names.push_back(ss.str());
	if (empty)
		empty = false;
}

void BUtils::Menu::setSideChars(char * left, char * right)
{
	if (!empty)
	{
		for (unsigned int i = 0; i < names.size(); i++)
		{
			if (this->right != 0 && this->left != 0)
			{
				names[i].erase(0, strlen(this->left));
				names[i].erase(names[i].length() - strlen(this->right), strlen(this->right));
			}

			if (i == index)
				names[i] = left + names[i] + right;
			else
				names[i] = std::string(strlen(left), ' ') + names[i] + std::string(strlen(right), ' ');
		}
	}
	free(this->right);
	this->right = (char*)malloc(sizeof(char) * strlen(right) + 1);
	strcpy(this->right, right);

	free(this->left);
	this->left = (char*)malloc(sizeof(char) * strlen(left) + 1);
	strcpy(this->left, left);
}

void BUtils::Menu::setTextColor(int color)
{
	textColor = color;
}

void BUtils::Menu::setBackgroundColor(int color)
{
	backgroundColor = color;
}

void BUtils::Menu::resetChoise()
{
	choice = -1;
	index = 0;
}

void BUtils::Menu::clearChoices()
{
	names.clear();
}

int BUtils::Menu::update()
{
	if (!empty && choice == -1)
	{
		if (_kbhit())
		{
			int k = _getch();
			if (k == 224 || k == 0)
			{
				k = _getch();

				if (k == ARROW_UP)
				{
					if (index != 0)
					{
						index--;

						names[index + 1].erase(0, strlen(left));
						names[index + 1].erase(names[index + 1].length() - strlen(right), strlen(right));

						names[index + 1] = std::string(strlen(left), ' ') + names[index + 1] + std::string(strlen(right), ' ');
					}
					else
					{
						index = names.size() - 1;

						names[0].erase(0, strlen(left));
						names[0].erase(names[0].length() - strlen(right), strlen(right));

						names[0] = std::string(strlen(left), ' ') + names[0] + std::string(strlen(right), ' ');

					}
					names[index].erase(0, strlen(left));
					names[index].erase(names[index].length() - strlen(right), strlen(right));
					names[index] = left + names[index] + right;
					return 1;
				}
				else if (k == ARROW_DOWN)
				{
					if (index != names.size() - 1)
					{
						index++;

						names[index - 1].erase(0, strlen(left));
						names[index - 1].erase(names[index - 1].length() - strlen(right), strlen(right));

						names[index - 1] = std::string(strlen(left), ' ') + names[index - 1] + std::string(strlen(right), ' ');
					}
					else
					{
						index = 0;

						names[names.size() - 1].erase(0, strlen(left));
						names[names.size() - 1].erase(names[names.size() - 1].length() - strlen(right), strlen(right));

						names[names.size() - 1] = std::string(strlen(left), ' ') + names[names.size() - 1] + std::string(strlen(right), ' ');
					}
					names[index].erase(0, strlen(left));
					names[index].erase(names[index].length() - strlen(right), strlen(right));
					names[index] = left + names[index] + right;
					return 1;
				}
			}
			if (k == RETURN)
			{
				choice = index;
				return 1;
			}
		}
	}
	return (choice == -1) ? 0 : 2;
}

void BUtils::Menu::print()
{
	if (!empty)
	{
		GetConsoleCursorInfo(non_public_U::hOut, &non_public_U::cci);
		int cV = non_public_U::cci.bVisible;
		non_public_U::cci.bVisible = false;
		SetConsoleCursorInfo(non_public_U::hOut, &non_public_U::cci);
		GetConsoleScreenBufferInfo(non_public_U::hOut, &non_public_U::csbi);

		for (unsigned int i = 0; i < names.size(); i++)
		{
			SetConsoleCursorPosition(non_public_U::hOut, { (short)std::ceil((float)((non_public_U::csbi.srWindow.Right + 1) / 2) - (float)(strlen(names[i].c_str()) / 2)), (short)((non_public_U::csbi.srWindow.Bottom + 1 - names.size()) / 2 + i) });
			std::cout << names[i].substr(0, strlen(left));
			SetConsoleTextAttribute(non_public_U::hOut, backgroundColor << 4 | textColor | (non_public_U::csbi.wAttributes >> 8 << 8));
			std::cout << names[i].substr(strlen(left), names[i].size() - strlen(left) - strlen(right));
			SetConsoleTextAttribute(non_public_U::hOut, non_public_U::csbi.wAttributes);
			std::cout << names[i].substr(names[i].size() - strlen(right), strlen(right));
		}

		SetConsoleCursorPosition(non_public_U::hOut, non_public_U::csbi.dwCursorPosition);
		non_public_U::cci.bVisible = cV;
		SetConsoleCursorInfo(non_public_U::hOut, &non_public_U::cci);
	}
}

int BUtils::Menu::getChoose()
{
	return choice;
}
