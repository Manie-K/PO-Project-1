#pragma once
#include "Animal.h"

using namespace std;

class Fox : public Animal {
public:
	Fox(World& w, Logger& l, pair<int, int> pos, int s = 3);

	void draw() const override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override;
	bool goodSmell(Animal* defender) const override;
};