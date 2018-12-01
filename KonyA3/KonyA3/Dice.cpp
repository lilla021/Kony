#include "Dice.h"
using namespace std;
Dice::Dice()
{
	Side1 = "Energy";
	Side2 = "Attack";
	Side3 = "Heal";
	Side4 = "Destruction";
	Side5 = "Celebrity";
	Side6 = "Ouch";
	result;
	rollAgain = false;
}
//MUTATORS
void Dice::setResult(string r)
{
	result = r;
}
void Dice::setRollAgain(bool ans)
{
	rollAgain = ans;
}
// ACCESSORS
string Dice::getResult()
{
	return result;
}
bool Dice::getRollAgain()
{
	return rollAgain;
}

//METHODS
//            ROLL ONE DIE - WORKS
void Dice::roll()
{
	int min = 1; // the min number a die can roll is 1
	int max = 6;// this->dieSize; // the max value is the die size
	int y = rand() % (max - min + 1) + min;
	//int y = rand() % 6 + 1;
	switch (y)
	{
	case 1:
		result = Side1;
		break;
	case 2:
		result = Side2;
		break;
	case 3:
		result = Side3;
		break;
	case 4:
		result = Side4;
		break;
	case 5:
		result = Side5;
		break;
	case 6:
		result = Side6;
		break;
	default:
		cout << "Error Roll" << endl;
	}
}

