#pragma once
#include <Windows.h>

class textCustomizer
{
public:
	textCustomizer();
	~textCustomizer();
	static void disableCursor() {
		CONSOLE_CURSOR_INFO inf;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inf);
		inf.bVisible = FALSE;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inf);
	};
	static void textcolor(int color){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	static void gotoxy(int x, int y) {
		COORD coord;
		coord.X = x-1;
		coord.Y = y-1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

};

