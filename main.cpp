#include <iostream>
#include <iomanip>
#include "World.h"
#include "Organism.h"
#include "Configuration.h"
#include "Animals.h"

using namespace std;

int main()
{
	_setcursortype(_NOCURSOR);
	textbackground(BLACK);
	textcolor(WHITE);
	World w(5,5);
	Wolf *wolf = new Wolf(w, make_pair<int,int>(0,0));

	w.getOrganismAtPos(wolf->getPosition()) = wolf;

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