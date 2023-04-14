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
	const int w, h;
private:
	void setUpWorld(); //here are the initial conditions
	void save();
	void load();
public:
	Simulator(const unsigned int w,const unsigned int h);
	~Simulator();
	void run();
};