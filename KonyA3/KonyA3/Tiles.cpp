#include "Tiles.h"
#include <iostream>
using namespace std;
Tiles::Tiles()
{
	IsBuilding = true;
	IsUnit = false;
}
Tiles::~Tiles()
{
}
int Tiles::getTilesTotal() {
	return TilesTotal;
}
void Tiles::SetTilesTotal(int newTotal) {
	TilesTotal = newTotal;
}
bool Tiles::getIsBuilding() {
	return (IsBuilding == true);
}
bool Tiles::getIsUnit() {
	return (IsUnit = true);
}
std::string Tiles::getFace() {
	if (IsBuilding)
		return "Building";
	return "Unit";
}
int Tiles::getDurability()
{
	return durability;
}
bool Tiles::getFlipCheck()
{
	return flip;
}
void Tiles::setFlipCheck(bool set)
{
	flip = set;
}
std::string Tiles::getRewardType() {
	return rewardType;
}
std::vector <Tiles> Tiles::shuffleTiles(std::vector <Tiles> tls) {
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(tls.begin(), tls.end());
	return tls;
}
/*
void Tiles::printTile() {
cout << "name: " << name << ", rewards: " << rewards << ", durability: " << durability << ", reward type: " << rewardType << endl;
}
*/
void Tiles::ReverseTile() {
	IsBuilding = false;
	IsUnit = true;
	name = nameU;
	durability = durabilityU;
	rewardType = rewardTypeU;
}
HighRise1::HighRise1() {
	name = "High Rise";
	TilesTotal = 22;
	rewards = 1;
	durability = 1;
	rewardType = "victory";
	nameU = "Infantry";
	durabilityU = 2;
	rewardTypeU = "life";
	flip = false;
}
HighRise1::~HighRise1() {
}
HighRise2::HighRise2() {
	name = "High Rise";
	TilesTotal = 8;
	rewards = 2;
	durability = 2;
	rewardType = "victory";
	nameU = "Jet";
	durabilityU = 3;
	rewardTypeU = "energy";
	flip = false;
}
HighRise2::~HighRise2() {
}
Hospital2::Hospital2() {
	name = "Hospital";
	TilesTotal = 3;
	rewards = 2;
	durability = 2;
	rewardType = "life";
	nameU = "Jet";
	durabilityU = 3;
	rewardTypeU = "energy";
	flip = false;
}
Hospital2::~Hospital2() {
}
Factory2::Factory2() {
	name = "Factory";
	TilesTotal = 3;
	rewards = 2;
	durability = 2;
	rewardType = "energy";
	nameU = "Jet";
	durabilityU = 3;
	rewardTypeU = "energy";
	flip = false;
}
Factory2::~Factory2() {
}
HighRise3::HighRise3() {
	name = "High Rise";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "victory";
	nameU = "Tank";
	durabilityU = 4;
	rewardTypeU = "victory";
	flip = false;
}
HighRise3::~HighRise3() {
}
Hospital3::Hospital3() {
	name = "Hospital";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "life";
	nameU = "Tank";
	durabilityU = 4;
	rewardTypeU = "victory";
	flip = false;
}
Hospital3::~Hospital3() {
}
Factory3::Factory3() {
	name = "Factory";
	TilesTotal = 3;
	rewards = 3;
	durability = 3;
	rewardType = "energy";
	nameU = "Tank";
	durabilityU = 4;
	rewardTypeU = "victory";
	flip = false;
}
Factory3::~Factory3() {
}

/*
std::vector<Tiles> Tiles::createTiles() {
vector<Tiles> myTiles;
HighRise1 hr1; //22
HighRise2 hr2; //8
HighRise3 hr3; //3
Hospital2 hos2; //3
Hospital3 hos3; //3
Factory2 fac2; //3
Factory3 fac3; //3
for (int i = 0; i < 22; i++) {
myTiles.push_back(hr1);
}
for (int i = 1; i <= 8; i++) {
myTiles.push_back(hr2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hr3);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hos2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(hos3);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(fac2);
}
for (int i = 1; i <= 3; i++) {
myTiles.push_back(fac3);
}
return myTiles;
}
void Tiles::print() {
vector<Tiles> t;
t = Tiles::createTiles();
for (int i = 0; i < t.size(); i++)
cout << t.at(i).getInfo() << endl;
}
*/

void Tiles::getInfo() {
	cout << name << " - Reward: " << rewards << " " << getRewardType() << " Durability: " << durability << " durability \n" << endl;
	//ReverseTile();
	//return "a" +name+ ", it has " +rewards; !!
	//cout<<"On the other face, it is \" " + name + ", it has "<<rewards <<" " + getRewardType() + " and "<<durability<<" durability." << endl;
}

