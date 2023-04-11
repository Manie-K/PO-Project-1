#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 0, "Dandelion", pos) {}
	~Dandelion() {}
	void draw() const override
	{
		custom.textcolor(YELLOW);
		cout << DANDELION_CHAR;
		custom.textcolor(WHITE);
	}
	int getChances() const override
	{
		return 3;
	}
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new Dandelion(w, l, pos);
	}
};