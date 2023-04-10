#include "InputManager.h"

InputManager::InputManager()
{
	quit = false;
	arrowKey = false;
	inputChar = 0;
}

InputManager::~InputManager(){}

void InputManager::input()
{
	arrowKey = quit = false;
	inputChar = getchar();
	if (inputChar == UP_ARROW || inputChar == DOWN_ARROW || inputChar == LEFT_ARROW || inputChar == RIGHT_ARROW)
	{
		arrowKey = true;
	}
	if (inputChar == END_SIMULATION_KEY)
	{
		quit = true;
	}
}

int InputManager::getInput() const{return inputChar;}
bool InputManager::getQuit() const { return quit; }
bool InputManager::getArrowKey() const { return arrowKey; }