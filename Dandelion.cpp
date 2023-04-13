#include "Dandelion.h"

Dandelion::Dandelion(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 0, "Dandelion", pos) {}
void Dandelion::draw() const
{
	textCustomizer::textcolor(YELLOW);
	cout << DANDELION_CHAR;
	textCustomizer::textcolor(WHITE);
}
int Dandelion::getChances() const
{
	return 3;
}
Organism* Dandelion::giveBirth(World& w, Logger& l, pair<int, int> pos) const
{
	return new Dandelion(w, l, pos);
}
