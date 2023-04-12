#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana(World& w, Logger& l, pair<int, int> pos);
	~Guarana();
	void draw() const override;
	void modify(Organism* attacker) const override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};