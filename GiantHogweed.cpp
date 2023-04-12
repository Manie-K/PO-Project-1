#include "GiantHogweed.h"


GiantHogweed::GiantHogweed(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 10, "Giant Hogweed", pos) {}
GiantHogweed::~GiantHogweed() {}
void GiantHogweed::draw() const 
{
	textCustomizer::textcolor(LIGHTRED);
	cout << GIANT_HOGWEED_CHAR;
	textCustomizer::textcolor(WHITE);
}
bool GiantHogweed::kill(Organism* attacker) 
{
	killOrganism(attacker);
	logger.addLog({ attacker->getSpecies() + " died from eating " + species, KILL });
	return true;
}

void GiantHogweed::action() 
{
	if (position.second > 0 && dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second - 1 }))
		!= nullptr)
	{
		logger.addLog({ species + " killed " + world.getOrganismAtPos({ position.first,position.second - 1 })->getSpecies(),KILL });
		killOrganism(world.getOrganismAtPos({ position.first,position.second - 1 }));
	}
	if (position.second < world.getHeight() - 1 && dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second + 1 }))
		!= nullptr)
	{
		logger.addLog({ species + " killed " + world.getOrganismAtPos({ position.first,position.second + 1 })->getSpecies(),KILL });
		killOrganism(world.getOrganismAtPos({ position.first,position.second + 1 }));
	}
	if (position.first < world.getWidth() - 1 && dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first + 1,position.second }))
		!= nullptr)
	{
		logger.addLog({ species + " killed " + world.getOrganismAtPos({ position.first+1,position.second })->getSpecies(),KILL });
		killOrganism(world.getOrganismAtPos({ position.first + 1,position.second }));
	}
	if (position.first > 0 && dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first - 1,position.second }))
		!= nullptr)
	{
		logger.addLog({ species + " killed " + world.getOrganismAtPos({ position.first-1,position.second})->getSpecies(),KILL });
		killOrganism(world.getOrganismAtPos({ position.first - 1,position.second }));
	}
}
Organism* GiantHogweed::giveBirth(World& w, Logger& l, pair<int, int> pos) const
{
	return new GiantHogweed(w, l, pos);
}
