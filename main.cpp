#include <iostream>
#include <iomanip>
#include "World.h"
#include "Organism.h"
#include "Configuration.h"
#include "AnimalsIncludeList.h"

using namespace std;

int main()
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	textcolor(WHITE);
	Logger logger(1,21);
	World w(10,10,logger);

	char input;
	bool quit = false;

	w.drawWorld();
	while(!quit)
	{
		input = getchar();
		switch (input)
		{
		case END_SIMULATION_KEY:
			quit = true;
			break;
		case NEXT_TURN_KEY:
			w.simulateTurn();
			w.drawWorld();
			logger.display();
			break;
		default:
			break;
		}
	}

	return 1;
}