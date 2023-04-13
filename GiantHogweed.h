#pragma once
#include "Animal.h"

class GiantHogweed : public Plant {
public:
	GiantHogweed(World& w, Logger& l, pair<int, int> pos);
	void draw() const override;
	bool kill(Organism* attacker) override;
	void action() override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};