#include "Wolf.h"

Wolf::Wolf(World& w, Logger& l, pair<int,int> pos,int s) : Animal(w,l, s, 5, "Wolf", pos) {};

void Wolf::draw() const{
	textCustomizer::textcolor(RED);
	cout << WOLF_CHAR;
	textCustomizer::textcolor(WHITE);
}

Organism* Wolf::giveBirth(World& w, Logger& l, pair<int, int> pos) const
{
	return new Wolf(w,l, pos);
}
