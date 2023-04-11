#pragma once
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
	static textCustomizer custom;
private:
	void setUpWorld();
public:
	Simulator();
	~Simulator();
	void run();
};