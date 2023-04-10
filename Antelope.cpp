#include "Animal.h"
#include <iostream>

using namespace std;

class Antelope : public Animal {
public:
	Antelope(World& w, Logger& l, pair<int, int> pos) :Animal(w, l, 4, 4, "Antelope", pos) {};

	void draw()const override {
		textcolor(LIGHTRED);
		cout << ANTELOPE_CHAR;
		textcolor(WHITE);
	}

	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos)const override
	{
		return new Antelope(w, l, pos);
	}

	int howManyMoves() const override
	{
		return 2;
	}

	bool defenderFlee(Animal* attacker) override
	{
		int flee = rand() % 2;
		if (flee == 1)
		{
			pair<int, int> tempPos = position;
			if (position.second > 0 &&
				world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr)
			{
				world.getOrganismAtPos(position) = nullptr;
				position.second--;
				world.getOrganismAtPos(position) = this;
			}
			else if (position.second < world.getHeight()-1 && 
				world.getOrganismAtPos({position.first,position.second + 1}) == nullptr)
			{
				world.getOrganismAtPos(position) = nullptr;
				position.second++;
				world.getOrganismAtPos(position) = this;
			}
			else if (position.first < world.getWidth()-1 &&
				world.getOrganismAtPos({ position.first+1,position.second}) == nullptr)
			{
				world.getOrganismAtPos(position) = nullptr;
				position.first++;
				world.getOrganismAtPos(position) = this;
			}
			else if (position.first > 0 && 
				world.getOrganismAtPos({ position.first - 1,position.second }) == nullptr)
			{
				world.getOrganismAtPos(position) = nullptr;
				position.first--;
				world.getOrganismAtPos(position) = this;
			}
			else
				return false; //no empty tile

			world.getOrganismAtPos(attacker->getPosition()) = nullptr;
			attacker->setPosition(tempPos);
			world.getOrganismAtPos(attacker->getPosition()) = attacker;
			return true;
		}
		return false;
	}

};