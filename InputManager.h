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
	bool save;
	bool load;
public:
	InputManager();
	~InputManager();
	void input();

	int getAbility() const;
	int getAbilityCooldown() const;
	int getInput() const;
	bool getQuit() const;
	bool getSave() const;
	bool getLoad() const;
	bool getArrowKey() const;

	void nextTurn();
};