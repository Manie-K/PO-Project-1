#include "Organism.h"
#include "OrganismIncludeList.h"
#include <fstream>

using namespace std;

Organism::Organism(World& w, Logger& l, const int s, const int i, const string species,const pair<int, int> pos)
	:world(w),logger(l),strenght(s),initiative(i),age(0),species(species)
{
	try {
		if (pos.first < 0 || pos.second < 0 || pos.first >= world.getWidth() || pos.second >= world.getHeight())
			throw out_of_range("Creating organism outside of map!");
	}
	catch(exception& e){
		cerr << "Error: " << e.what() << endl;
	}
	position = pos;
	w.getOrganisms().push_back(this);
	w.getOrganismAtPos(pos) = this;
};
Organism::~Organism() {};

int Organism::getStrenght() const { return strenght; };
int Organism::getInitiative() const { return initiative; };
int Organism::getAge() const { return age; };
string Organism::getSpecies() const { return species; }
pair<int, int> Organism::getPosition() { return position; };

void Organism::setAge(int age) { this->age = age; }
void Organism::setStrenght(int strenght) { this->strenght = strenght; }
void Organism::setPosition(pair<int, int> pos) { this->position = pos; }

void Organism::killOrganism(Organism* victim)
{
	world.getOrganismAtPos(victim->getPosition()) = nullptr;
	replace(world.getOrganisms().begin(), world.getOrganisms().end(), victim, static_cast<Organism*>(nullptr));
}

void Organism::save(fstream& f)const
{
	f << strenght <<" " << age << " " << species << " " << position.first << " " << position.second << endl;
}
Organism* Organism::load(fstream& f, World& wor, Logger& log, InputManager& input)
{
	int s, a, pf, ps;
	string spec;
	f >> s >> a >> spec >> pf >> ps;

	pair<int, int> pos = make_pair<int, int>((int)pf, (int)ps);
	if (spec == "Wolf")
		return new Wolf(wor, log, pos, s);
	if (spec == "Sheep")
		return new Sheep(wor, log, pos, s);
	if (spec == "Fox")
		return new Fox(wor, log, pos, s);
	if (spec == "Turtle")
		return new Turtle(wor, log, pos, s);
	if (spec == "Antelope")
		return new Antelope(wor, log, pos, s);
	if (spec == "Human")
		return new Human(wor, log,input, pos, s);
	if (spec == "Grass")
		return new Grass(wor, log, pos);
	if (spec == "Dandelion")
		return new Dandelion(wor, log, pos);
	if (spec == "Guarana")
		return new Guarana(wor, log, pos);
	if (spec == "WolfBerries")
		return new WolfBerries(wor, log, pos);
	if (spec == "GiantHogweed")
		return new GiantHogweed(wor, log, pos);
	
}