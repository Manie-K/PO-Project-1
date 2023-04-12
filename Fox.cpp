#include "Animal.h"
#include <iostream>

using namespace std;

class Fox : public Animal {
public:
	Fox(World& w, Logger& l, pair<int, int> pos) :Animal(w, l, 3, 7, "Fox", pos) {};

	void draw() const override {
		textCustomizer::textcolor(BROWN);
		cout << FOX_CHAR;
		textCustomizer::textcolor(WHITE);
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override
	{
		return new Fox(w, l, pos);
	}

	bool goodSmell(Animal* defender) const override
	{
		if (defender == nullptr || defender->getStrenght() <= strenght)
			return false;
		logger.addLog({ species + "hasn't attacked " + defender->getSpecies() + " because of good smell",INFO });
		return true;
	}
};