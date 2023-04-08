#include <iostream>
#include <iomanip>
#include "World.h"
#include "Organism.h"
#include "Configuration.h"

using namespace std;

int main()
{
	World w(5,5);
	char input;
	bool quit = false;
	while(!quit)
	{
		input = getchar();
		switch (input)
		{
		case END_SIMULATION_KEY:
			quit = true;
			break;
		case NEXT_TURN_KEY:
			w.drawWorld();
			break;
		default:
			break;
		}
	}

	return 1;
}