#include "Organism.h"

class Animal : public Organism 
{
protected:
	void action() override {};
	void collision() override {};
	void draw() override {};
public:
	Animal() {};
	~Animal() override {};
};
