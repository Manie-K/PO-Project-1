#include "Organism.h"

Organism::Organism(World& w, const int s, const int i,
	const pair<int, int> pos) 
	:world(w),strenght(s),initiative(i),age(0)
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
};
Organism::~Organism() {};

int Organism::getStrenght() const { return strenght; };
int Organism::getInitiative() const { return initiative; };
int Organism::getAge() const { return age; };
pair<int, int> Organism::getPosition() { return position; };

bool Organism::operator<(const Organism* other) const
{
	if (initiative == other->getInitiative())
	{
		return age < other->getAge();
	}
	return initiative < other->getInitiative();
}


