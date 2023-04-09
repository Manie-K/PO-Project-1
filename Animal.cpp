#include "Organism.h"

class Animal : public Organism 
{
protected:
	void action() override 
	{
		bool foundGoodTile = false;
		
		while(!foundGoodTile)
		{
			int random = rand() % 4;
			if (random == 0&& position.second > 0) //up
			{
				if (world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr) //empty
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second--;
					world.getOrganismAtPos(position) = this;
				}
				else //not empty
					collision(world.getOrganismAtPos({ position.first,position.second -1}));
				foundGoodTile = true;
			}
			else if (random == 1 && position.second < world.getHeight() - 1)//bottom
			{
				if (world.getOrganismAtPos({position.first,position.second+1}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second++;
					world.getOrganismAtPos(position) = this;
				}
				else 
					collision(world.getOrganismAtPos({ position.first,position.second +1}));
				foundGoodTile = true;
			}
			else if (random == 2&& position.first < world.getWidth() - 1)//right
			{
				if (world.getOrganismAtPos({ position.first+1,position.second}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first++;
					world.getOrganismAtPos(position) = this;
				}
				else
					collision(world.getOrganismAtPos({ position.first + 1,position.second}));
				foundGoodTile = true;
			}
			else if (random == 3&& position.first > 0)//left
			{
				if (world.getOrganismAtPos({ position.first-1,position.second}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first--;
					world.getOrganismAtPos(position) = this;
				}
				else
					collision(world.getOrganismAtPos({ position.first-1,position.second }));
				foundGoodTile = true;
			}
		}
	};

	void collision(Organism* defender) override 
	{
		//todo: if plant then call collision method from plant
		if (species != defender->getSpecies()) {
			if (defender->getStrenght() <= strenght)
			{
				world.getOrganismAtPos(position) = nullptr;
				position = defender->getPosition();
				killOrganism(defender);
				world.getOrganismAtPos(position) = this;
				return;
			}
			killOrganism(this);
			return;
		}
		breed(defender);
		gotoxy(50, 50);
	};

	void breed(Organism* partner) const
	{
		pair<int, int> pos = partner->getPosition();
		for (int i = 0; i < 2; i++) {
			if (pos.second > 0 && world.getOrganismAtPos({ pos.first, pos.second - 1 }) == nullptr)
			{
				giveBirth(world, { pos.first, pos.second - 1 });
				return;
			}
			if (pos.second < world.getHeight() - 1 && world.getOrganismAtPos({ pos.first, pos.second + 1 }) == nullptr)
			{
				giveBirth(world, { pos.first, pos.second + 1 });
				return;
			}
			if (pos.first > 0 && world.getOrganismAtPos({ pos.first - 1, pos.second }) == nullptr)
			{
				giveBirth(world, { pos.first - 1, pos.second });
				return;
			}
			if (pos.first < world.getWidth() - 1 && world.getOrganismAtPos({ pos.first + 1, pos.second }) == nullptr)
			{
				giveBirth(world, { pos.first + 1, pos.second });
				return;
			}
			pos = position; //second loop iteration will look at tiles near this organism
		}
	}

public:
	Animal(World& w, const int s, const int i,const string species, const pair<int, int> pos)
		:Organism(w,s,i,species,pos) {};
	~Animal() override {};
};
