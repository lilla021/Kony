#include "Cards.h"
Cards::Cards()
{
	cost = 0;
	HowToPlay = "NOTHING TO DISPLAY";
	name = "NO NAME";
	type = "UNKNOWN";
}
Cards::~Cards()
{
}
std::vector <Cards> Cards::shuffleCards(std::vector <Cards> crds) {
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(crds.begin(), crds.end());
	return crds;
}
std::string Cards::getCardName() {
	return name;
}
std::string Cards::getType() {
	return type;
}
int Cards::getCost() {
	return cost;
}
std::string Cards::getHowToPlay() {
	return HowToPlay;
}

void Cards::effects() { //might be used for later assignments
						//
}
LongNeck::LongNeck() {
	name = "LongNeck";
	type = "power card";
	cost = 3;
	HowToPlay = "need two destructions to destroy a Jet.";
}
LongNeck::~LongNeck() {}
void LongNeck::effects() { //might be used for later assignments
						   //
}
CanOpener::CanOpener() {
	name = "Can Opener";
	type = "power card";
	cost = 4;
	HowToPlay = "need two destructions to destroy a Jet.";
}
CanOpener::~CanOpener() {}
void CanOpener::effects() { //might be used for later assignments
							//
}
PhoenixBlood::PhoenixBlood() {
	name = "Phoenix Blood";
	type = "power card";
	cost = 4;
	HowToPlay = "need two destructions to destroy a Jet.";
}
PhoenixBlood::~PhoenixBlood() {}
void PhoenixBlood::effects() { //might be used for later assignments
							   //
}
Stomp::Stomp() {
	name = "Stomp";
	type = "power card";
	cost = 4;
	HowToPlay = "need two destructions to destroy a Jet.";
}
Stomp::~Stomp() {}
void Stomp::effects() { //might be used for later assignments
						//
}
ChinaTownRegular::ChinaTownRegular() {
	name = "China Town Regular";
	type = "power card";
	cost = 3;
	HowToPlay = "need two destructions to destroy a Jet.";
}
ChinaTownRegular::~ChinaTownRegular() {}
void ChinaTownRegular::effects() { //might be used for later assignments
								   //
}
TrashThrower::TrashThrower() {
	name = "TrashThrower";
	type = "power card";
	cost = 5;
	HowToPlay = "Monsters you attack lose 1 energy.";
}
TrashThrower::~TrashThrower() {}
void TrashThrower::effects() { //might be used for later assignments
							   //
}
TrophyHuner::TrophyHuner() {
	name = "TrophyHuner";
	type = "power card";
	cost = 5;
	HowToPlay = "gain 1 victory each time you destroy a Unit.";
}
TrophyHuner::~TrophyHuner() {}
void TrophyHuner::effects() { //might be used for later assignments
							  //
}
Regeneration::Regeneration() {
	name = "Regeneration";
	type = "power card";
	cost = 5;
	HowToPlay = "gain 1 victory each time you destroy a Unit.";
}
Regeneration::~Regeneration() {}
void Regeneration::effects() { //might be used for later assignments
							   //
}
Drain::Drain() {
	name = "Drain";
	type = "power card";
	cost = 4;
	HowToPlay = "gain 1 victory each time you destroy a Unit.";
}
Drain::~Drain() {}
void Drain::effects() { //might be used for later assignments
						//
}
Overload::Overload() {
	name = "Overload";
	type = "power card";
	cost = 0;
	HowToPlay = "gain 1 victory each time you destroy a Unit.";
}
Overload::~Overload() {}
void Overload::effects() { //might be used for later assignments
						   //
}

StatueOfLiberty::StatueOfLiberty() {
	name = "Statue of Liberty";
	type = "special";
	cost = 0;
	HowToPlay = "take this card when you....etc";
}
StatueOfLiberty::~StatueOfLiberty() {}
void StatueOfLiberty::effects() {
}
Superstar::Superstar() {
	name = "Superstart";
	type = "special";
	cost = 0;
	HowToPlay = "take this card when you....etc";
}
Superstar::~Superstar() {}
void Superstar::effects() {
}

