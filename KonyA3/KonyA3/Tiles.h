#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include<stack>
class Tiles
{
public:
	//int BDurability;
	//int UDurability;
	//int BRewardPoints;
	//int UnitRewardPoints;
	Tiles();
	virtual ~Tiles();
	int getTilesTotal();
	bool getIsBuilding(); //to check if builing; it is SET initially, and can't be set again once it is reversed.
	bool getIsUnit(); // to check if Unit; it is SET within ReverseTile() method.
	std::string getFace(); // to see if it is a bulding or a unit.
	std::string getRewardType(); // it is fixed and no need to SET
	void SetTilesTotal(int newTotal);
	void getInfo();
	int getDurability();
	bool getFlipCheck();
	void setFlipCheck(bool set);
	void ReverseTile(); // convert a building into a Unit; i.e SET a UNIT
	std::vector <Tiles> shuffleTiles(std::vector <Tiles> tls);
	//void printTile();
	std::string getName() { return name; }
	/*
	int b1 = 22;
	int b2 = 8;
	int h2 = 3;
	int f2 = 3;
	int b3 = 3;
	int h3 = 3;
	int f3 = 3;
	*/
	std::string name;
protected:
	//std::string name;
	bool IsBuilding; // set initially true
	bool IsUnit; // set initially false
	bool flip;
	int TilesTotal; //total nummber of a tile
	int rewards; //reward a tile gives
	std::string rewardType; // would be a victory, life, or energy.
	int durability; // in order to be destroyed
					//////////////////////////////
	std::string nameU;
	std::string rewardTypeU; // would be a victory, life, or energy, UNIT
	int durabilityU; // in order to be destroyed, UNIT
};
class HighRise1 : public Tiles {
public:
	HighRise1();
	virtual ~HighRise1();
	//void ReverseTile();
};
class HighRise2 : public Tiles {
public:
	HighRise2();
	virtual ~HighRise2();
	//void ReverseTile();
};
class Hospital2 : public Tiles {
public:
	Hospital2();
	virtual ~Hospital2();
	//void ReverseTile();
};
class Factory2 : public Tiles {
public:
	Factory2();
	virtual ~Factory2();
	//void ReverseTile();
};
class HighRise3 : public Tiles {
public:
	HighRise3();
	virtual ~HighRise3();
	// void ReverseTile();
};
class Hospital3 : public Tiles {
public:
	Hospital3();
	virtual ~Hospital3();
	// void ReverseTile();
};
class Factory3 : public Tiles {
public:
	Factory3();
	virtual ~Factory3();
	//void ReverseTile();
};

