#include "Animal.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

class Human : public Animal {
private:
	InputManager& inputManager;
public:
	Human(World& w, Logger& l,InputManager& man, pair<int, int> pos) :Animal(w, l, 5, 4, "Human", pos),inputManager(man) {};

	void draw() override {
		textcolor(YELLOW);
		cout << HUMAN_CHAR;
		textcolor(WHITE);
	}

	int getDirection() const override //ERROR NEAR BORDERS
	{
		switch (inputManager.getInput())
		{
		case UP_ARROW:
			return 0;
		case DOWN_ARROW:
			return 1;
		case RIGHT_ARROW:
			return 2;
		case LEFT_ARROW:
			return 3;
		}
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override
	{
		return static_cast<Organism*>(nullptr);
	}

};