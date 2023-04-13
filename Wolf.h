#pragma once
#include "Animal.h"
#include <iostream>

using namespace std;

class Wolf : public Animal {
public:
	Wolf(World& w, Logger& l, pair<int, int> pos, int s = 9);
	void draw() const override;
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override;
};