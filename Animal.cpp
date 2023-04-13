#include "Animal.h"

Animal::Animal(World& w, Logger& l, const int s, const int i, const string species, const pair<int, int> pos)
		:Organism(w, l, s, i, species, pos) {}
Animal::~Animal(){}

void Animal::action()
{
	int moves = howManyMoves();
	float chanceToNotMove = chanceToStay();
	float stay = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	bool dead = false;
	const int max = (1 << DIRECTION_COUNT) - 1;
	if (stay < chanceToNotMove)
		return;

	for (int m = 0; m < moves; m++) {
		if (dead) 
			return;
		bool foundGoodTile = false;
		int badTiles = 0;
		while (!foundGoodTile)
		{
			int direction = getDirection();
			if (badTiles>=max || direction == -1)
				return;
			if (direction == 0 && position.second > 0 && !(badTiles & (1 << direction)))//up
			{
				if (world.getOrganismAtPos({ position.first,position.second - 1 }) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second--;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second - 1 })))) {
					dead = collision(world.getOrganismAtPos({ position.first,position.second - 1 }));
					foundGoodTile = true;
				}
				else badTiles|=(1<<direction);
			}
			else if (direction == 1 && position.second < world.getHeight() - 1 && !(badTiles & (1 << direction)))//bottom
			{
				if (world.getOrganismAtPos({ position.first,position.second + 1 }) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.second++;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first,position.second + 1 })))) {
					dead = collision(world.getOrganismAtPos({ position.first,position.second + 1 }));
					foundGoodTile = true;
				}
				else badTiles |= (1 << direction);
			}
			else if (direction == 2 && position.first < world.getWidth() - 1 && !(badTiles & (1 << direction)))//right
			{
				if (world.getOrganismAtPos({ position.first + 1,position.second }) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first++;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first + 1,position.second })))) {
					dead = collision(world.getOrganismAtPos({ position.first + 1,position.second }));
					foundGoodTile = true;
				}
				else badTiles |= (1 << direction);
			}
			else if (direction == 3 && position.first > 0 && !(badTiles & (1 << direction)))//left
			{
				if (world.getOrganismAtPos({ position.first - 1,position.second }) == nullptr)
				{
					world.getOrganismAtPos(position) = nullptr;
					position.first--;
					world.getOrganismAtPos(position) = this;
					foundGoodTile = true;
				}
				else if (!goodSmell(dynamic_cast<Animal*>(world.getOrganismAtPos({ position.first - 1,position.second })))) {
					dead = collision(world.getOrganismAtPos({ position.first - 1,position.second }));
					foundGoodTile = true;
				}
				else badTiles |= (1 << direction);
			}
			else
			{
				badTiles |= (1 << direction);
			}
		}
	}
};
bool Animal::collision(Organism* defender)
{
	string mess = "";
	Plant* testIfPlant = dynamic_cast<Plant*>(defender);

	//its plant
	if (testIfPlant != nullptr) {
		bool killed = dynamic_cast<Plant*>(defender)->collision(this);
		mess = defender->getSpecies() + " has been eaten by " + species;
		logger.addLog({ mess,EAT });
		if (killed)
		{
			mess = species + " has been poisoned by " + defender->getSpecies();
			logger.addLog({ mess,POISON });
		}
		return killed;
	}

	//its animal
	if (species == defender->getSpecies())
	{
		breed(defender);
		return false;
	}
	if (dynamic_cast<Animal*>(defender)->defenderFlee(dynamic_cast<Animal*>(this))) {
		mess = defender->getSpecies() + " has fleed from " + species;
		logger.addLog({ mess, INFO });
		return false;
	}
	if (dynamic_cast<Animal*>(defender)->defenderDeflected(dynamic_cast<Animal*>(this))) {
		mess = defender->getSpecies() + " has succesfully deflected an attack of " + species;
		logger.addLog({ mess, INFO });
		return false;
	}

	if (defender->getStrenght() <= strenght)
	{
		world.getOrganismAtPos(position) = nullptr;
		position = defender->getPosition();
		killOrganism(defender);
		world.getOrganismAtPos(position) = this;

		mess = species + " has killed " + defender->getSpecies() + " in attack";
		logger.addLog({ mess,KILL });
		return false;
	}
	killOrganism(this);
	mess = species + " has been killed by " + defender->getSpecies() + " in attack";
	logger.addLog({ mess,KILL });
	return true;
};
void Animal::breed(Organism* partner) const
{
	bool success = false;
	pair<int, int> pos = partner->getPosition();
	for (int i = 0; i < 2; i++) {
		if (success)
			break;
		if (pos.second > 0 && world.getOrganismAtPos({ pos.first, pos.second - 1 }) == nullptr)
		{
			giveBirth(world, logger, { pos.first, pos.second - 1 });
			success = true;
			continue;
		}
		if (pos.second < world.getHeight() - 1 && world.getOrganismAtPos({ pos.first, pos.second + 1 }) == nullptr)
		{
			giveBirth(world, logger, { pos.first, pos.second + 1 });
			success = true;
			continue;
		}
		if (pos.first > 0 && world.getOrganismAtPos({ pos.first - 1, pos.second }) == nullptr)
		{
			giveBirth(world, logger, { pos.first - 1, pos.second });
			success = true;
			continue;
		}
		if (pos.first < world.getWidth() - 1 && world.getOrganismAtPos({ pos.first + 1, pos.second }) == nullptr)
		{
			giveBirth(world, logger, { pos.first + 1, pos.second });
			success = true;
			continue;
		}
		pos = position; //second loop iteration will look at tiles near this organism
	}

	if (success) {
		string mess = species + " has been born";
		logger.addLog({ mess,BIRTH });
	}
}

bool Animal::defenderFlee(Animal* attacker) { return false; }
bool Animal::defenderDeflected(Animal* attacker)const { return false; }
bool Animal::goodSmell(Animal* defender) const { return false; }
int Animal::howManyMoves() const { return 1; }
float Animal::chanceToStay() const { return 0.0; }
int Animal::getDirection() const { return rand() % DIRECTION_COUNT; }
