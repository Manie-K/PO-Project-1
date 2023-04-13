#include "Sheep.h"
#include <iostream>

using namespace std;

Sheep::Sheep(World& w, Logger& l, pair<int, int> pos, int s) :Animal(w,l, s, 4, "Sheep", pos) {};

void Sheep::draw() const {
	textCustomizer::textcolor(LIGHTGREEN);
	cout << SHEEP_CHAR;
	textCustomizer::textcolor(WHITE);
}

Organism* Sheep::giveBirth(World& w, Logger& l, pair<int, int> pos)const 
{
	return new Sheep(w,l, pos);
}
