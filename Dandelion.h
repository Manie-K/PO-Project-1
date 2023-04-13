#pragma once
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World& w, Logger& l, pair<int, int> pos);
	void draw() const override;
	int getChances() const override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};