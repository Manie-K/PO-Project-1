#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal
{
public:
	Sheep(World& w, Logger& l, pair<int, int> pos, int s = 4);

	void draw() const override;

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override;
};