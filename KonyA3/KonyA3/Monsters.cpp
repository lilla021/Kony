#include <iostream>
#include <string>
#include "Monsters.h"
Monsters::Monsters()
{
	name;
	lifePoints = 10;
	victoryPoints = 0;
}
Monsters::Monsters(string mName)
{
	name = mName;
	lifePoints = 10;
	victoryPoints = 0;
}
Monsters::~Monsters()
{
}
//MUTATORS
void Monsters::setVPoints(int i)
{
	victoryPoints = i;
}
void Monsters::setLPoints(int i)
{
	lifePoints = i;
}
//ACCESSORS
int Monsters::getVPoints()
{
	return victoryPoints;
}
int Monsters::getLPoints()
{
	return lifePoints;
}
string Monsters::getMonsName()
{
	return name;
}

