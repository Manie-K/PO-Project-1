#include "Animal.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

class Human : public Animal {
private:
	InputManager& inputManager;
public:
	Human(World& w, Logger& l,InputManager& man, pair<int, int> pos) :Animal(w, l, 5, 4, "Human", pos),inputManager(man) {};

	void draw() const override {
		custom.textcolor(YELLOW);
		cout << HUMAN_CHAR;
		custom.textcolor(WHITE);
	}

	int howManyMoves() const override
	{
		int turnsLeft = inputManager.getAbility();
		if(turnsLeft == 0)
			return 1;
		if (turnsLeft > 2)
			return 2;
		int random = rand() % 2;
		return random == 1 ? 2 : 1;
	}

	int getDirection() const override //Won't move into border
	{
		int ret;
		switch (inputManager.getInput())
		{
		case UP_ARROW:
			if (position.second <= 0)
				ret = -1;
			else
				ret = 0;
			break;
		case DOWN_ARROW:
			if (position.second >= world.getHeight() - 1)
				ret = -1;
			else
				ret = 1;
			break;
		case RIGHT_ARROW:
			if (position.first >= world.getWidth() - 1)
				ret = -1;
			else
				ret = 2;
			break;
		case LEFT_ARROW:
			if (position.first <= 0)
				ret = -1;
			else
				ret = 3;
			break;
		default:
			ret = -1;
			break;
		}
		if (ret == -1)
			logger.addLog({"Human tried to walk into border!", INFO});
		return ret;
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return static_cast<Organism*>(nullptr);
	}

};