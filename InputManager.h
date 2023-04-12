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
	InputManager();
	InputManager(bool q, bool s, bool l, bool a, int i, int al, int ac);
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
	void saveFile(FILE* f);
	static InputManager* loadFile(FILE* f);
};