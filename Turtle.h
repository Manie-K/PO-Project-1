#pragma once
#include "Animal.h"

using namespace std;

class Turtle : public Animal
{
public:
	Turtle(World& w, Logger& l, pair<int, int> pos, int s = 9);

	void draw() const override;

	float chanceToStay() const override;
	bool defenderDeflected(Animal* attacker) override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override;
};