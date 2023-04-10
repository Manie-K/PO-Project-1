#include "Plant.h"

Plant::Plant(World& w, Logger& l, const int s, const string species, pair<int, int> pos) :Organism(w, l, s, 0, species, pos) {}
Plant::~Plant(){}

void Plant::action()
{
	int numberOfChances = getChances();
	for (int i = 0; i < numberOfChances; i++) {
		float chance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		if (chance <= PLANT_SEED_CHANCE)
		{
			int noGoodTile = 0;
			const int x = (1 << DIRECTION_COUNT) - 1;
			while (noGoodTile < x)
			{
				int dir = rand() % DIRECTION_COUNT;
				if (dir == 0) //TOP
				{
					if (position.second > 0 && world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr)
					{
						sow({ position.first,position.second - 1 });
						noGoodTile = x;
					}
					else
						noGoodTile = noGoodTile | (1 <<dir);
				}
				else if (dir == 1) //BOTTOM
				{
					if (position.second < world.getHeight() - 1 && world.getOrganismAtPos({ position.first,position.second + 1 }) == nullptr)
					{
						sow({ position.first,position.second + 1 });
						noGoodTile = x;
					}
					else
						noGoodTile = noGoodTile | (1 << dir);
				}
				else if (dir == 2) //RIGHT
				{
					if (position.first > world.getWidth() - 1 && world.getOrganismAtPos({ position.first + 1,position.second }) == nullptr)
					{
						sow({ position.first + 1,position.second });
						noGoodTile = x;
					}
					else
						noGoodTile = noGoodTile | (1 << dir);
				}
				else if (dir == 3) //LEFT
				{
					if (position.first > 0 && world.getOrganismAtPos({ position.first - 1,position.second }) == nullptr)
					{
						sow({ position.first - 1,position.second });
						noGoodTile = x;
					}
					else
						noGoodTile = noGoodTile | (1 << dir);
				}
			}
		}
	}
}
bool Plant::collision(Organism* attacker)
{
	killOrganism(this);
	if (kill(attacker))
		return true;
	modify(attacker);
	world.getOrganismAtPos(attacker->getPosition()) = nullptr;
	attacker->setPosition(position);
	world.getOrganismAtPos(attacker->getPosition()) = attacker;
	return false;
}

void Plant::sow(pair<int, int> pos) {
	world.getOrganismAtPos(pos) = giveBirth(world, logger, pos);
	string mess = species + " has been planted";
	logger.addLog({ mess,SOW });
}
int Plant::getChances() const { return 1; }
bool Plant::kill(Organism* attacker) { return false; }
void Plant::modify(Organism* attacker)const { return; }

