#pragma once
#include "Configuration.h"
#include <iostream>
#include <conio.h>
#include <fstream>

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

	int getInput() const;
	int getAbility() const;
	int getAbilityCooldown() const;
	bool getQuit() const;
	bool getSave() const;
	bool getLoad() const;
	bool getArrowKey() const;

	void nextTurn();
	void saveFile(fstream& f);
	static InputManager* loadFile(fstream& f);
};