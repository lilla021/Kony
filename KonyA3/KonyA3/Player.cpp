#include "Player.h"
#include "Vertex.h"
#include "Map.h"
#include <random>
class Map;
using namespace std;

//CONSTRUCTORS
Player::Player()
{
	playerId;
	monster;
	ownsRegion;
	energyPoints = 0;
	blackDice;
	greenDice;
	tokens;
	//energyCubes;
	cards;
	cardsFrMap;
	startBlackAmountAttack; //I added
	startGreenAmountAttack;
	totalAttack;
	Dice blackOne;
	Dice blackTwo;
	Dice blackThree;
	Dice blackFour;
	Dice blackFive;
	Dice blackSix;
	blackDice.push_back(blackOne);
	blackDice.push_back(blackTwo);
	blackDice.push_back(blackThree);
	blackDice.push_back(blackFour);
	blackDice.push_back(blackFive);
	blackDice.push_back(blackSix);
	Dice greenOne;
	Dice greenTwo;
	greenDice.push_back(greenOne);
	greenDice.push_back(greenTwo);

	active = true;
	destroy = true;
	firstTurn = true;
	canBuy = true;
	isTurn = false;
	cardsFrMap = true;
	cardsFrHand = false;
	behavior = 0;
	keepTracker = 0;

}
Player::~Player() {
	//delete monster;
	monster = NULL;
	//delete behavior;
	behavior = NULL;
	_subjectDice->DetachDice(this);
	_subjectStats->DetachStats(this);
	_subjectPhase->DetachPhase(this);
	_subjectCard->DetachCard(this);
}
Player::Player(Behavior* beh)
{
	playerId;
	monster;
	ownsRegion;
	energyPoints = 0;
	blackDice;
	greenDice;
	tokens;
	//energyCubes;
	cards;
	cardsFrMap;
	//myMap = map;
	startBlackAmountAttack; //I added
	startGreenAmountAttack;
	totalAttack;
	Dice blackOne;
	Dice blackTwo;
	Dice blackThree;
	Dice blackFour;
	Dice blackFive;
	Dice blackSix;
	blackDice.push_back(blackOne);
	blackDice.push_back(blackTwo);
	blackDice.push_back(blackThree);
	blackDice.push_back(blackFour);
	blackDice.push_back(blackFive);
	blackDice.push_back(blackSix);
	Dice greenOne;
	Dice greenTwo;
	greenDice.push_back(greenOne);
	greenDice.push_back(greenTwo);

	active = true;
	destroy = true;
	firstTurn = true;
	canBuy = true;
	isTurn = false;
	cardsFrMap = true;
	cardsFrHand = false;
	behavior = beh;
	keepTracker = 0;


}
/*Eventually when loading from file
Player::Player(int id, Monsters mons, Vertex ownsReg, int nrg, vector <Dice> blDice, vector <Dice> grDice, vector <Cards> crds, vector <Tokens> tok, vector <EnemeyCubes> nme, bool turn)
{
playerId = id;
monster = mons;
ownsRegion = ownsReg;
energyPoints = nrg;
blackDice = blDice;
greenDice = grDice;
tokens = tok;
enemyCubes = nme;
cards = crds;
isTurn = turn;
}*/
// MUTATORS
void Player::setVCardsFrMap(Map* myMap)
{
	vCardsFrMap = myMap->getCards();
}
void Player::executeRollDice(Player* p)
{
	return behavior->rollDice(p);
}
void Player::executeResolveDice(Map* myMap, Player* p)
{
	return behavior->resolveDice(myMap, p);
}
void Player::executeMove(Map* myMap, Player* p)
{
	return behavior->move(myMap, p);
}
void Player::executeBuyCards(Map* myMap, Player* p)
{
	return behavior->buyCards(myMap, p);
}
void Player::executeChooseMonster(Map* myMap, Player* p)
{
	return behavior->chooseMonster(myMap, p);
}
void Player::executeSetFirstPosition(Map* myMap, Player* p)
{
	return behavior->setFirstPosition(myMap, p);
}
void Player::setBehavior(Behavior* someBehavior)
{
	behavior = someBehavior;
}
void Player::setCanBuy(bool set)
{
	canBuy = set;
}
bool Player::getCanBuy()
{
	return canBuy;
}
int Player::getRegionId()
{
	return regionId;
}
void Player::setRegionId(int set)
{
	regionId = set;
}
/*void Player::setMap(Map*)
{
Map* getInstance();
}*/
void Player::executeDisplayStats(Player* p)
{
	return behavior->displayStats(p);
}
void Player::displayMonsterStats()
{
	cout << endl << getMonsterName();
	cout << endl << "Life points: ";
	cout << getLifePoints();
	cout << endl << "Victory points: ";
	cout << getVictoryPoints();
	if (!getRegion().getName().empty()) {
		cout << endl << "Region: ";
		cout << getRegion().getName() << endl;
	}
	else {
		cout << endl;
	}

}
void Player::setPlayerId(int id)
{
	playerId = id;
	_subjectPhase = behavior;
	_subjectStats = behavior;
	
	_subjectDice = behavior;
	_subjectDice->AttachDice(this);

	_subjectPhase->AttachPhase(this, this->getPlayerId());
	_subjectStats->AttachStats(this);
	
	_subjectCard = behavior;
	_subjectCard->AttachCard(this);
	


}
void Player::setMonster(Monsters* mons)
{
	monster = mons;
}
void Player::setLifePoints(int lp)
{
	monster->setLPoints(lp);
}
void Player::setVictoryPoints(int vp)
{
	monster->setVPoints(vp);
}
void Player::setEnergyPoints(int nrg)
{
	energyPoints = nrg;
}
void Player::setBlDice(vector <Dice> bl)
{
	blackDice = bl;
}
void Player::setGrDice(vector <Dice> gr)
{
	greenDice = gr;
}
void Player::setRegion(Vertex reg)
{
	ownsRegion = reg;
}
void Player::setTokens(vector <Tokens> tok)
{
	tokens = tok;
}
//void Player::setEnergyCubes(EnergyCubes nmeCubes)
//{
//energyCubes = nmeCubes;
//}
void Player::setCards(vector <Cards> crds)
{
	cards = crds;
}
void Player::setActivity(bool set)
{
	active = set;
}
void Player::setSuperStar(bool set)
{
	superStar = set;
}
void Player::setStatue(bool set)
{
	statue = set;
}
void Player::setDestroy(bool set)
{
	destroy = set;
}
void Player::setFirstTurn(bool turn)
{
	firstTurn = turn;
}
void Player::setBlackcountAttack(vector <Dice> vDice) {
	int countAttack = 0;
	for (size_t i = 0; i < vDice.size(); i++) {
		vDice[i].roll();
		if (vDice[i].getResult() == "Attack") {
			countAttack++;
		}
	}
	cout << "Number of Attacks counted for the 6 Black Dice " << countAttack << endl;
	startBlackAmountAttack = countAttack;
}
void Player::setGreencountAttack(vector <Dice> vDice) {
	int countAttack = 0;
	for (size_t i = 0; i < vDice.size(); i++) {
		vDice[i].roll();
		if (vDice[i].getResult() == "Attack") {
			countAttack++;
		}
	}
	cout << "Number of Attacks counted for the 2 Green Dice " << countAttack << endl;
	startGreenAmountAttack = countAttack;
}
void Player::setTotalAttack(int bAttack, int gAttack) {
	totalAttack = bAttack + gAttack;
}
void Player::setCardsFrMap(bool set)
{
	cardsFrMap = set;
}
void Player::setCardsFrHand(bool set)
{
	cardsFrHand = set;
}

//ACCESSORS
int Player::getPlayerId()
{
	return playerId;
}
Monsters* Player::getMonster()
{
	return monster;
}
string Player::getMonsterName()
{
	return monster->getMonsName();
}
int Player::getLifePoints()
{
	return monster->getLPoints();
}
int Player::getVictoryPoints()
{
	return monster->getVPoints();
}
int Player::getEnergyPoints()
{
	return energyPoints;
}
vector <Dice> Player::getBlDice()
{
	return blackDice;
}
vector <Dice> Player::getGrDice()
{
	return greenDice;
}
Vertex Player::getRegion()
{
	return ownsRegion;
}
vector <Tokens> Player::getTokens()
{
	return tokens;
}
//EnergyCubes Player::getEnergyCubes()
//{
// return energyCubes;
//}
vector <Cards> Player::getCards()
{
	return cards;
}
vector <Cards> Player::getVCardsFrMap()
{
	return vCardsFrMap;
}
bool Player::getActivity()
{
	return active;
}
bool Player::getSuperStar()
{
	return superStar;
}
bool Player::getStatue()
{
	return statue;
}
bool Player::getDestroy()
{
	return destroy;
}
bool Player::getFirstTurn()
{
	return firstTurn;
}
int Player::getBlackcountAttack() {
	return startBlackAmountAttack;
}
int Player::getGreencountAttack() {
	return startGreenAmountAttack;
}
int Player::getTotalAttack() {
	return totalAttack;
}


//          GAME PIECE RELATED

void Player::displayTokens()
{
	cout << "You have the following tokens: " << endl;
	for (size_t i = 0; i < tokens.size(); i++)
	{
		cout << tokens[i].getTokenName() << endl;
	}
}

void Player::displayCubes()
{
	cout << endl << "You have " << energyPoints << " energy cubes." << endl;
}

vector<Vertex> Player::getRegionsVisited(vector<Player*> pls) {
	vector<Vertex> regionsVisited;
	for (int i = 0; i < pls.size(); i++)
	{
		regionsVisited.push_back(pls[i]->getRegion());
	}
	return regionsVisited;
}

void Player::moveToManhattan(Map* myMap, string zoneName)
{
	//string zoneName;
	int destination;
	for (int i = 0; i < myMap->getGraph().getZones().size(); i++)
	{
		if (myMap->getGraph().getZones().at(i).getName().compare(zoneName) == 0)
			destination = myMap->getGraph().getZones().at(i).getID();
	}
	myMap->getGraph().visitNode(destination, this->getRegion().getID());
	this->setRegion(myMap->getGraph().findVertexById(destination));
}
void Player::moveUp(Map* myMap)
{
	int destination = myMap->getGraph().getUpperManhattan(this->getRegion().getID());
	if (destination != 0) {
		this->setRegion(myMap->getGraph().findVertexById(destination));
		myMap->getGraph().visitNode(destination, this->getRegion().getID());
		cout << endl << this->getMonsterName() << " has been placed in " << this->getRegion().getName() << endl;
	}
	else {
		cout << endl << this->getMonsterName() << " is still in " << this->getRegion().getName() << endl;
	}
}
void Player::UpdateStats()
{
	displayMonsterStats();
};

void Player::UpdatePhase(string action)
{
	displayPhase(action);
};

void Player::displayPhase(string action)
{
	cout << endl << "Player " << this->getPlayerId() << " : " << action << " STEP" << endl;
};

void Player::UpdateDice()
{
	displayDice();
};

void Player::displayDice()
{
	srand(time_t(0));
	if (this->rollCounter == 0)
	{

	}
	else
	{
		
		if (this->rollCounter == 4)
		{
	
			cout << endl << "Player " << this->getPlayerId() << endl << "Roll " << (this->rollCounter) - 1 << endl << "You rolled: " << endl;
			for (size_t i = 0; i < this->getBlDice().size(); i++)
			{
				cout << "Dice " << i + 1 << ": " << this->getBlDice()[i].getResult() << endl;

			}
			
			//this->isTurn = false;
			
			
		}
		
		if(this->rollCounter != 4)
		{
			
			if ((this->keepTracker != 6))
			{
				cout << endl << "**DICE EFFECTS**" << endl;
				cout << "Energy - One green cube is obtained for energy you rolled." << endl;
				cout << "Attack - Lose one heart Point.If you are Mahattan, damages all the monster outside Manhattan. If your are not in Manhattan, damages all the monster on Mahattan" << endl;
				cout << "Heal - Gain one lifeline" << endl;
				cout << "Destruction - Gain a point to destroy a building" << endl;
				cout << "Celebrity - Gain a point to get acess to a superstar card" << endl;
				cout << "Ouch! - Suffer 1 damage per unit tile on your borough" << endl;
			}
			cout << endl << "Player " << this->getPlayerId() << endl << "Roll " << this->rollCounter << endl << "You rolled: " << endl;
			//srand(time_t(0));
			for (size_t i = 0; i < this->getBlDice().size(); i++)
			{
				
				if ((this->rollCounter == 1) || (this->keepTracker == 6))
				{
					
					this->blackDice[i].roll();
					cout << endl << "Dice " << i + 1 << ": " << this->blackDice[i].getResult();
					
					//break;
				}
				if ((this->keepTracker != 6) && (this->rollCounter == 2) || (this->rollCounter == 3))
				{
					if (this->blackDice[i].getRollAgain() == true)
					{
						
						this->blackDice[i].roll();
						cout << endl << "New roll - Dice " << i + 1 << ": " << this->blackDice[i].getResult();
					}
					if (this->blackDice[i].getRollAgain() == false)
					{
						cout << endl << "Previous roll - Dice " << i + 1 << ": "
							<< this->blackDice[i].getResult();
					}
				}
			
			}
			//this->isTurn = false;
			
		}
		

	}
};
void Player::UpdateCard()
{
	displayCards();
};


void Player::displayCards()
{
	if ((this->cardsFrMap == false) && (this->cardsFrHand == true) && (this->isTurn == true))//looking to display players cards
	{
		cout << endl << "You have the following cards: " << endl;
		if (this->cards.size() == 0)
			cout << endl << "N/A" << endl;
		else
		{
			for (size_t i = 0; i < this->cards.size(); i++)
			{
				cout << endl << "Card: " << this->cards[i].getCardName() << " - " << endl
					<< "Description: " << this->cards[i].getHowToPlay() << endl << endl;
			}
		}
	}

	if ((this->cardsFrMap == true) && (this->cardsFrHand == false) && (this->isTurn == true))//if looking to display the maps card options
	{
		for (int i = 0; i < 3; i++)
		{
			if (this->getVCardsFrMap().size() > i)
			{ // to check if we have more than 3 cards on deck

				cout << endl << i + 1 << ". " << this->getVCardsFrMap().at(i).getCardName() << endl
					<< "Description: " << this->getVCardsFrMap().at(i).getHowToPlay() << endl
					<< "Cost: " << this->getVCardsFrMap().at(i).getCost() << endl;
				/*if (this->getVCardsFrMap().at(i).getCardName() == "Overload")
				{
					cout << "Overload ( 0 energy points to buy!)";
				}*/
				if (i == 2)
				{
					cout << endl << "4. If you want to discard/reveal new three cards" << endl;
					break;
				}
			}
			
		}
		
	}

};
/*void Player::displayCard()
{
	cout << endl << "You have: " << endl;
	
	cout << "Card: " << cards[i].getCardName() << " - " <<endl
		<< "Description: " << cards[i].getHowToPlay() << endl;
	
};*/