#include "InputManager.h"

InputManager::InputManager()
{
	quit = false;
	arrowKey = false;
	inputChar = abilityLeft = abilityCooldown= 0;
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
	if (inputChar == ABILITY_KEY)
	{
		if (abilityCooldown == 0) {
			abilityCooldown = ABILITY_COOLDOWN;
			abilityLeft = ABILITY_TIME;
		}
	}
}

int InputManager::getAbility() const { return abilityLeft; }
int InputManager::getInput() const{return inputChar;}
bool InputManager::getQuit() const { return quit; }
bool InputManager::getArrowKey() const { return arrowKey; }

void InputManager::nextTurn()
{
	if (abilityLeft > 0)
		abilityLeft--;
	if (abilityCooldown > 0)
		abilityCooldown--;
}