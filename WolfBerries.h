#pragma once
#include "Plant.h"

class WolfBerries : public Plant {
public:
	WolfBerries(World& w, Logger& l, pair<int, int> pos);
	~WolfBerries();
	void draw() const override;
	bool kill(Organism* attacker) override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};