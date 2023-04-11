#include "Animal.h"
#include <iostream>

using namespace std;

class Wolf : public Animal {
public:
	Wolf(World& w, Logger& l, pair<int,int> pos) :Animal(w,l, 9, 5, "Wolf", pos) {};
	
	void draw() const override {
		custom.textcolor(RED);
		cout << WOLF_CHAR;
		custom.textcolor(WHITE);
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override
	{
		return new Wolf(w,l, pos);
	}
};