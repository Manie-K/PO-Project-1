#include "World.h"
#include "Organism.h"
#include "conio2.h"
#include <iostream>


World::World(int w, int h):width(w),height(h)
{
	map = new Organism** [height];
	for (int y = 0; y < height; y++)
	{
		map[y] = new Organism *[width];
		for (int x = 0; x < width; x++)
		{
			map[y][x] = nullptr;
		}
	}
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

vector<Organism*>& World::getOrganisms()
{
	return organisms;
}

void World::drawWorld()
{
	clrscr();
	drawBorder();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			gotoxy(x, y);
			if(map[y][x]!=nullptr)
				map[y][x]->draw();
		}
	}
}

void World::simulateTurn()
{
	std::sort(organisms.begin(), organisms.end());
	for (auto& organism : organisms)
	{
		organism->action();
	}
}

void World::updateMap(const pair<int,int> pos, Organism& org)
{
	map[pos.second][pos.first] = &org;
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