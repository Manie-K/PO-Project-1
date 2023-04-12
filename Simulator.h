#pragma once
#include <fstream>
#include "Configuration.h"
#include "OrganismIncludeList.h"
#include "World.h"
#include "Logger.h"
#include "InputManager.h"

class Simulator {
private:
	World* world;
	Logger* logger;
	InputManager* manager;
private:
	void setUpWorld();
	void save();
	void load();
public:
	Simulator();
	~Simulator();
	void run();
};