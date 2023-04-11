#include "Plant.h"

class WolfBerries : public Plant {
public:
	WolfBerries(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 99, "Wolf Berries", pos) {}
	~WolfBerries() {}
	void draw() const override
	{
		custom.textcolor(LIGHTMAGENTA);
		cout << WOLF_BERRIES_CHAR;
		custom.textcolor(WHITE);
	}
	bool kill(Organism* attacker) override
	{
		killOrganism(attacker);
		logger.addLog({ attacker->getSpecies() + " died from eating " + species, KILL });
		return true;
	}
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new WolfBerries(w, l, pos);
	}
};