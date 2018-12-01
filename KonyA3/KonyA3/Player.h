#pragma once
#include "Monsters.h"
#include "Vertex.h"
#include "Tokens.h"
#include "Dice.h"
#include "EnergyCubes.h"
#include "Cards.h"
#include "Map.h"
#include "Tiles.h"
#include "Behavior.h"
#include "PhaseObserver.h"
#include "StatsObserver.h"
#include "DiceObserver.h"
#include "CardObserver.h"
class Dice;
class Behavior;
using namespace std;

class Player : public PhaseObserver, public StatsObserver, public DiceObserver, public CardObserver
{
public:
	Player();
	~Player();
	Player(Behavior* beh);
	//When loading from a file that has all the player information stored in it
	//Player(int id, [type] monster, Vertex reg, vector <Dice> die, vector <Type Cards> cards, int nrg, int vp, int lp);
	friend class Dice;
	//friend class Behavior;

	// MUTATORS
	void setPlayerId(int id);
	//FIXXX
	void setMonster(Monsters* mons);//fine, choose monster needs to reference map
	void setLifePoints(int lp);//access from monster instead
	void setVictoryPoints(int vp);//access from monster instead
	void setFirstTurn(bool turn);
	//void setMap(Map*);
	void setEnergyPoints(int nrg);
	void setRegion(Vertex reg);
	void setBlDice(vector <Dice> bl);
	void setGrDice(vector <Dice> gr);
	void setTokens(vector <Tokens> tok);
	//void setEnergyCubes(EnergyCubes cubes);//i think needs to be a vector of energy cubes
	void setCards(vector <Cards> crds);
	void setActivity(bool set);
	void setSuperStar(bool set);
	void setStatue(bool set);
	void setDestroy(bool set);
	void setCanBuy(bool set);
	void setRegionId(int set);
	void setBlackcountAttack(vector <Dice> vDice); // i added
	void setGreencountAttack(vector <Dice> vDice);
	void setTotalAttack(int bAttack, int gAttack);
	void setCardsFrMap(bool set);
	void setCardsFrHand(bool set);

	vector <Cards> getVCardsFrMap();

	void setVCardsFrMap(Map* myMap);

	//ACCESSORS
	int getPlayerId();

	Monsters* getMonster();
	string getMonsterName();
	int getLifePoints();
	int getVictoryPoints();
	int getRegionId();
	int getEnergyPoints();
	bool getActivity();
	bool getSuperStar();
	bool getStatue();
	bool getDestroy();
	bool getFirstTurn();
	bool getCanBuy();
	int getBlackcountAttack();  // i added
	int getGreencountAttack();
	int getTotalAttack();
	Vertex getRegion();
	vector <Dice> getBlDice();
	vector <Dice> getGrDice();
	vector <Tokens> getTokens();
	//EnergyCubes getEnergyCubes();
	vector <Cards> getCards();

	vector<Vertex> getRegionsVisited(vector<Player*> pls);
	//void displayMonsterStats();
	virtual void moveToManhattan(Map* myMap, string zoneName);
	virtual void moveUp(Map* myMap);
	//Game Piece related
	void displayTokens();
	void displayCubes();

	//Map* myMap;

	vector <Dice> blackDice;
	vector <Dice> greenDice;
	vector <Tokens> tokens;
	//EnergyCubes energyCubes;
	vector <Cards> cards;
	void setBehavior(Behavior* someBehavior);
	void executeRollDice(Player* p);
	void executeResolveDice(Map* myMap, Player* p);
	void executeMove(Map* myMap, Player* p);
	void executeBuyCards(Map* myMap, Player* p);
	void executeChooseMonster(Map* myMap, Player* p);
	void executeSetFirstPosition(Map* myMap, Player* p);
	void executeDisplayStats(Player* p);
	//void executeDisplayDice(Player* p);

	//void contextInterface();
	void UpdatePhase(string action);
	void displayPhase(string action);

	void UpdateStats();
	void displayMonsterStats();

	void UpdateDice();
	void displayDice();

	void UpdateCard();


	//void UpdateCard(Map * myMap);
	//void displayCards(Map * myMap);
	void displayCards();
	vector <Cards> vCardsFrMap; 
	bool cardsFrMap;
	bool cardsFrHand;
	
	int rollCounter;
	bool isTurn;
	int keepTracker = 0;
	
private:
	//Map* myMap;
	int playerId;
	//access through monster object through map
	int lifePoints;
	int victoryPoints;
	int energyPoints;
	int regionId;
	Monsters* monster;
	Vertex ownsRegion;
	int startBlackAmountAttack; // I added
	int startGreenAmountAttack;
	int totalAttack;
	bool active;
	bool superStar;
	bool statue;
	bool destroy;
	bool firstTurn;
	bool canBuy;
	
	//Members for future functionalities
	

	Behavior* behavior;

	Behavior*_subjectPhase;
	Behavior*_subjectStats;
	Behavior*_subjectDice;
	Behavior*_subjectCard;

};

