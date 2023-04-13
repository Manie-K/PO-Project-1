#include "Guarana.h"

Guarana::Guarana(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 0, "Guarana", pos) {}
void Guarana::draw() const 
{
	textCustomizer::textcolor(LIGHTCYAN);
	cout << GUARANA_CHAR;
	textCustomizer::textcolor(WHITE);
}
void Guarana::modify(Organism* attacker) const 
{
	attacker->setStrenght(attacker->getStrenght()+3);
	logger.addLog({ attacker->getSpecies() + " got stronger beacause it ate " + species, EAT });
}
Organism* Guarana::giveBirth(World& w, Logger& l, pair<int, int> pos) const
{
	return new Guarana(w, l, pos);
}