#pragma once
#include "World.h"
#include <utility>

using namespace std;

class Organism{
protected:
	int strenght;
	int initiative;
	int age;
	pair<int, int> position;
	World& world;
public:
	Organism();
	int getStrenght() const { return strenght; };
	int getInitiative() const {	return initiative;};
	int getAge() const { return age; };
	virtual pair<int, int> getPosition() { return position; };
	virtual ~Organism() = 0;

	virtual void action() = 0;
	virtual void draw() = 0;

	bool operator<(const Organism* other) const
	{
		if (initiative == other->getInitiative())
		{
			return age < other->getAge();
		}
		return initiative < other->getInitiative();
	}
protected:
	virtual void collision() = 0;
};
