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
	World w(20,20);

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
			break;
		default:
			break;
		}
	}

	return 1;
}