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
		}
	}
}

void Simulator::setUpWorld()
{
	Human* human = new Human(*world, *logger,*manager, { 5, 5});
	Sheep* s1 = new Sheep(*world, *logger, { 1, 0 });
	Fox* f1 = new Fox(*world, *logger, { 1, 1 });
	Organism* w1 = new Wolf(*world, *logger, { 0,1 });
	Animal* t1 = new Turtle(*world, *logger, { 0, 0 });
	Antelope* a1 = new Antelope(*world, *logger, { 2, 0 });
}
