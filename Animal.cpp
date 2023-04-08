#include "Organism.h"

class Animal : public Organism 
{
protected:
	void action() override 
	{
		srand(time(NULL));

		bool foundGoodTile = false;
		while(!foundGoodTile)
		{
			int random = rand() % 4;
			if (random == 0) //up
			{
				if (position.second <= 0)
					continue;
				if (world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr) //empty
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second--;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else //not empty
				{

				}
			}
			else if (random == 1)//bottom
			{
				if (position.second >= world.getHeight()-1)
					continue;
				if (world.getOrganismAtPos({position.first,position.second+1}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second++;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else 
				{

				}
			}
			else if (random == 2)//right
			{
				if (position.first >= world.getWidth()-1)
					continue;
				if (world.getOrganismAtPos({ position.first+1,position.second}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first++;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else
				{

				}
			}
			else if (random == 3)//left
			{
				if (position.first <= 0)
					continue;
				if (world.getOrganismAtPos({ position.first-1,position.second}) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first--;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else
				{

				}
			}
		}

	};
	void collision() override {};
public:
	Animal(World& w, const int s, const int i, const pair<int, int> pos)
		:Organism(w,s,i,pos) {};
	~Animal() override {
		
	};
};
