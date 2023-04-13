#define _CRT_SECURE_NO_WARNINGS
#include "Simulator.h"

void Simulator::setUpWorld()
{
	Human* human = new Human(*world, *logger,*manager, { 0,1});
	Fox* f1 = new Fox(*world, *logger, { 0, 0 });	
}


Simulator::Simulator()
{
	srand(time(NULL));
	manager = new InputManager;
	logger = new Logger(1,MAP_START_Y+MAP_H+LOG_POS_OFFSET,*manager);
	world = new World(MAP_W, MAP_H);
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


void Simulator::save()
{
	system("cls");
	textCustomizer::textcolor(LIGHTGREEN);
	cout << "Wprowadz nazwe pliku zapisu: ";
	string fName;
	cin >> fName;

	fstream file;
	file.open(fName.c_str(), ios::out);
	try {
		if (file.good()) {
			manager->saveFile(file);
			world->saveFile(file);
			file.close();
			textCustomizer::textcolor(WHITE);
			logger->addLog({ "Pomyslnie zapisano do pliku", INFO });
			world->drawWorld();
			logger->display();
		}
		else
			throw runtime_error("Nie udalo sie zapisac do pliku\n");
	}
	catch (const exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
}

void Simulator::load()
{
	system("cls");
	textCustomizer::gotoxy(1, 1);
	textCustomizer::textcolor(LIGHTGREEN);
	cout << "Podaj nazwe pliku zapisu: ";
	string fName;
	cin >> fName;

	fstream file;
	file.open(fName.c_str(), ios::in);
	try {
		delete world;
		delete logger;
		delete manager;
		if (file.good()) {
			manager = InputManager::loadFile(file);
			logger = new Logger(1, MAP_START_Y + MAP_H + LOG_POS_OFFSET,*manager);
			world = World::loadFile(file,*logger,*manager);
			file.close();
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