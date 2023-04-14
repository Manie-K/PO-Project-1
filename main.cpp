#include "Simulator.h"

using namespace std;

int main()
{
	unsigned int worldWidth, worldHeight;
	cout << "Podaj wymiary swiata (szerokosc  x  wysokosc): ";
	cin >> worldWidth >> worldHeight;

	Simulator simulator(worldWidth,worldHeight); 
	system("cls");
	
	simulator.run();
	
	return 1;
}