#include "Organism.h"
#include <iostream>
#include "Animal.h"

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
			//delete map[y][x];
			map[y][x] = nullptr;
		}
		//delete[] map[y];
		map[y] = nullptr;
	}
	//delete[] map;
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
	textCustomizer::gotoxy(1, 15);
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


void World::saveFile(FILE* f)
{
	fwrite(&width, sizeof(int), 1, f);
	fwrite(&height, sizeof(int), 1, f);
	int organismCount = organisms.size();
	fwrite(&organismCount, sizeof(int), 1, f); 

	for (const Organism* org : organisms) {
		if(org!=nullptr)
			org->save(f);
	}

	for(int y = 0; y < height; y++)
	{
		for(int x = 0;  x< width; x++)
		{
			Organism* org = map[y][x];
			fwrite(org, sizeof(Organism), 1, f); 
		}
	}
}
World* World::loadFile(FILE* f,Logger& logger, InputManager& input)
{
	int w, h;
	fread(&w, sizeof(int), 1, f);
	fread(&h, sizeof(int), 1, f);

	World* world = new World(w, h);

	int organismCount;
	vector<Organism*> organisms;
	
	fread(&organismCount, sizeof(int), 1, f);

	for (int i = 0; i < organismCount; i++) {
		organisms.push_back(Organism::load(f,*world,logger,input));
	}

	Organism*** map = new Organism * *[h];
	for (int y = 0; y < h; y++)
	{
		map[y] = new Organism * [w];
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