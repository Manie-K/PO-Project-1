#pragma once
#include <vector>
#include <algorithm>
#include "Configuration.h"

using namespace std;

class Organism;
class Logger;

class World {
private:
	const int width, height;
	vector<Organism*> organisms;
	Organism*** map;
private:
	void drawBorder();
	void customInitialMapLoad(Logger& logger);
	static bool compareOrganismPointer(const Organism* o1, const Organism* o2);
public:
	World(int w, int h, Logger& logger);
	~World();

	int getWidth() const;
	int getHeight() const;
	vector<Organism*>& getOrganisms();
	Organism*** getMap();
	Organism*& getOrganismAtPos(pair<int, int> pos);

	void drawWorld();
	void simulateTurn();
};
