#include "InputManager.h"
#include <conio.h>

InputManager::InputManager()
{
	quit = save = load = arrowKey = false;
	inputChar = abilityLeft = abilityCooldown= 0;
}

InputManager::InputManager(bool q, bool s, bool l, bool a, int i, int al, int ac)
{
	quit = q;
	save = s;
	load = l;
	arrowKey = a;
	inputChar = i;
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

void InputManager::saveFile(FILE* f)
{
	fwrite(&quit, sizeof(bool), 1, f);
	fwrite(&save, sizeof(bool), 1, f);
	fwrite(&load, sizeof(bool), 1, f);
	fwrite(&arrowKey, sizeof(bool), 1, f);
	fwrite(&inputChar, sizeof(int), 1, f);
	fwrite(&abilityLeft, sizeof(int), 1, f);
	fwrite(&abilityCooldown, sizeof(int), 1, f);
}
InputManager* InputManager::loadFile(FILE* f)
{
	bool quit,save,load , arrowKey;
	int inputChar, abilityLeft, abilityCooldown;
	fread(&quit, sizeof(bool), 1, f);
	fread(&save, sizeof(bool), 1, f);
	fread(&load, sizeof(bool), 1, f);
	fread(&arrowKey, sizeof(bool), 1, f);
	fread(&inputChar, sizeof(int), 1, f);
	fread(&abilityLeft, sizeof(int), 1, f);
	fread(&abilityCooldown, sizeof(int), 1, f);
	return new InputManager(quit, save, load, arrowKey, inputChar, abilityLeft, abilityCooldown);
}