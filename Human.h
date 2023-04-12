#pragma once
#include "Animal.h"
#include "InputManager.h"

using namespace std;

class Human : public Animal {
private:
	InputManager& inputManager;
public:
	Human(World& w, Logger& l, InputManager& man, pair<int, int> pos,int s = 5);

	void draw() const override;

	int howManyMoves() const override;

	int getDirection() const override; //Won't move into border
	Organism* giveBirth(World& w, Logger& l, pair<int, int> pos) const override;
};