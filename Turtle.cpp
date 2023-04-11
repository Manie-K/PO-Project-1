#include "Animal.h"
#include <iostream>

using namespace std;

class Turtle : public Animal
{
public:
	Turtle(World& w, Logger& l, pair<int, int> pos) :Animal(w, l, 2, 1, "Turtle", pos) {};

	void draw() const override {
		custom.textcolor(GREEN);
		cout << TURTLE_CHAR;
		custom.textcolor(WHITE);
	}

	float chanceToStay() const override
	{
		return 0.75f;
	}

	bool defenderDeflected(Animal* attacker) override
	{
		return attacker->getStrenght() < 5;
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override
	{
		return new Turtle(w, l, pos);
	}
};