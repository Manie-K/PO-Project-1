#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 0, "Guarana", pos) {}
	~Guarana() {}
	void draw() const override
	{
		textcolor(LIGHTCYAN);
		cout << GUARANA_CHAR;
		textcolor(WHITE);
	}
	void modify(Organism* attacker) const override
	{
		attacker->setStrenght(attacker->getStrenght()+3);
		logger.addLog({ attacker->getSpecies() + " got stronger beacause it ate " + species, EAT });
	}
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new Guarana(w, l, pos);
	}
};