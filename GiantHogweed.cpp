#include "Animal.h"

class GiantHogweed : public Plant {
public:
	GiantHogweed(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 10, "Giant Hogweed", pos) {}
	~GiantHogweed() {}
	void draw() const override
	{
		textCustomizer::textcolor(LIGHTRED);
		cout << GIANT_HOGWEED_CHAR;
		textCustomizer::textcolor(WHITE);
	}
	bool kill(Organism* attacker) override
	{
		killOrganism(attacker);
		logger.addLog({ attacker->getSpecies() + " died from eating " + species, KILL });
		return true;
	}

	void action() override
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
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new GiantHogweed(w, l, pos);
	}
};