#include "Behavior.h"

Behavior::Behavior()
{
}

Behavior::~Behavior()
{
}
/////////////THIS DISPLAYS BLACK DICE, NEED TO MAKE ONE FOR GREEN DICE
/*void Behavior::displayDice(Player* p)
{
	for (size_t i = 0; i < p->getBlDice().size(); i++) 
	{
		cout << "Dice " << i + 1 << ": " << p->getBlDice()[i].getResult() << endl;
	}
}*/



void Behavior::addEnergy(Player* p, int amount)
{
	int energy = p->getEnergyPoints() + amount;
	p->setEnergyPoints(energy);
}


