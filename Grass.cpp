#include "Plant.h"

class Grass : public Plant {
public:
	Grass(World& w, Logger& l,pair<int, int> pos):Plant(w,l,0,"Grass",pos) {}
	~Grass(){}
	void draw() const override
	{
		textcolor(GREEN);
		cout << GRASS_CHAR;
		textcolor(WHITE);
	}
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new Grass(w, l, pos);
	}
};