#pragma once
#include "World.h"
#include <iostream>
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
	pair<int, int> position;
	World& world;
public:
	Organism(World& w,const int s=0, const int i=0,
		const pair<int, int> pos=make_pair<int,int>(0,0));
	int getStrenght() const;
	int getInitiative() const;
	int getAge() const;
	pair<int, int> getPosition();
	
	virtual ~Organism()= 0;

	virtual void action() = 0;
	virtual void draw() = 0;

	bool operator<(const Organism* other) const;
protected:
	virtual void collision() = 0;
	
};
