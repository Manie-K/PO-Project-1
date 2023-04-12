#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 0, "Dandelion", pos) {}
	~Dandelion() {}
	void draw() const override
	{
		textCustomizer::textcolor(YELLOW);
		cout << DANDELION_CHAR;
		textCustomizer::textcolor(WHITE);
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