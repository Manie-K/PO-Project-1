#include "Organism.h"
#include <iostream>
#include <fstream>

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
	organisms.clear();
	for (int y = 0; y < height; y++)
	{
		
		map[y] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

int World::getWidth() const { return width; }

int World::getHeight() const { return height; }

vector<Organism*>& World::getOrganisms(){ return organisms; }

Organism*** World::getMap() { return map; }

void World::drawWorld()
{
	system("cls");
	drawBorder();
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			textCustomizer::gotoxy(x+MAP_START_X+1, y+MAP_START_Y+1); //map start includes border, so + 1
			if(map[y][x]!=nullptr)
				map[y][x]->draw();
		}
	}
	textCustomizer::gotoxy(1, 1);
}

bool World::compareOrganismPointer(const Organism* o1, const Organism* o2)
{
	if (o1->getInitiative() == o2->getInitiative())
	{
		return o1->getAge() > o2->getAge();
	}
	return o1->getInitiative() > o2->getInitiative();
}

void World::simulateTurn()
{
	sort(organisms.begin(), organisms.end(), compareOrganismPointer);

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
	textCustomizer::gotoxy(MAP_START_X, MAP_START_Y);
	for (int x = 0; x < width + 2; x++)
	{
		cout <<BORDER_CHAR;
	}
	textCustomizer::gotoxy(MAP_START_X, MAP_START_Y+height+1);
	for (int x = 0; x < width + 2; x++)
	{
		cout << BORDER_CHAR;
	}
	for (int y = 0; y < height+1; y++)
	{
		textCustomizer::gotoxy(MAP_START_X, MAP_START_Y+y);
		cout << BORDER_CHAR;
	}
	for (int y = 0; y < height + 1; y++)
	{
		textCustomizer::gotoxy(MAP_START_X+width+1, MAP_START_Y+y);
		cout << BORDER_CHAR;
	}
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


void World::saveFile(fstream& f)
{
	int organismCount = organisms.size();
	f << width << " " << height << " " << organismCount << endl;
	for (const Organism* org : organisms) {
		if(org!=nullptr)
			org->save(f);
	}
}
World* World::loadFile(fstream& f,Logger& logger, InputManager& input)
{
	int w, h, size;
	f >> w >> h >> size;

	World* world = new World(w, h);
	vector<Organism*> organisms;

	for (int i = 0; i < size; i++) {
		organisms.push_back(Organism::load(f,*world,logger,input));
	}

	Organism*** map = new Organism** [h];
	for (int y = 0; y < h; y++)
	{
		map[y] = new Organism* [w];
		for (int x = 0; x < w; x++)
		{
			map[y][x] = nullptr;
		}
	}

	for (auto org : organisms)
	{
		if (org != nullptr)
			map[org->getPosition().second][org->getPosition().first] = org;
	}

	world->organisms = organisms;
	world->map = map;

	return world;
}