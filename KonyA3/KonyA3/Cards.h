#pragma once
#include <string>
#include <iostream>
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

class Cards
{
public:
	Cards();
	virtual ~Cards();
	std::string getCardName();
	std::string getType();
	std::string getHowToPlay();
	int getCost();
	std::vector <Cards> shuffleCards(std::vector <Cards> crds);
	virtual void effects(); //might be used for later assignments
protected:
	int cost; //Set initially; never change.
	std::string name; //Set initially; never change.
	std::string type; //Set initially; never change.
	std::string HowToPlay; //Set initially; never change.
};
//we might implement MORE Cards later.
class LongNeck : public Cards {
public:
	LongNeck();
	virtual ~LongNeck();
	virtual void effects();
};
class TrashThrower : public Cards {
public:
	TrashThrower();
	virtual ~TrashThrower();
	virtual void effects();
};
class TrophyHuner : public Cards {
public:
	TrophyHuner();
	virtual ~TrophyHuner();
	virtual void effects();
};
class CanOpener : public Cards {
public:
	CanOpener();
	virtual ~CanOpener();
	virtual void effects();
};
class PhoenixBlood : public Cards {
public:
	PhoenixBlood();
	virtual ~PhoenixBlood();
	virtual void effects();
};
class Stomp : public Cards {
public:
	Stomp();
	virtual ~Stomp();
	virtual void effects();
};
class ChinaTownRegular : public Cards {
public:
	ChinaTownRegular();
	virtual ~ChinaTownRegular();
	virtual void effects();
};
class Regeneration : public Cards {
public:
	Regeneration();
	virtual ~Regeneration();
	virtual void effects();
};
class Drain : public Cards {
public:
	Drain();
	virtual ~Drain();
	virtual void effects();
};
class Overload : public Cards {
public:
	Overload();
	virtual ~Overload();
	virtual void effects();
};
class StatueOfLiberty : public Cards {
public:
	StatueOfLiberty();
	virtual ~StatueOfLiberty();
	virtual void effects();
};
class Superstar : public Cards {
public:
	Superstar();
	virtual ~Superstar();
	virtual void effects();
};


