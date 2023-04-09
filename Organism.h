#pragma once
#include "World.h"
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
public:
	Organism(World& w,const int s=0, const int i=0,const string species="",
		const pair<int, int> pos=make_pair<int,int>(0,0));
	int getStrenght() const;
	int getInitiative() const;
	int getAge() const;
	void setAge(int age);
	string getSpecies() const;
	pair<int, int> getPosition();
	
	virtual ~Organism()= 0;

	virtual void action() = 0;
	virtual void draw() = 0;

	bool operator<(const Organism* other) const;
protected:
	virtual void collision(Organism* defender) = 0;
	virtual Organism* giveBirth(World& w, pair<int, int> pos) const = 0;
	void killOrganism(Organism* victim);
};
