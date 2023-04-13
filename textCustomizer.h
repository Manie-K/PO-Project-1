#pragma once
#include <Windows.h>

class textCustomizer
{
public:
	textCustomizer();
	~textCustomizer();
	static void disableCursor();
	static void textcolor(int color);
	static void gotoxy(int x, int y);
};

