#include "InputManager.h"

InputManager::InputManager(int al, int ac)
{
	quit = save = load = arrowKey = false;
	inputChar = 0;
	abilityLeft = al;
	abilityCooldown = ac;
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

bool InputManager::getQuit() const { return quit; }
bool InputManager::getSave() const { return save; }
bool InputManager::getLoad() const { return load; }
bool InputManager::getArrowKey() const { return arrowKey; }
int InputManager::getInput() const{return inputChar;}
int InputManager::getAbility() const { return abilityLeft; }
int InputManager::getAbilityCooldown() const { return abilityCooldown; }

void InputManager::nextTurn()
{
	if (abilityLeft > 0)
		abilityLeft--;
	if (abilityCooldown > 0)
		abilityCooldown--;
}

void InputManager::saveFile(fstream& f)
{
	f << abilityLeft << " " << abilityCooldown << endl;
}
InputManager* InputManager::loadFile(fstream& f)
{
	int abilityLeft, abilityCooldown;
	f >> abilityLeft>> abilityCooldown;
	return new InputManager(abilityLeft, abilityCooldown);
}