#include "Antelope.h"

Antelope::Antelope(World& w, Logger& l, pair<int, int> pos, int s) :Animal(w, l, s, 4, "Antelope", pos) {};

void Antelope::draw()const{
	textCustomizer::textcolor(LIGHTRED);
	cout << ANTELOPE_CHAR;
	textCustomizer::textcolor(WHITE);
}

Organism* Antelope::giveBirth(World& w, Logger& l, pair<int, int> pos)const
{
	return new Antelope(w, l, pos);
}

int Antelope::howManyMoves() const 
{
	return 2;
}

bool Antelope::defenderFlee(Animal* attacker)
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