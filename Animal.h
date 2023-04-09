#pragma once
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
		string mess = "";
		//todo: if plant then call collision method from plant
		if (species != defender->getSpecies()) {
			if (defender->getStrenght() <= strenght)
			{
				world.getOrganismAtPos(position) = nullptr;
				position = defender->getPosition();
				killOrganism(defender);
				mess = defender->getSpecies() + " has been killed by " + species;
				logger.addLog({ mess,KILL });
				world.getOrganismAtPos(position) = this;
				return;
			}
			killOrganism(this);
			mess = species + " has been killed by " + defender->getSpecies();
			logger.addLog({ mess,KILL });
			return;
		}
		breed(defender);
	};

	void breed(Organism* partner) const
	{
		bool succes = false;
		pair<int, int> pos = partner->getPosition();
		for (int i = 0; i < 2; i++) {
			if (pos.second > 0 && world.getOrganismAtPos({ pos.first, pos.second - 1 }) == nullptr)
			{
				giveBirth(world, logger,{ pos.first, pos.second - 1 });
				succes = true;
				break;
			}
			if (pos.second < world.getHeight() - 1 && world.getOrganismAtPos({ pos.first, pos.second + 1 }) == nullptr)
			{
				giveBirth(world, logger, { pos.first, pos.second + 1 });
				succes = true;
				break;
			}
			if (pos.first > 0 && world.getOrganismAtPos({ pos.first - 1, pos.second }) == nullptr)
			{
				giveBirth(world, logger, { pos.first - 1, pos.second });
				succes = true;
				break;
			}
			if (pos.first < world.getWidth() - 1 && world.getOrganismAtPos({ pos.first + 1, pos.second }) == nullptr)
			{
				giveBirth(world, logger, { pos.first + 1, pos.second });
				succes = true;
				break;
			}
			pos = position; //second loop iteration will look at tiles near this organism
		}

		if (succes) {
			string mess = species + " has been born";
			logger.addLog({ mess,BIRTH });
		}
	}

public:
	Animal(World& w,Logger& l, const int s, const int i,const string species, const pair<int, int> pos)
		:Organism(w,l,s,i,species,pos) {};
	~Animal() override {};
};
