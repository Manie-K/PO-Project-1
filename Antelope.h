#pragma once
#include "Animal.h"

using namespace std;

class Antelope : public Animal {
public:
	Antelope(World& w, Logger& l, pair<int, int> pos, int s = 4);

	void draw()const override;

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override;

	int howManyMoves() const override;

	bool defenderFlee(Animal* attacker) override;
};