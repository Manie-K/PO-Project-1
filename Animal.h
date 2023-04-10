#pragma once
#include "Organism.h"
#include "Plant.h"

class Animal : public Organism 
{
private:
	void action() override;
	bool collision(Organism* defender) override;
	void breed(Organism* partner) const;

protected:
	virtual bool defenderFlee(Animal* attacker);
	virtual bool defenderDeflected(Animal* attacker);
	virtual bool goodSmell(Animal* defender) const;
	virtual int howManyMoves() const;
	virtual float chanceToStay() const;
	virtual int getDirection() const;

public:
	Animal(World& w, Logger& l, const int s, const int i, const string species, const pair<int, int> pos);
	~Animal() override;
};