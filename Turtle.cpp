#include "Turtle.h"
#include <iostream>

using namespace std;

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

bool Turtle::defenderDeflected(Animal* attacker)
{
	return attacker->getStrenght() < 5;
}

Organism* Turtle::giveBirth(World& w, Logger& l, pair<int, int> pos)const
{
	return new Turtle(w, l, pos);
}