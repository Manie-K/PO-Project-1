#include "Animal.h"
#include <iostream>

using namespace std;

class Sheep : public Animal
{
public:
	Sheep(World& w, Logger& l, pair<int, int> pos) :Animal(w,l, 4, 4, "Sheep", pos) {};

	void draw() override {
		textcolor(LIGHTGREEN);
		cout << SHEEP_CHAR;
		textcolor(WHITE);
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override
	{
		return new Sheep(w,l, pos);
	}
};