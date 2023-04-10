#include "Organism.h"

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
