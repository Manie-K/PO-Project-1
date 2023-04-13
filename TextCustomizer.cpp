#include "TextCustomizer.h"

textCustomizer::textCustomizer(){}
textCustomizer::~textCustomizer(){}
void textCustomizer::disableCursor() {
	CONSOLE_CURSOR_INFO inf;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inf);
	inf.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inf);
};
void textCustomizer::textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void textCustomizer::gotoxy(int x, int y) {
	COORD coord;
	coord.X = x - 1;
	coord.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

