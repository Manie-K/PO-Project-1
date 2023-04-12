#define _CRT_SECURE_NO_WARNINGS
#include "Simulator.h"

Simulator::Simulator()
{
	srand(time(NULL));
	manager = new InputManager;
	logger = new Logger(1,MAP_START_Y+MAP_H+LOG_POS_OFFSET,*manager);
	world = new World(MAP_W, MAP_H, *logger);
	setUpWorld();
}
Simulator::~Simulator()
{
	delete world;
	world = nullptr;
	delete logger;
	logger = nullptr;
	delete manager;
	manager = nullptr;
}

void Simulator::run()
{
	textCustomizer::disableCursor();
	world->drawWorld();
	logger->display();
	while (!manager->getQuit())
	{
		manager->input();
		if (manager->getArrowKey())
		{
			world->simulateTurn();
			world->drawWorld();
			manager->nextTurn();
			logger->display();
		}
		else if (manager->getLoad())
		{
			load();
		}
		else if (manager->getSave())
		{
			save();
		}
	}
}

void Simulator::setUpWorld()
{
	Human* human = new Human(*world, *logger,*manager, { 1, 5});
	Fox* f1 = new Fox(*world, *logger, { 6, 7 });
	Dandelion* d1 = new Dandelion(*world, *logger, { 15, 7 });
	Grass* g1 = new Grass(*world, *logger, { 3, 5 });
	Guarana* gu1 = new Guarana(*world, *logger, {6, 2 });
	WolfBerries* w1 = new WolfBerries(*world, *logger, { 7, 0 });
	GiantHogweed* h1 = new GiantHogweed(*world, *logger, { 5, 1 });
}

void Simulator::save()
{
	system("cls");
	textCustomizer::textcolor(LIGHTGREEN);
	cout << "Wprowadz nazwe pliku zapisu: ";
	string fName;
	cin >> fName;
	FILE* file = fopen(fName.c_str(), "w");
	try {
		if (file) {
			fwrite(manager, sizeof(manager), 1, file);
			fwrite(logger, sizeof(logger), 1, file);
			fwrite(world, sizeof(world), 1, file);
			fclose(file);
		}
		else
			throw runtime_error("Nie udalo sie zapisac do pliku\n");
	}
	catch (const exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	textCustomizer::textcolor(WHITE);
	logger->addLog({ "Pomyslnie zapisano do pliku", INFO });
	world->drawWorld();
	logger->display();
}

void Simulator::load()
{
	system("cls");
	textCustomizer::gotoxy(1, 1);
	textCustomizer::textcolor(LIGHTGREEN);
	cout << "Podaj nazwe pliku zapisu: ";
	string fName;
	cin >> fName;

	FILE* file = fopen(fName.c_str(), "r");
	try {
		delete world;
		delete logger;
		delete manager;
		if (file) {
			fread(manager, sizeof(manager), 1, file);
			fread(logger, sizeof(logger), 1, file);
			fread(world, sizeof(world), 1, file);
			fclose(file);
			textCustomizer::textcolor(WHITE);
			logger->addLog({ "Pomyslnie wczytano swiat",INFO });
			world->drawWorld();
			logger->display();
		}
		else
			throw runtime_error("Nie udalo sie wczytac z pliku\n");
	}
	catch (const exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}