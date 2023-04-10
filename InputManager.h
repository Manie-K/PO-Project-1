#pragma once
#include <iostream>
#include "Configuration.h"

using namespace std;

class InputManager {
private:
	int inputChar;
	bool arrowKey;
	bool quit;
public:
	InputManager();
	~InputManager();
	void input();

	int getInput() const;
	bool getQuit() const;
	bool getArrowKey() const;
};