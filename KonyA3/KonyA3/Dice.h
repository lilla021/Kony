#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
using namespace std;
class Dice
{
public:
	Dice();
	//METHODS
	void roll();
	//MUTATORS
	void setResult(string r);
	void setRollAgain(bool ans);

	//ACCESSORS
	string getResult();
	bool getRollAgain();

private:
	string result;
	bool rollAgain;
	string Side1;
	string Side2;
	string Side3;
	string Side4;
	string Side5;
	string Side6;
};

