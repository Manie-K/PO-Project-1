#include "Logger.h"

Logger::Logger(const int x, const int y, InputManager& in):startX(x),startY(y),added(false),input(in)
{
	logs.clear();
}

Logger::Logger(const int x, const int y, InputManager& in, deque<LogString> log, bool add) :startX(x), startY(y), added(add), input(in)
{
	int size = log.size();
	logs.clear();
	for (int i = 0; i < size; i++)
	{
		logs.push_back(logs[i]);
	}
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
		textCustomizer::gotoxy(startX, startY + i);
		switch (logs.at(i).type)
		{
		case EMPTY:
			textCustomizer::textcolor(WHITE);
			break;
		case INFO:
			textCustomizer::textcolor(LIGHTBLUE);
			break;
		case KILL:
			textCustomizer::textcolor(RED);
			break;
		case BIRTH:
			textCustomizer::textcolor(LIGHTGREEN);
			break;
		case SOW:
			textCustomizer::textcolor(GREEN);
			break;
		case EAT:
			textCustomizer::textcolor(MAGENTA);
			break;
		case POISON:
			textCustomizer::textcolor(YELLOW);
			break;
		default:
			textCustomizer::textcolor(BLACK);
			break;
		}
		cout << logs.at(i).mess;
		i++;
		it++;
	}
	textCustomizer::textcolor(WHITE);
	added = false;
}

void Logger::textMenu() const
{
	const int x = MAP_START_X + MAP_W + 30;
	const int y = MAP_START_Y;

	int i = y;
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(LIGHTGREEN);
	cout << "MACIEJ GORALCZYK 193302";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(MAGENTA);
	cout << "Legenda (pl):";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(CYAN);
	cout << ABILITY_KEY << " - Umiejetnosc specjalna czlowieka";
	textCustomizer::gotoxy(x, i++);
	cout << END_SIMULATION_KEY << " - Zakoncz symulacje";
	textCustomizer::gotoxy(x, i++);
	cout << SAVE_KEY << " - Zapisz";
	textCustomizer::gotoxy(x, i++);
	cout << LOAD_KEY << " - Wczytaj";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(BROWN);
	cout << "Umiejetnosc specjalna (pozostalo tur) : " << input.getAbility();
	textCustomizer::gotoxy(x, i++);
	cout << "Umiejetnosc specjalna (cooldown) : " << input.getAbilityCooldown();
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(DARKGRAY);
	cout << "Postacie:";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(YELLOW);
	cout << HUMAN_CHAR << " - Czlowiek";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(RED);
	cout << WOLF_CHAR << " - Wilk";
	textCustomizer::gotoxy(x, i++);
	cout << SHEEP_CHAR << " - Owca";
	textCustomizer::gotoxy(x, i++);
	cout << FOX_CHAR << " - Lis";
	textCustomizer::gotoxy(x, i++);
	cout << TURTLE_CHAR << " - Zolw";
	textCustomizer::gotoxy(x, i++);
	cout << ANTELOPE_CHAR << " - Antyloopa";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(GREEN);
	cout << GRASS_CHAR << " - Trawa";
	textCustomizer::gotoxy(x, i++);
	cout << DANDELION_CHAR << " - Mlecz";
	textCustomizer::gotoxy(x, i++);
	cout << GUARANA_CHAR << " - Guarana";
	textCustomizer::gotoxy(x, i++);
	cout << WOLF_BERRIES_CHAR << " - Wilcze Jagody";
	textCustomizer::gotoxy(x, i++);
	cout << GIANT_HOGWEED_CHAR << " - Barszcz Sosnowskiego";
	textCustomizer::gotoxy(x, i++);
	textCustomizer::textcolor(WHITE);
}

void Logger::addLog(const LogString& log)
{
	added = true;
	logs.push_front(log);
	if (logs.size() > max_messages)
		logs.pop_back();
}

void Logger::saveFile(FILE* f)
{
	fwrite(&startX, sizeof(int), 1, f);
	fwrite(&startY, sizeof(int), 1, f);
	fwrite(&added, sizeof(bool), 1, f);
	int size = logs.size();
	fwrite(&size, sizeof(int), 1, f);
	for (auto i : logs) {
		fwrite(&i, sizeof(LogString), 1, f); // write each element of the deque to the file
	}
}
Logger* Logger::loadFile(FILE* f, InputManager& in)
{
	deque<LogString> logs;
	int startX, startY;
	bool added;
	int size;
	fread(&startX, sizeof(int), 1, f);
	fread(&startY, sizeof(int), 1, f);
	fread(&added, sizeof(bool), 1, f);
	fread(&size, sizeof(size_t), 1, f); // read the size of the deque from the file

	for (int i = 0; i < size; i++) {
		LogString elem;
		fread(&elem, sizeof(LogString), 1, f); // read each element of the deque from the file
		logs.push_back(elem);
	}

	return new Logger(startX, startY, in, logs, added);
}