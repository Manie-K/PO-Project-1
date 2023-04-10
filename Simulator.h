#pragma once
#include "Configuration.h"
#include "AnimalsIncludeList.h"
#include "World.h"
#include "Logger.h"
#include "InputManager.h"
#include "conio2.h"

class Simulator {
private:
	World* world;
	Logger* logger;
	InputManager* manager;
private:
	void setUpWorld();
public:
	Simulator();
	~Simulator();
	void run();
};