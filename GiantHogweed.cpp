#include "Plant.h"

class GiantHogweed : public Plant {
public:
	GiantHogweed(World& w, Logger& l, pair<int, int> pos) :Plant(w, l, 10, "Giant Hogweed", pos) {}
	~GiantHogweed() {}
	void draw() const override
	{
		textcolor(LIGHTRED);
		cout << GIANT_HOGWEED_CHAR;
		textcolor(WHITE);
	}
	bool kill(Organism* attacker) override
	{
		killOrganism(attacker);
		return true;
	}

	void action() override
	{
		if (position.second > 0 && world.getOrganismAtPos({ position.first,position.second - 1 })!=nullptr)
			killOrganism(world.getOrganismAtPos({ position.first,position.second - 1 }));
		if (position.second < world.getHeight()-1 && world.getOrganismAtPos({ position.first,position.second + 1 }) != nullptr)
			killOrganism(world.getOrganismAtPos({ position.first,position.second + 1 }));
		if (position.first < world.getWidth()-1 && world.getOrganismAtPos({ position.first+1,position.second }) != nullptr)
			killOrganism(world.getOrganismAtPos({ position.first+1,position.second}));
		if (position.first > 0 && world.getOrganismAtPos({ position.first-1,position.second}) != nullptr)
			killOrganism(world.getOrganismAtPos({ position.first-1,position.second}));
	}
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return new GiantHogweed(w, l, pos);
	}
};