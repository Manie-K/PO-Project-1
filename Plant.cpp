#include "Organism.h"

class Plant : public Organism 
{
protected:
	void action() override {};
public:
	Plant() { initiative = 0; };
	~Plant() override {};
};