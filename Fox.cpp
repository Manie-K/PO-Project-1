#include "Fox.h"

Fox::Fox(World& w, Logger& l, pair<int, int> pos, int s) :Animal(w, l, s, 7, "Fox", pos) {};

void Fox::draw() const{
	textCustomizer::textcolor(BROWN);
	cout << FOX_CHAR;
	textCustomizer::textcolor(WHITE);
}
Organism* Fox::giveBirth(World& w, Logger& l, pair<int, int> pos)const
{
	return new Fox(w, l, pos);
}

bool Fox::goodSmell(Animal* defender) const
{
	if (defender == nullptr || defender->getStrenght() <= strenght)
		return false;
	logger.addLog({ species + " hasn't attacked " + defender->getSpecies() + " because of good smell",INFO });
	return true;
}
