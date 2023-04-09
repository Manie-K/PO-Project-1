#pragma once
#include "Organism.h"

class Animal : public Organism 
{
protected:
	void action() override 
	{
		const int dirs = 4;
		int moves = howManyMoves();
		float chanceToNotMove = chanceToStay();
		float stay = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (stay < chanceToNotMove)
			return;
		for (int m = 0; m < moves; m++) {
			bool foundGoodTile = false;
			bool badTiles[dirs] = { false,false,false,false };
			while (!foundGoodTile)
			{
				if (badTiles[0] && badTiles[1] && badTiles[2] && badTiles[3])
					return;
				int random = rand() % dirs;
				if (random == 0 && position.second > 0) //up
				{
					if (world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr)
					{
						world.getOrganismAtPos(position) = nullptr;
						position.second--;
						world.getOrganismAtPos(position) = this;
						foundGoodTile = true;
					}
					else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second - 1 })))) {
						collision(world.getOrganismAtPos({ position.first,position.second - 1 }));
						foundGoodTile = true;
					}
					else badTiles[0]=true;
				}
				else if (random == 1 && position.second < world.getHeight() - 1)//bottom
				{
					if (world.getOrganismAtPos({ position.first,position.second + 1 }) == nullptr)
					{
						world.getOrganismAtPos(position) = nullptr;
						position.second++;
						world.getOrganismAtPos(position) = this;
						foundGoodTile = true;
					}
					else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second + 1 })))) {
						collision(world.getOrganismAtPos({ position.first,position.second + 1 }));
						foundGoodTile = true;
					}
					else badTiles[1] = true;
				}
				else if (random == 2 && position.first < world.getWidth() - 1)//right
				{
					if (world.getOrganismAtPos({ position.first + 1,position.second }) == nullptr)
					{
						world.getOrganismAtPos(position) = nullptr;
						position.first++;
						world.getOrganismAtPos(position) = this;
						foundGoodTile = true;
					}
					else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first + 1,position.second })))){
						collision(world.getOrganismAtPos({ position.first + 1,position.second }));
						foundGoodTile = true;
					}
					else badTiles[2] = true;
				}
				else if (random == 3 && position.first > 0)//left
				{
					if (world.getOrganismAtPos({ position.first - 1,position.second }) == nullptr)
					{
						world.getOrganismAtPos(position) = nullptr;
						position.first--;
						world.getOrganismAtPos(position) = this;
						foundGoodTile = true;
					}
					else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first - 1,position.second })))) {
						collision(world.getOrganismAtPos({ position.first - 1,position.second }));
						foundGoodTile = true;
					}
					else badTiles[3] = true;
				}
			}
		}
	};

	void collision(Organism* defender) override 
	{
		string mess = "";
		//todo: if plant then call collision method from plant

		//its animal
		if (species == defender->getSpecies())
		{
			breed(defender);
			return;
		}
		if (defenderFlee(dynamic_cast<Animal*>(defender))) {
			return;
		}
		if (defenderDeflected(dynamic_cast<Animal*>(defender))){
			return;
		}

		if (defender->getStrenght() <= strenght)
		{
			world.getOrganismAtPos(position) = nullptr;
			position = defender->getPosition();
			killOrganism(defender);
			world.getOrganismAtPos(position) = this;

			mess = defender->getSpecies() + " has been killed by " + species;
			logger.addLog({ mess,KILL });
			return;
		}
		killOrganism(this);

		mess = species + " has been killed by " + defender->getSpecies();
		logger.addLog({ mess,KILL });
		return;
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

	virtual bool defenderFlee(Animal* defender) { return false; }
	virtual bool defenderDeflected(Animal* defender) { return false; }
	virtual bool goodSmell(Animal* defender) const { return false; }
	virtual int howManyMoves() const { return 1; }
	virtual float chanceToStay() const { return 0.0; }

public:
	Animal(World& w,Logger& l, const int s, const int i,const string species, const pair<int, int> pos)
		:Organism(w,l,s,i,species,pos) {};
	~Animal() override {};
};
