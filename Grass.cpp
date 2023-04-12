#include "Grass.h"

Grass::Grass(World& w, Logger& l,pair<int, int> pos):Plant(w,l,0,"Grass",pos) {}
Grass::~Grass(){}
void Grass::draw() const
{
	textCustomizer::textcolor(GREEN);
	cout << GRASS_CHAR;
	textCustomizer::textcolor(WHITE);
}
Organism* Grass::giveBirth(World& w, Logger& l, pair<int, int> pos) const
{
	return new Grass(w, l, pos);
}
