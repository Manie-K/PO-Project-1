#pragma once
#include <vector>
#include <algorithm>
#include "Configuration.h"

using namespace std;

class Organism;

class World {
private:
	const int width, height;
	vector<Organism*> organisms;
	Organism*** map;
private:
	void updateMap(const pair<int,int> pos, Organism& org);
	void drawBorder();
public:
	World(int w = 0, int h = 0);
	~World();

	int getWidth() const;
	int getHeight() const;
	vector<Organism*>& getOrganisms();

	void drawWorld();
	void simulateTurn();
};
