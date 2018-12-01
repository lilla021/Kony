#pragma once
#include "Player.h"
#include "Dice.h"
#include "Map.h"
#include "Tiles.h"
#include "Cards.h"
#include "PhaseSubject.h"
#include "StatsSubject.h"
#include "DiceSubject.h"
#include "CardSubject.h"
#include <vector>
class Map;
class Player;
class Behavior : public PhaseSubject, public StatsSubject, public DiceSubject, public CardSubject
{
public:
	Behavior();

	//virtual void execute(Player* p) = 0;
	virtual void chooseMonster(Map* myMap, Player* p) = 0;//point to map
	virtual void setFirstPosition(Map* myMap, Player* p) = 0;
	virtual void rollDice(Player* p) = 0;
	virtual void resolveDice(Map* myMap, Player* p) = 0;
	virtual void move(Map* myMap, Player* p) = 0;
	virtual void buyCards(Map* myMap, Player* p) = 0;
	virtual void displayStats(Player* p) = 0;
	virtual void displayDice(Player* p) = 0;
	virtual void displayCards() = 0;

	// Helper METHODS

	virtual void addEnergy(Player* p, int amount); //in players maybe?
	

	~Behavior();
};


