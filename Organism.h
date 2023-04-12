#pragma once
#include "World.h"
#include "Logger.h"
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <time.h>
#include <stdexcept>

using namespace std;

class Organism{
protected:
	int strenght;
	int initiative;
	int age;
	string species;
	pair<int, int> position;
	World& world;
	Logger& logger;
public:
	Organism(World& w, Logger& l,const int s = 0, const int i = 0, const string species = "",
		const pair<int, int> pos = make_pair<int, int>(0, 0));
	int getStrenght() const;
	int getInitiative() const;
	int getAge() const;
	string getSpecies() const;
	pair<int, int> getPosition();
	
	void setAge(int age);
	void setStrenght(int strenght);
	void setPosition(pair<int, int> pos);

	virtual ~Organism()= 0;

	virtual void action() = 0;
	virtual void draw() const = 0;

protected:
	virtual bool collision(Organism* other) = 0;//returns true when the attacker dies
	virtual Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const = 0;
	void killOrganism(Organism* victim);
};
