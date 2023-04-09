#include "Organism.h"

class Plant : public Organism 
{
protected:
	void action() override {};
public:
	Plant(World& w, const int s, const string species,pair<int, int> pos) :Organism(w, s, 0,species, pos) {};
	~Plant() override {};
};