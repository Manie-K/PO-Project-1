#include "Simulator.h"

Simulator::Simulator()
{
	srand(time(NULL));
	logger = new Logger(1,MAP_START_Y+MAP_H+LOG_POS_OFFSET);
	world = new World(MAP_W, MAP_H, *logger);
	manager = new InputManager;
	setUpWorld();
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	textcolor(WHITE);
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
	world->drawWorld();
	while (!manager->getQuit())
	{
		manager->input();
		if(manager->getArrowKey())
		{
			world->simulateTurn();
			world->drawWorld();
			logger->display();
			manager->nextTurn();
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
