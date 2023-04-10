#include "Logger.h"

Logger::Logger(const int x, const int y):startX(x),startY(y),added(false)
{
	logs.clear();
}

Logger::~Logger(){logs.clear();}

void Logger::display()
{
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

void Logger::addLog(const LogString& log)
{
	added = true;
	logs.push_front(log);
	if (logs.size() > max_messages)
		logs.pop_back();
}