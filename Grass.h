#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass(World& w, Logger& l, pair<int, int> pos);
	~Grass();
	void draw() const override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};