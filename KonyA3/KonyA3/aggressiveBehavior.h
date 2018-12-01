#pragma once
#include "Behavior.h"
class aggressiveBehavior :public Behavior
{
public:
	aggressiveBehavior();
	virtual void setFirstPosition(Map* myMap, Player* p);
	virtual void chooseMonster(Map* myMap, Player* p);
	virtual void rollDice(Player* p);
	virtual void resolveDice(Map* myMap, Player* p);
	virtual void move(Map* myMap, Player* p);
	virtual void buyCards(Map* myMap, Player* p);
	virtual void displayStats(Player* p);
	virtual void displayDice(Player* p);
	virtual void displayCards();
	~aggressiveBehavior();
};


