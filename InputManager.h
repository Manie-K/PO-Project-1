#pragma once
#include <iostream>
#include "Configuration.h"

using namespace std;

class InputManager {
private:
	int inputChar;
	int abilityCooldown;
	int abilityLeft;
	bool arrowKey;
	bool quit;
public:
	InputManager();
	~InputManager();
	void input();

	int getAbility() const;
	int getInput() const;
	bool getQuit() const;
	bool getArrowKey() const;

	void nextTurn();
};