#include "InputManager.h"
#include <conio.h>

InputManager::InputManager()
{
	quit = save = load = arrowKey = false;
	inputChar = abilityLeft = abilityCooldown= 0;
}

InputManager::~InputManager(){}

void InputManager::input()
{
	arrowKey = quit = save = load = false;
	inputChar = _getch();
	if(inputChar==ARROW_MODIFIER_KEY){
		inputChar = _getch();
		if (inputChar == UP_ARROW || inputChar == DOWN_ARROW || inputChar == LEFT_ARROW || inputChar == RIGHT_ARROW)
		{
			arrowKey = true;
		}
	}
	if (inputChar == END_SIMULATION_KEY)
	{
		quit = true;
	}
	if (inputChar == SAVE_KEY)
	{
		save = true;
	}
	if (inputChar == LOAD_KEY)
	{
		load = true;
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
int InputManager::getAbilityCooldown() const { return abilityCooldown; }
int InputManager::getInput() const{return inputChar;}
bool InputManager::getQuit() const { return quit; }
bool InputManager::getSave() const { return save; }
bool InputManager::getLoad() const { return load; }
bool InputManager::getArrowKey() const { return arrowKey; }

void InputManager::nextTurn()
{
	if (abilityLeft > 0)
		abilityLeft--;
	if (abilityCooldown > 0)
		abilityCooldown--;
}