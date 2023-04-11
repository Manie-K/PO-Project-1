#include "Logger.h"

Logger::Logger(const int x, const int y, InputManager& in):startX(x),startY(y),added(false),input(in)
{
	logs.clear();
}

Logger::~Logger(){logs.clear();}

void Logger::display()
{
	textMenu();
	if(!added)
		addLog({ "                                  ",EMPTY });
	auto it = logs.begin();
	int i = 0;
	textbackground(WHITE);
	while (i < max_messages && it != logs.end()) {
		gotoxy(startX, startY + i);
		switch (logs.at(i).type)
		{
		case EMPTY:
			textcolor(WHITE);
			break;
		case INFO:
			textcolor(LIGHTBLUE);
			break;
		case KILL:
			textcolor(RED);
			break;
		case BIRTH:
			textcolor(LIGHTGREEN);
			break;
		case SOW:
			textcolor(GREEN);
			break;
		case EAT:
			textcolor(MAGENTA);
			break;
		case POISON:
			textcolor(YELLOW);
			break;
		default:
			textcolor(BLACK);
			break;
		}
		cout << logs.at(i).mess;
		i++;
		it++;
	}
	textcolor(WHITE);
	textbackground(BLACK);
	added = false;
}

void Logger::textMenu() const
{
	const int x = MAP_START_X + MAP_W + 3;
	const int y = MAP_START_Y;

	int i = y;
	gotoxy(x, i++);
	cout << "MACIEJ GÓRALCZYK 193302";
	gotoxy(x, i++);
	cout << "LEGENDA:";
	gotoxy(x, i++);

	gotoxy(x, i++);
	gotoxy(x, i++);
	gotoxy(x, i++);
	cout << "Special ability (turns left) - " << input.getAbility();
	gotoxy(x, i++);
	cout << "Special ability (cooldown) - " << input.getAbilityCooldown();

}

void Logger::addLog(const LogString& log)
{
	added = true;
	logs.push_front(log);
	if (logs.size() > max_messages)
		logs.pop_back();
}