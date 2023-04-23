#pragma once
#include <Windows.h>

class textCustomizer
{
private:
	textCustomizer();
public:
	virtual ~textCustomizer() = 0;
	static void disableCursor();
	static void textcolor(int color);
	static void gotoxy(int x, int y);
};

