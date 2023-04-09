#include "Animal.h"
#include <iostream>

using namespace std;

class Sheep : public Animal
{
public:
	Sheep(World& w, pair<int, int> pos) :Animal(w, 4, 4, "Sheep", pos) {};

	void draw() override {
		textcolor(GREEN);
		cout << SHEEP_CHAR;
		textcolor(WHITE);
	}

	Organism* giveBirth(World& w, pair<int, int> pos)const override
	{
		return new Sheep(w, pos);
	}
};