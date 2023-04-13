#include "WolfBerries.h"

WolfBerries::WolfBerries(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 99, "WolfBerries", pos) {}
WolfBerries::~WolfBerries() {}
void WolfBerries::draw() const 
{
	textCustomizer::textcolor(LIGHTMAGENTA);
	cout << WOLF_BERRIES_CHAR;
	textCustomizer::textcolor(WHITE);
}
bool WolfBerries::kill(Organism* attacker) 
{
	killOrganism(attacker);
	logger.addLog({ attacker->getSpecies() + " died from eating " + species, KILL });
	return true;
}
Organism* WolfBerries::giveBirth(World& w, Logger& l, pair<int, int> pos) const 
{
	return new WolfBerries(w, l, pos);
}