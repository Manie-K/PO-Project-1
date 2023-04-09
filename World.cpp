#include "World.h"
#include "Organism.h"
#include "AnimalsIncludeList.h"
#include "conio2.h"
#include <iostream>

//EDIT THIS => INITIAL MAP CONFIGURATION
void World::customInitialMapLoad(Logger& logger)
{
	Wolf* w1 = new Wolf(*this,logger, { 2, 2 });
	Wolf* w2 = new Wolf(*this, logger, {6, 6});
	Sheep* s1 = new Sheep(*this, logger, { 5, 0 });
	Sheep* s2 = new Sheep(*this, logger, { 2, 8 });
}
//======================================

World::World(int w, int h, Logger& logger):width(w),height(h)
{
	srand(time(NULL)); //initilize randomness

	map = new Organism** [height];
	for (int y = 0; y < height; y++)
	{
		map[y] = new Organism *[width];
		for (int x = 0; x < width; x++)
		{
			map[y][x] = nullptr;
		}
	}
	customInitialMapLoad(logger);
}

World::~World()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			delete map[y][x];
			map[y][x] = nullptr;
		}
		delete[] map[y];
		map[y] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

int World::getWidth() const
{
	return width;
}

int World::getHeight() const
{
	return height;
}

vector<Organism*>& World::getOrganisms(){return organisms;}

Organism*** World::getMap() { return map; }

void World::drawWorld()
{
	clrscr();
	drawBorder();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			gotoxy(x+MAP_START_X+1, y+MAP_START_Y+1); //map start includes border, so + 1
			if(map[y][x]!=nullptr)
				map[y][x]->draw();
		}
	}
}

void World::simulateTurn()
{
	std::sort(organisms.begin(), organisms.end());
	reverse(organisms.begin(), organisms.end());

	int fixedSize = organisms.size();
	for (int i = 0; i < fixedSize; i++)
	{
		if (organisms[i] != nullptr)
		{
			organisms[i]->setAge(organisms[i]->getAge() + 1);
			organisms[i]->action();
		}
	}
	organisms.erase(remove(organisms.begin(), organisms.end(), nullptr), organisms.end());
}

void World::drawBorder()
{
	gotoxy(MAP_START_X, MAP_START_Y);
	for (int x = 0; x < width + 2; x++)
	{
		cout <<BORDER_CHAR;
	}
	gotoxy(MAP_START_X, MAP_START_Y+height+1);
	for (int x = 0; x < width + 2; x++)
	{
		cout << BORDER_CHAR;
	}
	for (int y = 0; y < height+1; y++)
	{
		gotoxy(MAP_START_X, MAP_START_Y+y);
		cout << BORDER_CHAR;
	}
	for (int y = 0; y < height + 1; y++)
	{
		gotoxy(MAP_START_X+width+1, MAP_START_Y+y);
		cout << BORDER_CHAR;
	}
	gotoxy(1, 15);
}

Organism*& World::getOrganismAtPos(pair<int, int> pos)
{
	try {
		if (pos.first < 0 || pos.first >= width|| pos.second >= height|| pos.second < 0)
			throw out_of_range("Trying to access position outside of map!");
	}
	catch (exception& e)
	{
		cerr << "Error: " << e.what() << endl;
	}
	return map[pos.second][pos.first];
}
