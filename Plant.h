#pragma once
#include "Organism.h"

class Animal;

class Plant : public Organism
{
private:
	void sow(pair<int, int> pos);

protected:
	void action() override;
	virtual int getChances() const;
	virtual bool kill(Organism* attacker);
	virtual void modify(Organism* attacker) const;
public:
	bool collision(Organism* attacker) override;
	Plant(World& w, Logger& l, const int s, const string species, pair<int, int> pos);
	~Plant() override;
};