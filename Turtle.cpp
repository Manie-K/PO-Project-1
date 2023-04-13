#include "Turtle.h"

Turtle::Turtle(World& w, Logger& l, pair<int, int> pos, int s) :Animal(w, l, s, 1, "Turtle", pos) {};

void Turtle::draw() const {
	textCustomizer::textcolor(GREEN);
	cout << TURTLE_CHAR;
	textCustomizer::textcolor(WHITE);
}

float Turtle::chanceToStay() const
{
	return 0.75f;
}

bool Turtle::defenderDeflected(Animal* attacker) const
{
	if(attacker!=nullptr)
		return attacker->getStrenght() < 5;
	return false;
}

Organism* Turtle::giveBirth(World& w, Logger& l, pair<int, int> pos)const
{
	return new Turtle(w, l, pos);
}