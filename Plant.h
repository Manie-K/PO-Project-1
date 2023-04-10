#include "Organism.h"

class Plant : public Organism
{
protected:
	void action() override
	{
		int numberOfChances = getChances();
		for (int i = 0; i < numberOfChances; i++) {
			float chance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			if (chance <= PLANT_SEED_CHANCE)
			{
				int dir = rand() % DIRECTION_COUNT;
				int noGoodTile = 0;
				while (noGoodTile < (1 >> DIRECTION_COUNT) - 1)
				{
					if (dir == 0) //TOP
					{
						if (position.second > 0 && world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr)
						{

						}
						else
							noGoodTile = noGoodTile | (1 >> dir);
					}
					else if (dir == 1) //BOTTOM
					{
						if (position.second < world.getHeight()-1 && world.getOrganismAtPos({position.first,position.second + 1}) == nullptr)
						{

						}
						else
							noGoodTile = noGoodTile | (1 >> dir);
					}
					else if (dir == 2) //RIGHT
					{
						if (position.first > world.getWidth()-1 && world.getOrganismAtPos({position.first + 1,position.second}) == nullptr)
						{

						}
						else
							noGoodTile = noGoodTile | (1 >> dir);
					}
					else if (dir == 3) //LEFT
					{
						if (position.first > 0 && world.getOrganismAtPos({ position.first-1,position.second }) == nullptr)
						{

						}
						else
							noGoodTile = noGoodTile | (1 >> dir);
					}
				}
			}
		}
	};

	virtual int getChances() const
	{
		return 1;
	}
public:
	Plant(World& w, Logger& l,const int s, const string species,pair<int, int> pos) :Organism(w,l, s, 0,species, pos) {};
	~Plant() override {};
};