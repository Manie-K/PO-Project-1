#include "Animal.cpp"
#include <iostream>

using namespace std;

class Wolf : public Animal {
public:
	Wolf(World& w, pair<int,int> pos) :Animal(w, 9, 5, pos) {};
	void draw() override {
		textcolor(RED);
		cout << WOLF_CHAR;
		textcolor(WHITE);
	}
};