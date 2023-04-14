#define _CRT_SECURE_NO_WARNINGS
#include "Simulator.h"

void Simulator::setUpWorld()
{
	Organism* o1 = new Human(*world, *logger, *manager, { 20,10 });
	Organism* o2a = new Fox(*world, *logger, { 10,10 });
	Organism* o2b = new Fox(*world, *logger, { 1,15 });
	Organism* o2c = new Fox(*world, *logger, { 1,17 });
	Organism* o2d = new Fox(*world, *logger, { 9,8 });
	Organism* o2e = new Fox(*world, *logger, { 9,3 });
	Organism* o3a = new Wolf(*world, *logger, { 1,3 });
	Organism* o3b = new Wolf(*world, *logger, { 19,5 });
	Organism* o4a = new Sheep(*world, *logger, { 3,19 });
	Organism* o4b = new Sheep(*world, *logger, { 9,19 });
	Organism* o4c = new Sheep(*world, *logger, { 30,19 });
	Organism* o4d = new Sheep(*world, *logger, { 35,15 });
	Organism* o4e = new Sheep(*world, *logger, { 33,5 });
	Organism* o4f = new Sheep(*world, *logger, { 34,8 });
	Organism* o5a = new Antelope(*world, *logger, { 6,16 });
	Organism* o5b = new Antelope(*world, *logger, { 16,6 });
	Organism* o5c = new Antelope(*world, *logger, { 13,11 });
	Organism* o6a= new Turtle(*world, *logger, { 11,14 });
	Organism* o6b= new Turtle(*world, *logger, { 1,4 });
	Organism* o6c = new Turtle(*world, *logger, { 37,9 });
	Organism* o10b = new Grass(*world, *logger, { 31,18 });
	Organism* o11a = new Dandelion(*world, *logger, { 30,3 });
	Organism* o13a = new Guarana(*world, *logger, { 1,1 });
	Organism* o14 = new GiantHogweed(*world, *logger, { 27,17 });
	Organism* o15b = new WolfBerries(*world, *logger, { 29,12 });

}

Simulator::Simulator(const unsigned int w, unsigned int h):w(w),h(h)
{
	srand(time(NULL));
	manager = new InputManager;
	logger = new Logger(1,MAP_START_Y+h+LOG_POS_OFFSET,w,*manager);
	world = new World(w, h);
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
			logger = new Logger(1, MAP_START_Y + h + LOG_POS_OFFSET,w,*manager);
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