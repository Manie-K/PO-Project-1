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
	while (i < max_messages && it != logs.end()) {
		custom.gotoxy(startX, startY + i);
		switch (logs.at(i).type)
		{
		case EMPTY:
			custom.textcolor(WHITE);
			break;
		case INFO:
			custom.textcolor(LIGHTBLUE);
			break;
		case KILL:
			custom.textcolor(RED);
			break;
		case BIRTH:
			custom.textcolor(LIGHTGREEN);
			break;
		case SOW:
			custom.textcolor(GREEN);
			break;
		case EAT:
			custom.textcolor(MAGENTA);
			break;
		case POISON:
			custom.textcolor(YELLOW);
			break;
		default:
			custom.textcolor(BLACK);
			break;
		}
		cout << logs.at(i).mess;
		i++;
		it++;
	}
	custom.textcolor(WHITE);
	added = false;
}

void Logger::textMenu() const
{
	const int x = MAP_START_X + MAP_W + 30;
	const int y = MAP_START_Y;

	int i = y;
	custom.gotoxy(x, i++);
	custom.textcolor(LIGHTGREEN);
	cout << "MACIEJ GORALCZYK 193302";
	custom.gotoxy(x, i++);
	custom.textcolor(MAGENTA);
	cout << "Legenda (pl):";
	custom.gotoxy(x, i++);
	custom.textcolor(CYAN);
	cout << ABILITY_KEY << " - Umiejetnosc specjalna czlowieka";
	custom.gotoxy(x, i++);
	cout << END_SIMULATION_KEY << " - Zakoncz symulacje";
	custom.gotoxy(x, i++);
	custom.textcolor(BROWN);
	cout << "Umiejetnosc specjalna (pozostalo tur) : " << input.getAbility();
	custom.gotoxy(x, i++);
	cout << "Umiejetnosc specjalna (cooldown) : " << input.getAbilityCooldown();
	custom.gotoxy(x, i++);
	custom.textcolor(DARKGRAY);
	cout << "Postacie:";
	custom.gotoxy(x, i++);
	custom.textcolor(YELLOW);
	cout << HUMAN_CHAR << " - Czlowiek";
	custom.gotoxy(x, i++);
	custom.textcolor(RED);
	cout << WOLF_CHAR << " - Wilk";
	custom.gotoxy(x, i++);
	cout << SHEEP_CHAR << " - Owca";
	custom.gotoxy(x, i++);
	cout << FOX_CHAR << " - Lis";
	custom.gotoxy(x, i++);
	cout << TURTLE_CHAR << " - Zolw";
	custom.gotoxy(x, i++);
	cout << ANTELOPE_CHAR << " - Antyloopa";
	custom.gotoxy(x, i++);
	custom.textcolor(GREEN);
	cout << GRASS_CHAR << " - Trawa";
	custom.gotoxy(x, i++);
	cout << DANDELION_CHAR << " - Mlecz";
	custom.gotoxy(x, i++);
	cout << GUARANA_CHAR << " - Guarana";
	custom.gotoxy(x, i++);
	cout << WOLF_BERRIES_CHAR << " - Wilcze Jagody";
	custom.gotoxy(x, i++);
	cout << GIANT_HOGWEED_CHAR << " - Barszcz Sosnowskiego";
	custom.gotoxy(x, i++);
	custom.textcolor(WHITE);
}

void Logger::addLog(const LogString& log)
{
	added = true;
	logs.push_front(log);
	if (logs.size() > max_messages)
		logs.pop_back();
}