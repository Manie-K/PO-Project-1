#pragma once
#include <iostream>
#include "Configuration.h"

using namespace std;

class InputManager {
private:
	bool quit;
	bool save;
	bool load;
	bool arrowKey;
	int inputChar;
	int abilityLeft;
	int abilityCooldown;
public:
	InputManager(int al = 0, int ac = 0);
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
	void saveFile(fstream& f);
	static InputManager* loadFile(fstream& f);
};