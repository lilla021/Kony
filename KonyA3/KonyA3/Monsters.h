#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Monsters
{
public:
	Monsters();
	Monsters(string mName);
	~Monsters();
	//MUTATORS
	void setVPoints(int i);
	void setLPoints(int i);
	//ACCESSORS
	int getVPoints();
	int getLPoints();
	string getMonsName();

private:
	string name;
	int victoryPoints;
	int lifePoints;
};

