
#include "aggressiveBehavior.h"
#include <iostream>
class Player;
class Map;
using namespace std;

aggressiveBehavior::aggressiveBehavior()
{
}

void aggressiveBehavior::setFirstPosition(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "\nCHOOSE STARTING REGION");
	vector<Vertex> regionsVisited = p->getRegionsVisited(myMap->getPlayers());
	vector<int> regAvail = myMap->graph.availableRegions(regionsVisited);
	for (int i = 0; i < regAvail.size(); i++)
	{
		cout << "(" << regAvail.at(i) << ") ";
		for (int j = 0; j < myMap->graph.regions.size(); j++)
		{
			if (myMap->graph.regions.at(j).getID() == regAvail.at(i))
			{
				//cout << myMap->regions.at(j).getNameByID(regAvail.at(i)) << endl;
				cout << myMap->graph.regions.at(j).getName();
				break;
			}
		}
	}
	int destination;
	bool wrongNumber = true;
	do {
		//cin >> destination;
		for (int i = 0; i < regAvail.size(); i++)
		{
			destination = regAvail[i];
			if (destination == regAvail.at(i))
			{
				wrongNumber = false;
			}
		}
		if (wrongNumber) {
			cout << endl << "That is an invalid entry." << endl
				<< "You must enter a valid number" << endl;
		}
	} while (wrongNumber);
	cout << endl << destination << endl;
	p->setRegion(myMap->graph.findVertexById(destination));
	myMap->graph.visitNodeFirstTime(destination);
	//NotifyStats(p->getPlayerId())
}
void aggressiveBehavior::chooseMonster(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "\nCHOOSE MONSTER");
	//vector <Monsters*> mnstr = myMap->getMonsters();
	static vector <string> monstersOptions = { "Drakonis", "Mantis", "Rob", "Sheriff", "Kong", "Captain Fish" };
	int value;
	string name;
	size_t size = monstersOptions.size();

	if (size == 6)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1; 
		cout << endl << value << endl;
		//dont need this for aggressive player
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5) && (value != 6))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 5)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		cout << endl << value << endl;
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4) && (value != 5))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 4)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		cout << endl << value << endl;
		/*while ((value != 1) && (value != 2) && (value != 3) && (value != 4))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 3)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		cout << endl << value << endl;
		/*while ((value != 1) && (value != 2) && (value != 3))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 2)
	{
		cout << "Please choose among the following monsters by entering the corresponding number: " << endl;
		for (int i = 0; i < size; i++)
		{
			//if (mnstr[i]->getAvailability() == true)
			cout << endl << i + 1 << ". " << monstersOptions[i];
		}
		cout << endl;
		//automatically select the first monster for each player
		value = 1;
		cout << endl << value << endl;
		/*while ((value != 1) && (value != 2))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "You must enter a valid number." << endl;
		cin >> value;
		cout << endl;
		}*/
		cout << endl << "You chose " << monstersOptions[value - 1] << "!" << endl;
		name = monstersOptions[value - 1];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
	if (size == 1)
	{
		cout << endl << "You will be " << monstersOptions[0] << "!" << endl;
		name = monstersOptions[0];
		for (int i = 0; i < myMap->getMonsters().size(); i++)
		{
			if (name == myMap->getMonsters().at(i)->getMonsName())
				p->setMonster(myMap->getMonsters().at(i));
		}
		//setMonster(mnstr[value - 1]);
		//monstersOptions.erase(monstersOptions.begin() + (value - 1));
		//mnstr[value - 1]->setAvailability(false);
	}
}
//            DICE RELATED

void aggressiveBehavior::rollDice(Player* p)
{
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	NotifyPhase(p->getPlayerId(), "\nROLL DICE");
	srand(time_t(0));
	p->rollCounter = 1;
	p->keepTracker = 0;
	
	while ((p->keepTracker != 6) && (p->rollCounter <= 4))
	{
		//srand(time_t(0));
		//player observer here?
		cout << endl << endl << "**ROLLING DICE**" << endl;
		NotifyDice();
		//cout << endl << "Roll " << p->rollCounter << endl << "You rolled: ";
		/*for (size_t i = 0; i < p->blackDice.size(); i++)
		{
			if (p->rollCounter == 1)
			{
				p->blackDice[i].roll();
				cout << endl << "Dice " << i + 1 << ": " << p->blackDice[i].getResult();
			}
			else
			{
				if (p->blackDice[i].getRollAgain() == true)
				{
					p->blackDice[i].roll();
					cout << endl << "New roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult();
				}
				if (p->blackDice[i].getRollAgain() == false)
				{
					cout << endl << "Previous roll - Dice " << i + 1 << ": "
						<< p->blackDice[i].getResult();
				}
			}
		}*/
		cout << endl;
		char input = NULL;
		p->keepTracker = 0;
		for (size_t i = 0; i < p->blackDice.size(); i++)
		{
			if (p->rollCounter == 3)
			{
				cout << endl << "This was your final roll, therefore you must keep this set of dice." << endl;
				//displayDice(p);
				p->rollCounter = 4;
				NotifyDice();
				cout << endl;
				break;
			}
			cout << endl << "Would you like to keep Dice " << i + 1 << ": " << p->blackDice[i].getResult() << "?";
			cout << endl << "Enter Y or N" << endl << endl;
			if ((p->blackDice[i].getResult() == "Attack") || (p->blackDice[i].getResult() == "Destruction"))
			{
				input = 'y';
				cout << endl << "Y";
				cout << endl << "Keep - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
				p->blackDice[i].setRollAgain(false);
				p->keepTracker++;
			}
			else
			{
				input = 'n';
				cout << endl << "N";
				cout << endl << "Re-roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
				p->blackDice[i].setRollAgain(true);
			}
			/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
			{
			cout << endl << "That is an invalid entry." << endl
			<< "Please enter Y or N" << endl << endl;
			cin >> input;
			}*/
			/*if ((input == 'y') || (input == 'Y'))
			{
			cout << "Keep - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
			p->blackDice[i].setRollAgain(false);
			keepTracker++;
			}*/
			/*if ((input == 'n') || (input == 'N'))
			{
			cout << "Re-roll - Dice " << i + 1 << ": " << p->blackDice[i].getResult() << endl;
			p->blackDice[i].setRollAgain(true);
			}*/
		}
		if (p->keepTracker == 6)
		{
			cout << endl << "You decided to keep all your dice!" << endl << endl;
			//displayDice(p);
			NotifyDice();
			cout << endl;
			//continue;
		}

		p->rollCounter++;
	}
	//return vDie;
}

void aggressiveBehavior::resolveDice(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "\nRESOLVE DICE");
	vector <Player*> plVect = myMap->players;
	cout << endl << "***RESOLVE YOUR DICE***" << endl;
	string res;
	cout << endl << "**DICE EFFECTS**" << endl;
	cout << "Energy - One green cube is obtained for energy you rolled." << endl;
	cout << "Attack - Lose one heart Point.If you are Mahattan, damages all the monster outside Manhattan.If your are not in Manhattan, amges all the monster on Mahattan" << endl;
	cout << "Heal - Gain one lifeline" << endl;
	cout << "Destruction - Gain a point to destroy a building" << endl;
	cout << "Celebrity - Gain a point to get acess to a superstar card" << endl;
	cout << "Ouch! - Suffer 1 damage per unit tile on your borough" << endl;
	int energyCount = 0, attackCount = 0, healCount = 0, desCount = 0, celebCount = 0, ouchCount = 0;
	char input;
	for (size_t i = 0; i < p->blackDice.size(); i++)
	{
		res = p->blackDice[i].getResult();
		if (res == "Energy")
			energyCount++;
		if (res == "Attack")
			attackCount++;
		if (res == "Heal")
			healCount++;
		//can't go over 10 heart points, as well can't gain any lifepoints on Manhattan.
		if (res == "Destruction")
			desCount++;
		if (res == "Celebrity")
			celebCount++;
		if (res == "Ouch")
			ouchCount++;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < p->cards.size(); i++) {
		string cardname = p->cards.at(i).getCardName();
		if (cardname == "Stomp") {
			desCount++;
		}
		if (cardname == "Overload") {
			int points = p->getEnergyPoints();
			points++;
			p->setEnergyPoints(points);
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool allResolved = false;
	cout << endl << "**MONSTER STATS**";
	p->displayMonsterStats();
	p->setCardsFrMap(false);
	p->setCardsFrHand(true);
	NotifyCard();
	p->displayCubes();
	cout << endl << "**YOUR DICE**" << endl;
	cout << "DICE TYPE # OF DICE" << endl;
	if (energyCount != 0)
		cout << "Energy Dice:  " << energyCount << endl;
	if (attackCount != 0)
		cout << "Attack Dice:  " << attackCount << endl;
	if (desCount != 0)
		cout << "Destruction Dice: " << desCount << endl;
	if (healCount != 0)
		cout << "Heal Dice:  " << healCount << endl;
	if (celebCount != 0)
		cout << "Celebrity Dice:  " << celebCount << endl;
	if (ouchCount != 0)
		cout << "Ouch! Dice:  " << ouchCount << endl;

	while (allResolved == false)
	{
		cout << endl << "Which dice would you like to resolve?" << endl
			<< "Enter 'E' for Energy, 'A' for Attack, 'D' for Destruction, 'H' for Heal, 'C' for Celebrity or 'O' for Ouch!" << endl;
		//cin >> input;
		if (attackCount != 0)
		{
			input = 'a';
			cout << endl << "A";
		}
		if (desCount != 0)
		{
			input = 'd';
			cout << endl << "D";
		}
		if (healCount != 0)
		{
			input = 'h';
			cout << endl << "H";
		}
		if (energyCount != 0)
		{
			input = 'e';
			cout << endl << "E";
		}
		if (ouchCount != 0)
		{
			input = 'o';
			cout << endl << "O";
		}
		if (celebCount != 0)
		{
			input = 'c';
			cout << endl << "C";
		}
		/*while ((input != 'e') && (input != 'E') && (input != 'a') && (input != 'A') && (input != 'd') && (input != 'D') && (input != 'h') && (input != 'H') && (input != 'c') && (input != 'C') && (input != 'o') && (input != 'O'))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "Enter 'E' for Energy, 'A' for Attack, 'D' for Destruction, 'H' for Heal, 'C' for Celebrity or 'O' for Ouch!" << endl;
		cin >> input;
		cout << endl;
		}*/
		///////////////////////////////////////////////////////////////////////////////////////////////////////////
		string cardname;
		int cardEffect = 0;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		switch (input)
		{
		case 'e': case 'E':
			if (energyCount == 0)
			{
				cout << "You do not have any Energy dice." << endl;
				break;
			}
			//DONE
			cout << endl << "ENERGY!" << endl;
			addEnergy(p, energyCount);
			p->displayCubes();
			energyCount = 0;
			break;
		case 'a': case 'A':
			if (p->getFirstTurn() == true)
			{
				cout << endl << "You cannot attack on the first turn, these dice will have no effect." << endl;
				attackCount = 0;
				//break;
			}
			if (p->getFirstTurn() != true)
			{
				if (attackCount == 0)
				{
					cout << "You do not have any Attack dice." << endl;
					break;
				}
				//if monster is in manhattan, inflict damage on all other players NOT in manhattan
				cout << endl << "ATTACK!" << endl;
				/////////////////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < p->cards.size(); i++)
				{
					cardname = p->cards.at(i).getCardName();
					if (cardname == "TrashThrower")
					{
						cardEffect = 1;
						p->setVictoryPoints(p->getVictoryPoints() - 1);
						if (p->getVictoryPoints() <= 0)
						{
							p->setVictoryPoints(0);
						}


					}
				}
				////////////////////////////////////////////////////////////////////////////////////////////////
				if (p->getRegion().getName().find("Zone") != string::npos)
				{
					int plcount = 0;
					//vector <Player*> plVect = p->myMap->getPlayers();
					cout << endl << p->getMonsterName() << " you are in Manhattan, therefore you will attack every monster outside of Manhattan." << endl;
					for (int i = 0; i < plVect.size(); i++)
					{
						if (plVect[i]->getRegion().getName().find("Zone") == string::npos)
						{
							if (plVect[i]->getRegion().getName() != "Manhattan")
							{
								int points = plVect[i]->getLifePoints();
								////////////////////////////////////////////////////////////////////////////////////////////
								for (int j = 0; j < plVect[i]->cards.size(); j++)
								{
									//int points = plVect[j]->getLifePoints();//
									string aCard = plVect[i]->cards.at(j).getCardName();//////////////////////DOES THIS MAKE SENSE? cards at j?
									if (aCard == "Drain")
									{
										plVect[i]->setEnergyPoints(plVect[i]->getEnergyPoints() + 2);
									}
									//points = points - (attackCount);////////////////////////////////////////////////////////////////
									//plVect[j]->setLifePoints(points);//
								}
								////////////////////////////////////////////////////////////////////////////////////////////
								points = points - attackCount;////////////////////////////////////////////////////////////////
								plVect[i]->setLifePoints(points);
								if (plVect[i]->getLifePoints() <= 0)
									plVect[i]->setActivity(false);
								if (plVect[i]->getMonsterName() != p->getMonsterName())
								{
									cout << plVect[i]->getMonsterName() << ": -" << attackCount
										<< " : " << plVect[i]->getLifePoints() << " life points remaining" << endl;
								}
								plcount++;
							}
						}
						if (plcount == 0)
						{
							cout << endl << "There are no other players currently in Manhattan.";
							cout << endl << "Your attack dice will have no effect and will be discarded." << endl;
							attackCount = 0;
							break;
						}
					}
					//}
					//if monster is not in manhattan AND there are monsters in manhattan, inflict damage on monsters in manhattan
					//if (p->getRegion().getName().find("Zone") == string::npos)
				}
				else
				{
					int plcount = 0;
					cout << endl << p->getMonsterName() << " You are not in Manhattan, therefore you will attack every monster inside of Manhattan." << endl;
					for (int i = 0; i < myMap->getPlayers().size(); i++)
					{
						if (plVect[i]->getRegion().getName().find("Zone") != string::npos)
						{
							//if (plVect[i]->getRegion().getName() == "Manhattan")
							//{
								int points = plVect[i]->getLifePoints();//
																		////////////////////////////////////////////////////////////////////////////////////////////
								for (int j = 0; j < plVect[j]->cards.size(); j++)
								{
									//int points = plVect[j]->getLifePoints();//
									string aCard = plVect[i]->cards.at(j).getCardName();///
									if (aCard == "Drain")
									{
										plVect[i]->setEnergyPoints(plVect[i]->getEnergyPoints() + 2);
									}
									//points = points - (attackCount);////////////////////////////////////////////////////////////////////////////
									//plVect[j]->setLifePoints(points);
								}
								////////////////////////////////////////////////////////////////////////////////////////////
								//int points = plVect[i]->getLifePoints();
								points = points - attackCount;////////////////////////////////////////////////////////////////////////////
								plVect[i]->setLifePoints(points);
							
								if (plVect[i]->getMonsterName() != p->getMonsterName())
								{
									cout << plVect[i]->getMonsterName() << ": -" << attackCount
										<< " : " << plVect[i]->getLifePoints() << " life points remaining" << endl;
								}
								if (plVect[i]->getLifePoints() <= 0)
									plVect[i]->setActivity(false);
								plcount++;
								
							//}
						}
					}
					if (plcount == 0)
					{
						cout << endl << "There are no monsters in Manhattan.";
						cout << endl << "Your attack dice will have no effect and will be discarded." << endl;
						attackCount = 0;
						break;
					}

				}
			}
			attackCount = 0;
			break;

		case 'h': case 'H':
			if (healCount == 0)
			{
				cout << "You do not have any Heal dice." << endl;
				break;
			}
			cout << endl << "HEAL!" << endl;
			//if player is NOT in manhattan AND lifepoints!=10,  lifepoints++
			if ((p->getRegion().getName().find("Zone") == string::npos) || (p->getLifePoints() != 10))
			{
				//if monster lifepoints ==10, cout << "You are already at max life points";

				if (p->getLifePoints() == 10)
				{
					cout << endl << "You are already at maximum health!" << endl
						<< "(You cannot go over the 10 life point maximum)" << endl;
				}
				else
				{
					int lifePoints = p->getLifePoints() + healCount;
					p->setLifePoints(lifePoints);
					if (p->getLifePoints() > 10)
					{
						//int life = p->getLifePoints() - 10;
						p->setLifePoints(10);
						cout << endl << "You have reached maximum health!" << endl
							<< "(You cannot go over the 10 life point maximum)" << endl;
					}
				}
				cout << endl << "You have " << p->getLifePoints() << " life points." << endl;
			}
			//if monster is in manhattan, cout << "You cannot increase lifepoint when you are in manhattan";
			if ((p->getRegion().getName().find("Zone") != string::npos))
			{
				cout << endl << p->getMonsterName() << " you are in Manhattan, therefore you cannot increase life points!" << endl;
			}
			healCount = 0;
			break;
		case 'c': case 'C':
			if (celebCount == 0)
			{
				cout << "You do not have any Celebrity dice." << endl;
				break;
			}
			cout << endl << "CELEBRITY!" << endl;
			//if celebCount less than 3 AND has no superstar card, nothing happens
			if ((celebCount < 3) && (p->getSuperStar() == false))
			{
				cout << endl << "You have less than 3 celebrity dice, therefore these dice perform no actions." << endl;
			}
			//if has superstar Card, celebCount *= 2;
			if (p->getSuperStar() == true)
			{
				int victoryPoints = p->getVictoryPoints() + (celebCount * 2);
				p->setVictoryPoints(victoryPoints);
				//if (p->getVictoryPoints() >= 20)
				//{
					//p->setVictoryPoints(0);
				//}
				cout << endl << "You currently posses the Superstar Card, therefore for every Celebrity Dice you roll you get double the victory points!" << endl;
				cout << endl << "You have " << p->getVictoryPoints() << " victory points." << endl;
			}
			//if celebCount >= 3 AND has no superstarCard, take superstar card
			if ((celebCount >= 3) && (p->getSuperStar() == false))
			{
				for (int i = 0; i < plVect.size(); i++)
				{
					if (plVect[i]->getSuperStar() == true)
					{
						plVect[i]->setSuperStar(false);
						cout << endl << plVect[i]->getMonsterName() << " looses the Superstar Card!" << endl;
					}
				}
				p->setSuperStar(true);
				int celCount = celebCount - 3;
				int victoryPoints = p->getVictoryPoints() + (celCount * 2);
				p->setVictoryPoints(victoryPoints);
				cout << endl << "You took possesion of the Superstar Card!" << endl
					<< "This will double your victory points for every Celebrity Dice you roll in your future turns" << endl
					<< "[Cost of Superstar Card = 3 Celebrity Dice, all remaining dice (X 2) are added to your victory points]" << endl;
				cout << endl << "You have " << p->getVictoryPoints() << " victory points." << endl;
			}
			celebCount = 0;
			break;
		case 'o': case 'O':
			if (ouchCount == 0)
			{
				cout << "You do not have any Ouch! dice." << endl;
				break;
			}
			cout << endl << "OUCH!" << endl;
			//getMilitaryUnitTiles() in borough player is in (getRegion())
			// for each military unit tile in the region, -1 lifepoint
			if ((p->getRegion().getUnits().size() == 0))
			{
				cout << endl << "There are no unit tiles in this region to be destroyed." << endl;
			}
			if ((p->getRegion().getUnits().size() != 0))
			{
				if (ouchCount == 1)
				{
					int damage = p->getRegion().getUnits().size();
					int lifePoints = p->getLifePoints() - damage;
					p->setLifePoints(lifePoints);
					
					cout << endl << "Only " << p->getMonsterName() << " looses life points!" << endl;
					cout << endl << p->getMonsterName() << ": ";
					cout << endl << "- " << p->getLifePoints() << " life points!" << endl;
					p->displayMonsterStats();
					if (p->getLifePoints() <= 0)
						p->setActivity(false);
				}
				//getMilitaryUnitTiles() in borough player is in (getRegion())
				//for each military unit tile in the region, -1 lifepoint from all players in the region
				//for loop through player vector, pl[i].getRegion()
				//if region is == to the region current player is in
				//pl[i].getLifepoints(), lifepoints -1 for each military unit tile in borough
				if (ouchCount == 2)
				{
					cout << endl << "All monsters suffer damage from the military units in their region!" << endl;
					int damage = p->getRegion().getUnits().size();
					int life;
					for (int i = 0; i < plVect.size(); i++)
					{
						life = plVect[i]->getLifePoints() - damage;
						plVect[i]->setLifePoints(life);

						cout << endl << p->getMonsterName() << ": ";
						cout << endl << "- " << life << " life points!" << endl;
						plVect[i]->displayMonsterStats();
						if (plVect[i]->getLifePoints() <= 0)
							plVect[i]->setActivity(false);
					}
				}
				//if ouchCount == 3
				//all players get attacked by the military unit tiles in their borough
				//-1 lifepoint for each unit tile in the players bourough
				// player becomes defender of the city
				//player obtains statueOfLibertyCard
				//+3 celebrity
				if (ouchCount == 3)
				{
					cout << endl << "All monsters suffer damage from all military units!" << endl;
					int damage = 0;
					for (int j = 0; j < myMap->graph.regions.at(j).getUnits().size(); j++)
					{
						damage = damage + myMap->graph.regions.at(j).getUnits().size();
					}
					int life;
					for (int i = 0; i < plVect.size(); i++)
					{
						life = plVect[i]->getLifePoints() - damage;
						plVect[i]->setLifePoints(life);
						cout << endl << "- " << life << " life points!" << endl;
						plVect[i]->displayMonsterStats();
						if (plVect[i]->getLifePoints() <= 0)
							plVect[i]->setActivity(false);
					}
					if (p->getStatue() == false)
					{
						p->setStatue(true);
						int lifePoints = p->getLifePoints() + 3;
						p->setLifePoints(lifePoints);
						cout << endl << "You took posseion of the Statue Of Liberty Card!" << endl;
						if (p->getLifePoints() > 10)
						{
							//int life = p->getLifePoints() - 10;
							p->setLifePoints(10);
							cout << endl << "You have reached maximum health!" << endl
								<< "(You cannot go over the 10 life point maximum)" << endl;
						}
						cout << endl << "+ " << life << " life points!" << endl;
						p->displayMonsterStats();
					}
					if (p->getStatue() == true)
					{
						int lifePoints = p->getLifePoints() + 3;
						p->setLifePoints(lifePoints);
						cout << endl << "You currently have the Statue Of Liberty Card!" << endl;
						if (p->getLifePoints() > 10)
						{
							//int life = p->getLifePoints() - 10;
							p->setLifePoints(10);
							cout << endl << "You have reached maximum health!" << endl
								<< "(You cannot go over the 10 life point maximum)" << endl;
						}
						cout << endl << "+ " << life << " life points!" << endl;
						p->displayMonsterStats();
					}
				}
			}
			ouchCount = 0;
			break;

		case 'd': case 'D':
			//desCount = 0; //destruction tiles still needs to be fixed
			int counter = 0;
			///check buildings and units on entire map
			for (int j = 0; j < 3; j++)// check all region stacks
			{
				if ((myMap->graph.regions.at(4).tiles.at(j).size() != 0) || (myMap->graph.regions.at(4).getUnits().size() != 0))
				{
					if (myMap->graph.regions.at(4).tiles.at(j).size() != 0)
					{
						if (myMap->graph.regions.at(4).tiles.at(j).back()->getDurability() >= desCount)
						{
							counter++;
						}
					}
					else if (myMap->graph.regions.at(4).getUnits().size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.at(4).getUnits().size(); i++)
						{
							if (myMap->graph.regions.at(4).getUnits().at(i)->getDurability() >= desCount)
							{
								counter++;
							}
						}
					}
				}


				if ((myMap->graph.regions.at(3).tiles.at(j).size() != 0) || (myMap->graph.regions.at(3).getUnits().size() != 0))
				{
					if (myMap->graph.regions.at(3).tiles.at(j).size() != 0)
					{
						if (myMap->graph.regions.at(3).tiles.at(j).back()->getDurability() >= desCount)
						{
							counter++;
						}
					}
					else if (myMap->graph.regions.at(3).getUnits().size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.at(3).getUnits().size(); i++)
						{
							if (myMap->graph.regions.at(3).getUnits().at(i)->getDurability() >= desCount)
							{
								counter++;

							}
						}
					}
				}

				if ((myMap->graph.regions.at(2).tiles.at(j).size() != 0) || (myMap->graph.regions.at(2).getUnits().size() != 0))
				{
					if (myMap->graph.regions.at(2).tiles.at(j).size() != 0)
					{
						if (myMap->graph.regions.at(2).tiles.at(j).back()->getDurability() >= desCount)
						{
							counter++;
						}
					}
					else if (myMap->graph.regions.at(2).getUnits().size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.at(2).getUnits().size(); i++)
						{
							if (myMap->graph.regions.at(2).getUnits().at(i)->getDurability() >= desCount)
							{
								counter++;
							}
						}
					}
				}

				if ((myMap->graph.regions.at(1).tiles.at(j).size() != 0) || (myMap->graph.regions.at(1).getUnits().size() != 0))
				{
					if (myMap->graph.regions.at(1).tiles.at(j).size() != 0)
					{
						if (myMap->graph.regions.at(1).tiles.at(j).back()->getDurability() >= desCount)
						{
							counter++;
						}
					}
					else if (myMap->graph.regions.at(1).getUnits().size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.at(1).getUnits().size(); i++)
						{
							if (myMap->graph.regions.at(1).getUnits().at(i)->getDurability() >= desCount)
							{
								counter++;
							}
						}
					}
				}

				if ((myMap->graph.regions.at(0).tiles.at(j).size() != 0) || (myMap->graph.regions.at(0).getUnits().size() != 0))
				{
					if (myMap->graph.regions.at(0).tiles.at(j).size() != 0)
					{
						if (myMap->graph.regions.at(0).tiles.at(j).back()->getDurability() >= desCount)
						{
							counter++;
						}
					}
					else if (myMap->graph.regions.at(0).getUnits().size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.at(0).getUnits().size(); i++)
						{
							if (myMap->graph.regions.at(0).getUnits().at(i)->getDurability() >= desCount)
							{
								counter++;
							}
						}
					}
				}
			}

			// if anywhere in the map there are no options and desCount is greater than zero, 
			if ((desCount > 0) && (counter == 0))
			{
				cout << endl << endl << "There are no possible buildings or unit to destroy on the current map for the number of destruction dice you rolled."
					<< endl << "Your destruction dice will have no effect and be discarded." << endl << endl;
				desCount = 0;
				break;
			}
			
			if (desCount <= 0)
			{
				cout << "You do not have any Destruction dice." << endl;
				desCount = 0;
				break;
			}
			//else
			//{
			if ((desCount > 0) && (counter != 0))
				{
					int canDorE = 0; //can destroy or eleminate any tile?
					if (myMap->graph.regions.size() != 0)
					{
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							for (int j = 0; j < 3; j++)
							{
								if (myMap->graph.regions.at(i).tiles.at(j).size() != 0) {
									if (desCount >= myMap->graph.regions.at(i).tiles.at(j).back()->getDurability())
									{
										canDorE++;
									}
								}
							}
						}
					}
					if (canDorE == 0)
					{
						cout << "You can't destroy any available building with the number of destruction dice you have!" << endl;
						cout << endl << "Your destruction dice are useless, sorry!\n" << endl;
						desCount = 0;
						break;
					}
					
					else
					{
						
						while (desCount > 0)
						{

							cout << endl << "DESTRUCTION!" << endl;
							cout << endl << "Which region would you like to attack?" << endl
								<< "'M' for Manhattan\n'X' for Brooklyn\n'S' for Staten-Island\n'Q' for Queens\n'Y' for Bronx" << endl;
							//cin >> input;
							/*while (!(input == 'm') && !(input == 'M') && !(input == 'x') && !(input == 'X') && !(input == 'y') && !(input == 'Y') && !(input == 's') && !(input == 'S') && !(input == 'q') && !(input == 'Q'))
							{
							cout << endl << "That is an invalid entry." << endl
							<< "Please enter 'M' for Manhattan, 'X' for Brooklyn, 'S' for Staten-Island, 'Q' for Queens, 'Y' Bronx" << endl << endl;
							cin >> input;
							}*/
							//input = 'm'; // always automatically choose manhattan
							//for (int i = 0; i < myMap->graph.regions.size(); i++) // go through all regions
							//{
							//int canDestroyOrEleminate = 0; 
							int check[3] = { 0, 0, 0 };
							bool selectAgain = true;
							
							char choice = NULL;
							char input = NULL;
							int mc = 0, muc = 0;
							int sc = 0, suc = 0;
							int brc = 0, bruc = 0;
							int brxc = 0, brxuc = 0;
							int qc = 0, quc = 0;
							while (selectAgain == true)
							{
								


								for (int j = 0; j < 3; j++)// check all region stacks and units
								{
									if ((myMap->graph.regions.at(4).tiles.at(j).size() != 0) || (myMap->graph.regions.at(4).getUnits().size() != 0))
									{
										if (myMap->graph.regions.at(4).tiles.at(j).size() != 0)
										{
											if ((myMap->graph.regions.at(4).getCanSelectB() == true) && (myMap->graph.regions.at(4).tiles.at(j).back()->getDurability() <= desCount))
											{
												mc++;
											}
										}
										else if (myMap->graph.regions.at(4).getUnits().size() != 0)
										{
											for (size_t i = 0; i < myMap->graph.regions.at(4).getUnits().size(); i++)
											{
												if ((myMap->graph.regions.at(4).getCanSelectU() == true) && (myMap->graph.regions.at(4).getUnits().at(i)->getDurability() <= desCount))
												{
													muc++;
												}
											}
										}
									}
								}
								//if unit or building vectors aren't empty, assign input to manhattan
								if ((mc > 0) || (muc > 0))
								{
									input = 'm';
									cout << endl << "M" << endl;
									selectAgain = false;
								}
								else
								{
									for (int j = 0; j < 3; j++)// check all region stacks
									{
										
											if ((myMap->graph.regions.at(3).tiles.at(j).size() != 0) || (myMap->graph.regions.at(3).getUnits().size() != 0))
											{
												if (myMap->graph.regions.at(3).tiles.at(j).size() != 0)
												{
													if ((myMap->graph.regions.at(3).getCanSelectB() == true) && (myMap->graph.regions.at(3).tiles.at(j).back()->getDurability() <= desCount))
													{
														brxc++;
													}
												}
												else if (myMap->graph.regions.at(3).getUnits().size() != 0)
												{
													for (size_t i = 0; i < myMap->graph.regions.at(3).getUnits().size(); i++)
													{
														if((myMap->graph.regions.at(3).getCanSelectU() == true) && (myMap->graph.regions.at(3).getUnits().at(i)->getDurability() <= desCount))
														{
															brxuc++;

														}
													}
												}
											}
										
									}
									if ((brxc > 0) || (brxuc > 0)) {
										input = 'x';
										//cout << endl << "X" << endl;
										selectAgain = false;
									}
									else
									{
										for (int j = 0; j < 3; j++)// check all region stacks
										{

											if ( (myMap->graph.regions.at(2).tiles.at(j).size() != 0) || (myMap->graph.regions.at(2).getUnits().size() != 0))
											{
												if (myMap->graph.regions.at(2).tiles.at(j).size() != 0)
												{
													if ((myMap->graph.regions.at(2).getCanSelectB() == true) && (myMap->graph.regions.at(2).tiles.at(j).back()->getDurability() <= desCount))
													{
														sc++;
													}
												}
												else if (myMap->graph.regions.at(2).getUnits().size() != 0)
												{
													for (size_t i = 0; i < myMap->graph.regions.at(2).getUnits().size(); i++)
													{
														if ((myMap->graph.regions.at(2).getCanSelectU() == true) && (myMap->graph.regions.at(2).getUnits().at(i)->getDurability() <= desCount))
														{
															suc++;
														}
													}
												}
											}
										}
										if ((sc > 0) || (suc > 0))
										{
											input = 's';
											//cout << endl << "S" << endl;
											selectAgain = false;
										}
										else
										{

											for (int j = 0; j < 3; j++)// check all region stacks
											{
												if ( (myMap->graph.regions.at(1).tiles.at(j).size() != 0) || (myMap->graph.regions.at(1).getUnits().size() != 0))
												{ 
													if (myMap->graph.regions.at(1).tiles.at(j).size() != 0)
													{
														if ((myMap->graph.regions.at(1).getCanSelectB() == true) && (myMap->graph.regions.at(1).tiles.at(j).back()->getDurability() <= desCount))
														{
															qc++;
														}
													}
													else if (myMap->graph.regions.at(1).getUnits().size() != 0)
													{
														for (size_t i = 0; i < myMap->graph.regions.at(1).getUnits().size(); i++)
														{
															if ((myMap->graph.regions.at(1).getCanSelectU() == true) && (myMap->graph.regions.at(1).getUnits().at(i)->getDurability() <= desCount))
															{
																quc++;
															}
														}
													}
												}
											}
											if ((qc > 0) || (quc > 0)) {
												input = 'q';
												//cout << endl << "Q" << endl;
												selectAgain = false;
											}
											else
											{

												for (int j = 0; j < 3; j++)// check all region stacks
												{
													if ( (myMap->graph.regions.at(0).tiles.at(j).size() != 0) || (myMap->graph.regions.at(0).getUnits().size() != 0))
													{
														if (myMap->graph.regions.at(0).tiles.at(j).size() != 0)
														{
															if ((myMap->graph.regions.at(0).getCanSelectB() == true) && (myMap->graph.regions.at(0).tiles.at(j).back()->getDurability() <= desCount))
															{
																brc++;
															}
														}
														else if (myMap->graph.regions.at(0).getUnits().size() != 0)
														{
															for (size_t i = 0; i < myMap->graph.regions.at(0).getUnits().size(); i++)
															{
																if ((myMap->graph.regions.at(0).getCanSelectU() == true) && (myMap->graph.regions.at(0).getUnits().at(i)->getDurability() <= desCount))
																{
																	bruc++;
																}
															}
														}
													}
												}
												if ((brc > 0) || (bruc > 0))
												{
													input = 'y';
													//cout << endl << "Y" << endl;
													selectAgain = false;
												}
												else
												{
													cout << endl << "You don't have enough dice to destroy any buildings or units." << endl;
													desCount = 0;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectB(false);//
														myMap->graph.regions.at(i).setCanSelectU(false);//
													}
												}
											}
										}

									}
								}
								cout << endl << input << endl;
								//}//


								if ((input == 'm') || (input == 'M'))
								{
									for (int i = 0; i < myMap->graph.regions.size(); i++)
									{
										if (myMap->graph.regions.at(i).getName() == "Manhattan")
										{
											cout << endl << "You chose Manhattan!" << endl;
											p->setRegionId(i);
										}
									}
									
								}
								if ((input == 'x') || (input == 'X'))
								{
									for (int i = 0; i < myMap->graph.regions.size(); i++)
									{
										if (myMap->graph.regions.at(i).getName() == "Brooklyn")
										{
											cout << endl << "You chose Brooklyn!" << endl;
											p->setRegionId(i);
										}
									}
								}
								if ((input == 'y') || (input == 'Y'))
								{
									for (int i = 0; i < myMap->graph.regions.size(); i++)
									{
										if (myMap->graph.regions.at(i).getName() == "Bronx")
										{
											cout << endl << "You chose Bronx!" << endl;
											p->setRegionId(i);
										}
									}
								}
								if ((input == 'q') || (input == 'Q'))
								{
									for (int i = 0; i < myMap->graph.regions.size(); i++)
									{
										if (myMap->graph.regions.at(i).getName() == "Queens")
										{
											cout << endl << "You chose Queens!" << endl;
											p->setRegionId(i);
										}
									}
								}
								if ((input == 's') || (input == 'S'))
								{
									for (int i = 0; i < myMap->graph.regions.size(); i++)
									{
										if (myMap->graph.regions.at(i).getName() == "Staten-Island")
										{
											cout << endl << "You chose Staten-Island!" << endl;
											p->setRegionId(i);
										}
									}
								}
								//
								if (input != NULL)
								{
									cout << "\nTo destroy a building enter \"b\", to eliminate a unit enter \"u\": ";
									int canDestroyOrEleminate = 0;
									//char choice;
									//cin >> choice;
									//int stackTrack = 0;
									bool chooseAgain = true;
									//int check[3] = { 0, 0, 0 };
									while (chooseAgain == true)
									{
										int stackTrack = 0;
										//check the chosen region to make sure it has building stacks (non empty vectors of tiles)	
										for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).tiles.size(); j++)
										{
											if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size()!=0) {
												if ((myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0) && (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability() <= desCount))
												{
													stackTrack++;
												}
											}
										}
										
										//if not building, yes units, input = units
										if((myMap->graph.regions.at(p->getRegionId()).getCanSelectU() == true) && (myMap->graph.regions.at(p->getRegionId()).units.size() != 0) && (stackTrack == 0)) //no stack, yes units
										{
												choice = 'u';
												cout << endl << "U" << endl;
												chooseAgain = false;
												stackTrack = 0;
										
										}
										//if no units, yes buildings, input = buildings
										else if ((myMap->graph.regions.at(p->getRegionId()).getCanSelectB() == true) && (myMap->graph.regions.at(p->getRegionId()).units.size() == 0) && (stackTrack != 0)) // no units, yes stacks
										{
											
												choice = 'b';
												cout << endl << "B" << endl;
												chooseAgain = false;
												stackTrack = 0;
											

										}
										//if yes buildings and yes units, input = buildings
										else if ((myMap->graph.regions.at(p->getRegionId()).getCanSelectU() == true) && (myMap->graph.regions.at(p->getRegionId()).getCanSelectB() == true) && (myMap->graph.regions.at(p->getRegionId()).units.size() != 0) && (stackTrack != 0)) //yes units, yes stacks
										{
											if (myMap->graph.regions.at(p->getRegionId()).getCanSelectB() == true)
											{
												choice = 'b';
												cout << endl << "B" << endl;
												chooseAgain = false;
												stackTrack = 0;
												//break;
											}
											else if (myMap->graph.regions.at(p->getRegionId()).getCanSelectU() == true)
											{
												choice = 'u';
												cout << endl << "U" << endl;
												chooseAgain = false;
												stackTrack = 0;
												//break;
											}
											
										}
										// if not buildings, no stacks , no buildings left in region, choose another regions... shouldn't get here
										else if ((myMap->graph.regions.at(p->getRegionId()).getCanSelectU() == false)&& (myMap->graph.regions.at(p->getRegionId()).getCanSelectB() == false) && (myMap->graph.regions.at(p->getRegionId()).units.size() == 0) && (stackTrack == 0))//no units, no stacks
										{
											cout << endl << "There are no possible buildings or units to destroy in this region with the number of Destruction dice you have." << endl
												<< "Please select another region." << endl;
											selectAgain = true;
											//chooseAgain = false;
											stackTrack = 0;
											myMap->graph.regions.at(p->getRegionId()).setCanSelectB(false);
											myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
											break;
										}
										

										if (((choice == 'b') || (choice == 'B')) && (chooseAgain == false)&& (myMap->graph.regions.at(p->getRegionId()).getCanSelectB() == true))
										{
											for (int j = 0; j < 3; j++)
											{
												if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0) {
													if (desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability())
													{
														canDestroyOrEleminate++;
													}
												}
											}
											if (canDestroyOrEleminate == 0)
											{
												cout << "Sorry, you can't destroy any buildings here with the number of destruction dice you have!" << endl;
												cout << endl << "Please choose another region to attack!\n" << endl;
												selectAgain = true;
												chooseAgain = false;
											
												myMap->graph.regions.at(p->getRegionId()).setCanSelectB(false);
												break;
											}
											else
											{
												cout << endl << "These are the buildings you can destroy with the number of Destruction Dice you have for " << myMap->graph.regions.at(p->getRegionId()).getName() << ": \n" << endl;
												//int check[3] = { 0,0,0 }; // to check if there is available buildings a player can destroy in that specific region
												for (int j = 0; j < 3; j++)
												{
													if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() == 0)
													{
														cout << endl << "Stack " << j + 1 << ": " << "There are no more buildings to destroy!" << endl;
														check[j] = 1;
														
													}
													else
													if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0)
													{
														if (myMap->graph.regions.at(p->getRegionId()).tiles.at(j).size() != 0) {
															if (desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability())
															{
																cout << endl << "Stack number \"" << j + 1 << "\": " << myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getName()
																	<< " " << myMap->graph.regions.at(p->getRegionId()).tiles.at(j).back()->getDurability() << " durability." << endl;
															}
														}
													}
														else
														{
															cout << endl << "Stack number \"" << j + 1 << "\": " << "you can't destroy its buildings (it requires more destruction dice than you have!)";
															check[j] = 1;
														}
													
												}

											}
										}
										if (((choice == 'u') || (choice == 'U')) && (chooseAgain == false)&& (myMap->graph.regions.at(p->getRegionId()).getCanSelectU() == true))
										{
											int unitCount = 0;
											for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++)
											{
												if (myMap->graph.regions.at(p->getRegionId()).getUnits().at(j)->getDurability() >= desCount)
													unitCount++;
											}

											if (unitCount == 0)
											{
												cout << endl << "You do not have enough destruction dice to destroy any units in this region."
													<< endl << "Please select another region." << endl;
												myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
												selectAgain = true;
												chooseAgain = false;

												break;
												////////////////////////////////////////////////////
											}
											int canEliminate = 0;
											//shouldnt ever reach here with the new conditions at the begining
											if (myMap->graph.regions.at(p->getRegionId()).getUnits().size() == 0)
											{
												cout << endl << "Sorry, there are NO units to eliminate!" << endl;
												cout << endl << "Please select another region." << endl;
												
												selectAgain = true;
												myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
												break;
												
											}
											else
											{
												for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++)
												{
													if (desCount >= myMap->graph.regions.at(p->getRegionId()).getUnits().at(j)->getDurability())
													{
														canEliminate++;
													}
												}
												if (canDestroyOrEleminate = 0)
												{
													cout << endl << "Sorry, you can't eliminate any units here with the number of destruction dice you have!" << endl;
													cout << endl << "Please select another region." << endl;
													selectAgain = true;
													chooseAgain = false;
													myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
													break;

												}
											}

										}
									}//
								}//
						
							}
							if ((choice == 'b') || (choice == 'B'))
							{
								//int check[3] = { 0, 0, 0 };
								//choose building they want to destroy
								int in;
								cout << endl << "Please select the building you'd like to destroy( enter its number):" << endl << endl;
							
								in = 1;
								int countN = 0;
								cout << endl << in << endl;
								
								while ((check[in - 1] == 1)) //&& (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).size()==0))
								{
									cout << "Sorry, this is an invalid option, choose another!";
									//cin >> in;
									in++;
									countN++;
									if (in > 3)
										in = 1;
									if (countN == 3)
										break;
									cout << endl << in << endl;
								}
								Tiles* ptr;
								//iterate through vector of vector of tiles
								//while
								if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).size()!=0)
								{
									if ((desCount >= myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability()))
									{
										//Tiles temp;
										cout << endl << "You destroyed: " << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
										//ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();

										//award players
										if ((myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).size() != 0) && (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName() == "High Rise"))
										{
											//high rise, 1 durability, 1 victory point
											if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 1)
											{
												desCount = desCount - 1;

												int points = p->getVictoryPoints() + 1;
												p->setVictoryPoints(points);
												cout << endl << " + 1 victory points!";
												//p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												//myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0) || (desCount == 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}

											}
											//high rise, 2 durability, 2 victory point
											else if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 2)
											{
												desCount = desCount - 2;
												int points = p->getVictoryPoints() + 2;
												p->setVictoryPoints(points);
												cout << endl << " + 2 victory points!" << endl;
												//p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
											//	myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0) || (desCount == 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}
											}

											//high rise, 3 durability, 3 victory point

											else if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 3)
											{
												desCount = desCount - 3;
												int points = p->getVictoryPoints() + 3;
												p->setVictoryPoints(points);
												cout << endl << " + 3 victory points!" << endl;
												//p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//cout << endl << myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName();
											//	myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0) || (desCount == 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}
											}


										}
										if ((myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back() != NULL) && (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName() == "Factory"))
										{
											//factory, 2 durability, 2 energy point
											if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 2)
											{
												desCount = desCount - 2;
												addEnergy(p, 2);
												cout << endl << " + 2 energy cubes!" << endl;
												cout << endl << "You have " << p->getEnergyPoints() << " energy cubes." << endl;
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0) || (desCount == 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}

											}
											//factory, 3 durability, 3 energy point
											else if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 3)
											{
												desCount = desCount - 3;
												addEnergy(p, 3);
												cout << endl << " + 3 energy cubes!" << endl;
												cout << endl << "You have " << p->getEnergyPoints() << " energy cubes." << endl;
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0) || (desCount == 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}
											}

										}
										if ((myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back() != NULL) && (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getName() == "Hospital"))
										{
											//hospital, 2 durability, 2 life point
											if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 2)
											{
												desCount = desCount - 2;
												int points = p->getLifePoints() + 2;
												p->setLifePoints(points);
												cout << endl << " + 2 life points!" << endl;
												if (p->getLifePoints() > 10)
												{
													//int life = p->getLifePoints() - 10;
													p->setLifePoints(10);
													cout << endl << "You have reached maximum health!" << endl
														<< "(You cannot go over the 10 life point maximum)" << endl;
												}
												//p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <=0) )
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}

											}
											//hospital, 3 durability, 3 victory point
											else if (myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->getDurability() == 3)
											{
												desCount = desCount - 3;
												int points = p->getLifePoints() + 3;
												p->setLifePoints(points);
												cout << endl << " + 3 life points!" << endl;
												if (p->getLifePoints() > 10)
												{
													//int life = p->getLifePoints() - 10;
													p->setLifePoints(10);
													cout << endl << "You have reached maximum health!" << endl
														<< "(You cannot go over the 10 life point maximum)" << endl;
												}
												//p->displayMonsterStats();
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back()->ReverseTile();
												//desCount = desCount - (ptr->getDurability());

												ptr = myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).back();
												myMap->graph.regions.at(p->getRegionId()).setUnits(ptr);
												myMap->graph.regions.at(p->getRegionId()).tiles.at(in - 1).pop_back();
												//myMap->graph.regions.at(p->getRegionId()).setCanSelectU(true);
												if ((desCount <= 0))
												{
													desCount = 0;
													p->setDestroy(false);
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													cout << endl << "You are out of destruction dice!" << endl;
													break;
												}
												if (desCount > 0)
												{
													cout << endl << "\nYou still have some destruction dice!\n" << endl;
													selectAgain = true;
													for (int i = 0; i < myMap->graph.regions.size(); i++)
													{
														myMap->graph.regions.at(i).setCanSelectU(true);
														myMap->graph.regions.at(i).setCanSelectB(true);
													}
													break;
												}

											}

										}
									}
								}
							}
					
							if ((choice == 'u') || (choice == 'U'))
							{
								/*int unitCount = 0;
								for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++)
								{
									if (myMap->graph.regions.at(p->getRegionId()).getUnits().at(j)->getDurability() >= desCount)
										unitCount++;
								}

								if (unitCount == 0)
								{
									cout << endl << "You do not have enough destruction dice to destroy any units in this region."
										<< endl << "Please select another region." << endl;
									myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
									selectAgain = true;
									break;
									////////////////////////////////////////////////////
								}*/
								cout << endl << "These are the units you can eliminate with the number of Destruction Dice you have" << myMap->graph.regions.at(p->getRegionId()).getName() << ": \n" << endl;
								for (int j = 0; j < myMap->graph.regions.at(p->getRegionId()).getUnits().size(); j++)
								{
									if(myMap->graph.regions.at(p->getRegionId()).getUnits().at(j)->getDurability() >= desCount)
									cout << endl << "Unit \"" << j + 1 << "\": " << myMap->graph.regions.at(p->getRegionId()).getUnits().at(j)->getName() << endl;
									
								}
								//choose unit they want to eleminate
								int countU = myMap->graph.regions.at(p->getRegionId()).units.size();
								int inU;
								int displayNumU = 0;
								cout << endl << "Please select the unit you'd like to eliminate (enter its number):" << endl << endl;
								//cin >> inU;
								inU = 1;
								cout << endl << inU << endl;//////////////////here
								if (desCount < myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getDurability())
								{
									while ((myMap->graph.regions.at(p->getRegionId()).units.size() != 0))
									//while (inU<1 || inU>myMap->graph.regions.at(p->getRegionId()).units.size())/////wtf is this?
									{
										cout << endl << "That is an invalid entry." << endl;
										cout << endl << "Please select the unit you'd like to eliminate (enter its number):" << endl << endl;
										inU++;
										cout << endl << inU << endl;
										if (inU == myMap->graph.regions.at(p->getRegionId()).units.size())
										{
											cout << endl << "You cannot destroy any units in this region." << endl;
											myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
											selectAgain = true;
											break;
										}
									}
								}
								Tiles* ptrU;
								//iterate through vector of vector of tiles
								if (desCount >= myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getDurability())
								{
									//Tiles temp;
									cout << endl << "You eliminated: " << myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getName();
									//ptrU = &myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1);

									//award players
									if (myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getName() == "Jet")
									{
										desCount = desCount - (myMap->graph.regions.at(p->getRegionId()).units.at(inU - 1)->getDurability());
										//jet
										int points = p->getEnergyPoints() + 2;
										p->setEnergyPoints(points);
										cout << endl << " + 2 energy points!";
										if (p->getLifePoints() > 10)
										{
											//int life = p->getLifePoints() - 10;
											p->setLifePoints(10);
											cout << endl << "You have reached maximum health!" << endl
												<< "(You cannot go over the 10 life point maximum)" << endl;
										}
										//p->displayMonsterStats();
										myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										
										//desCount = desCount - (ptrU->getDurability());
										if ((desCount <= 0) || (desCount == 0))
										{
											desCount = 0;
											p->setDestroy(false);
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											cout << endl << "You are out of destruction dice!" << endl;
											break;
										}
										if (desCount > 0)
										{
											cout << endl << "\nYou still have some destruction dice!\n" << endl;
											selectAgain = true;
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											break;
										}
										//myMap->graph.regions.at(p->getRegionId()).units.pop_back();
									}
									//award players
									if (myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getName() == "Tank")
									{
										desCount = desCount - (myMap->graph.regions.at(p->getRegionId()).units.at(inU - 1)->getDurability());
										//jet
										int points = p->getVictoryPoints() + 3;
										p->setVictoryPoints(points);
										cout << endl << " + 3 victory points!";
										//p->displayMonsterStats();
										myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										//desCount = desCount - (ptrU->getDurability());
										if ((desCount <= 0) || (desCount == 0))
										{
											desCount = 0;
											p->setDestroy(false);
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											cout << endl << "You are out of destruction dice!" << endl;
											break;
										}
										if (desCount > 0)
										{
											cout << endl << "\nYou still have some destruction dice!\n" << endl;
											selectAgain = true;
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											break;
										}
										//myMap->graph.regions.at(p->getRegionId()).units.pop_back();
									}
									//award players
									if (myMap->graph.regions.at(p->getRegionId()).getUnits().at(inU - 1)->getName() == "Infantry")
									{
										desCount = desCount - (myMap->graph.regions.at(p->getRegionId()).units.at(inU - 1)->getDurability());

										//jet
										int points = p->getLifePoints() + 1;
										p->setLifePoints(points);
										cout << endl << " + 1 life points!";
										if (p->getLifePoints() > 10)
										{
											//int life = p->getLifePoints() - 10;
											p->setLifePoints(10);
											cout << endl << "You have reached maximum health!" << endl
												<< "(You cannot go over the 10 life point maximum)" << endl;
										}
										//p->displayMonsterStats();
										myMap->graph.regions.at(p->getRegionId()).units.pop_back();
										//desCount = desCount - (ptrU->getDurability());
										if ((desCount <= 0) || (desCount == 0))
										{
											desCount = 0;
											p->setDestroy(false);
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											cout << endl << "You are out of destruction dice!" << endl;
											break;
										}
										if (desCount > 0)
										{
											cout << endl << "\nYou still have some destruction dice!\n" << endl;
											selectAgain = true;
											for (int i = 0; i < myMap->graph.regions.size(); i++)
											{
												myMap->graph.regions.at(i).setCanSelectU(true);
												myMap->graph.regions.at(i).setCanSelectB(true);
											}
											break;
										}
										//myMap->graph.regions.at(p->getRegionId()).units.pop_back();
									}
								}
								else// shouldn't get here
								{
									cout << endl << "You don't have enough destruction dice to eliminate this unit." << endl;
									cout << endl << "Please select another region to destroy." << endl;
									myMap->graph.regions.at(p->getRegionId()).setCanSelectU(false);
									selectAgain = true;
									break;
								}
							}
			
							int counter = 0;
							///check buildings and units on entire map
				
							for (int j = 0; j < 3; j++)// check all region stacks
					{
						if ((myMap->graph.regions.at(4).tiles.at(j).size() != 0) || (myMap->graph.regions.at(4).getUnits().size() != 0))
						{
							if (myMap->graph.regions.at(4).tiles.at(j).size() != 0)
							{
								if (myMap->graph.regions.at(4).tiles.at(j).back()->getDurability() >= desCount)
								{
									counter++;
								}
							}
							else if (myMap->graph.regions.at(4).getUnits().size() != 0)
							{
								for (int i = 0; i < myMap->graph.regions.at(4).getUnits().size(); i++)
								{
									if (myMap->graph.regions.at(4).getUnits().at(i)->getDurability() >= desCount)
									{
										counter++;
									}
								}
							}
						}


						if ((myMap->graph.regions.at(3).tiles.at(j).size() != 0) || (myMap->graph.regions.at(3).getUnits().size() != 0))
						{
							if (myMap->graph.regions.at(3).tiles.at(j).size() != 0)
							{
								if (myMap->graph.regions.at(3).tiles.at(j).back()->getDurability() >= desCount)
								{
									counter++;
								}
								
							}
							else if (myMap->graph.regions.at(3).getUnits().size() != 0)
							{
								for (int i = 0; i < myMap->graph.regions.at(3).getUnits().size(); i++)
								{
									if (myMap->graph.regions.at(3).getUnits().at(i)->getDurability() >= desCount)
									{
										counter++;

									}
								}
							}
						}

						if ((myMap->graph.regions.at(2).tiles.at(j).size() != 0) || (myMap->graph.regions.at(2).getUnits().size() != 0))
						{
							if (myMap->graph.regions.at(2).tiles.at(j).size() != 0)
							{
								if (myMap->graph.regions.at(2).tiles.at(j).back()->getDurability() >= desCount)
								{
									counter++;
								}
							}
							else if (myMap->graph.regions.at(2).getUnits().size() != 0)
							{
								for (size_t i = 0; i < myMap->graph.regions.at(2).getUnits().size(); i++)
								{
									if (myMap->graph.regions.at(2).getUnits().at(i)->getDurability() >= desCount)
									{
										counter++;
									}
								}
							}
						}

						if ((myMap->graph.regions.at(1).tiles.at(j).size() != 0) || (myMap->graph.regions.at(1).getUnits().size() != 0))
						{
							if (myMap->graph.regions.at(1).tiles.at(j).size() != 0)
							{
								if (myMap->graph.regions.at(1).tiles.at(j).back()->getDurability() >= desCount)
								{
									counter++;
								}
							}
							else if (myMap->graph.regions.at(1).getUnits().size() != 0)
							{
								for (int i = 0; i < myMap->graph.regions.at(1).getUnits().size(); i++)
								{
									if (myMap->graph.regions.at(1).getUnits().at(i)->getDurability() >= desCount)
									{
										counter++;
									}
								}
							}
						}

						if ((myMap->graph.regions.at(0).tiles.at(j).size() != 0) || (myMap->graph.regions.at(0).getUnits().size() != 0))
						{
							if (myMap->graph.regions.at(0).tiles.at(j).size() != 0)
							{
								if (myMap->graph.regions.at(0).tiles.at(j).back()->getDurability() >= desCount)
								{
									counter++;
								}
							}
							else if (myMap->graph.regions.at(0).getUnits().size() != 0)
							{
								for (int i = 0; i < myMap->graph.regions.at(0).getUnits().size(); i++)
								{
									if (myMap->graph.regions.at(0).getUnits().at(i)->getDurability() >= desCount)
									{
										counter++;
									}
								}
							}
						}
					}

								
					if ((desCount >= 0) && (counter == 0))
					{
						cout << endl << "There are no possible buildings or unit to destroy on the current map for the number of destruction dice you have left."
							<< endl << "Your remaining destruction dice will have no effect and be discarded." << endl;
						desCount = 0;
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							myMap->graph.regions.at(i).setCanSelectU(true);
							myMap->graph.regions.at(i).setCanSelectB(true);
						}
						break;

					}
					/*else if (desCount > 0)
					{
						cout << endl << "\nYou still have some destruction dice!\n" << endl;
						selectAgain = true;
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							myMap->graph.regions.at(i).setCanSelectU(true);
							myMap->graph.regions.at(i).setCanSelectB(true);
						}
						break;
					}*/
					else
					{
						desCount = 0;
						for (int i = 0; i < myMap->graph.regions.size(); i++)
						{
							myMap->graph.regions.at(i).setCanSelectU(true);
							myMap->graph.regions.at(i).setCanSelectB(true);
						}
						break;

					}
				}
			}
		}

		break;
	}
 //}
 

		if ((energyCount == 0) && (attackCount == 0) && (desCount == 0) && (healCount == 0) && (celebCount == 0) && (ouchCount == 0))
			allResolved = true;
		
	
		else
		{
			cout << endl << "YOUR DICE: " << endl;
			cout << "DICE TYPE # OF DICE" << endl;
			if (energyCount != 0)
				cout << "Energy Dice:  " << energyCount << endl;
			if (attackCount != 0)
				cout << "Attack Dice:  " << attackCount << endl;
			if (desCount > 0)
				cout << "Destruction Dice: " << desCount << endl;
			if (healCount != 0)
				cout << "Heal Dice:  " << healCount << endl;
			if (celebCount != 0)
				cout << "Celebrity Dice:  " << celebCount << endl;
			if (ouchCount != 0)
				cout << "Ouch! Dice:  " << ouchCount << endl;
		}
	}
	p->setFirstTurn(false);
}


void aggressiveBehavior::move(Map* myMap, Player* p)
{
	NotifyPhase(p->getPlayerId(), "\nMOVE");
	char input;
	cout << endl << p->getMonsterName() << ", would you like to move?" << endl;
	cout << endl << "Enter Y or N" << endl << endl;
	//automatically move
	input = 'y';
	cout << "Y";
	/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
	{
	cout << endl << "That is an invalid entry." << endl
	<< "Please enter Y or N" << endl << endl;
	cin >> input;
	}*/
	if ((input == 'y') || (input == 'Y'))
	{
		vector <Player*> plVect = myMap->getPlayers();
		cout << p->getMonsterName() << " is in " << p->getRegion().getName() << endl
			<< "You can move to one of the following cities: " << endl;
		vector<int>listNodes = myMap->graph.availableNodes(p->getRegion().getID(), p->getRegionsVisited(plVect));
		int destination;
		bool wrongNumber = true;
		do
		{
			cout << endl << "Where would you like to go? (only numbers on list)" << endl;
			for (int i = 0; i < listNodes.size(); i++)
			{
				destination = listNodes.at(i); // always choose first place on list
				if ((destination == listNodes.at(i)) && (listNodes.at(i) != NULL))//
				{
					wrongNumber = false;
				}
			}
		} while (wrongNumber);
		myMap->graph.visitNode(destination, p->getRegion().getID());
		p->setRegion(myMap->graph.findVertexById(destination));
		//check conditions if they can/can't move there*/
	}
	if ((input == 'n') || (input == 'N'))
		return;
}


void aggressiveBehavior::buyCards(Map* myMap, Player* p)
{
	char input;
	int cardNumber;
	do
	{
		//p->isTurn = true;
		//char input;
		NotifyPhase(p->getPlayerId(), "\nBUY CARDS");
		cout << endl << p->getMonsterName() << ", would you like to buy cards?" << endl;
		cout << endl << "Enter Y or N" << endl << endl;
		input = 'y';
		cout << endl << "Y";
		/*while (!(input == 'y') && !(input == 'Y') && !(input == 'n') && !(input == 'N'))
		{
		cout << endl << "That is an invalid entry." << endl
		<< "Please enter Y or N" << endl << endl;
		cin >> input;
		}*/
		if (((input == 'y') || (input == 'Y')) && (myMap->cards.size() > 0))
		{

			//int cardNumber;
			cout << "Select one of the following cards: (1, 2, 3 or 4) \n" << endl;
			/*for (int i = 0; i < 3; i++)
			{
				if (myMap->cards.size() > i)
				{ // to check if we have more than 3 cards on deck
					
					cout << endl << i + 1 << ". " << myMap->cards.at(i).getCardName() << endl;
					//NotifyCard();
					if (myMap->cards.at(i).getCardName() == "Overload")
					{
						cout << endl << "Overload ( 0 energy points to buy!)";

					}
				}

			
			}
			//cout << endl << "4. If you want to discard/reveal new three cards" << endl;*/
			p->setCardsFrMap(true);
			p->setCardsFrHand(false);

			p->setVCardsFrMap(myMap);
			NotifyCard();
			for (int i = 0; i < 3; i++)
			{
				if (myMap->cards.size() > i)
				{
					if (myMap->cards.at(i).getCardName() == "Overload")
					{

						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						//cout << endl << "You selected Overload" << endl;
						break;
					}
					else if (myMap->cards.at(i).getCardName() == "Regeneration")
					{
						//cout << endl << "You selected Regeneration" << endl;
						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
					else if (myMap->cards.at(i).getCardName() == "PhoenixBlood")
					{
						//cout << endl << "You selected Phoenix Blood" << endl;
						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
					else if (myMap->cards.at(i).getCardName() == "ChinaTownRegular")
					{
						//cout << endl << "You selected China Town Regular" << endl;
						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
					else if (myMap->cards.at(i).getCardName() == "TrophyHuner")
					{
						//cout << endl << "You selected Trophy Huner" << endl;
						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
					else if (myMap->cards.at(i).getCardName() == "Drain")
					{
						//cout << endl << "You selected Drain" << endl;
						cardNumber = i;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
					else
					{
						cardNumber = i;
						//cout << endl << "You selected " << myMap->cards.at(i).getCardName() << endl;
						cout << endl << cardNumber + 1 << endl;
						break;
					}
				}
			}

			/*p->setCardsFrMap(false);
			p->setCardsFrHand(true);

			p->setVCardsFrMap(myMap);
			NotifyCard();*/
			//always choose first card
			//cardNumber = 1;
			//cout << endl << "4. If you want to discard/reveal new three cards" << endl;
			//cin >> cardNumber;
		if (cardNumber == 4)
		{
			// player wanted to discard cards
			int newCnum;
			vector<Cards> newCards;
			if (p->getEnergyPoints() < 2)
			cout << "You don't have enough energy points to discard!";
			else
			{
				if (myMap->cards.size() <= 3)
				{
					cout << endl << "Opp! Sorry: there are no more cards in the deck!"
						<< endl << "You cannot buy any cards." << endl;
					p->setCanBuy(false);
				}
				else
				{
					p->setEnergyPoints(p->getEnergyPoints() - 2);
					for (int i = 3; i < myMap->cards.size(); i++)
					{
						newCards.push_back(myMap->cards.at(i));
					}
					newCards.push_back(myMap->cards.at(2));
					newCards.push_back(myMap->cards.at(1));
					newCards.push_back(myMap->cards.at(0));
					//}
					myMap->setCards(newCards);
				}
				cout << "Select one of the following cards: (1,2 or 3) \n" << endl;
				/*for (int i = 0; i < 3; i++) {
				if (myMap->cards.size() > i) { // to check if we have more than 3 cards on deck
				cout << i + 1 << ". " << myMap->cards.at(i).getCardName();
				if (myMap->cards.at(i).getCardName() == "Overload") {
				cout << " ( 0 energy points to buy!)";
				}*/
				p->setCardsFrMap(true);
				p->setCardsFrHand(false);

				p->setVCardsFrMap(myMap);
				NotifyCard();

				cout << endl;
			}
		//}
	//}
			cin >> newCnum;
			cardNumber = newCnum;
		}
			// a loop for discarding cards
			if (cardNumber < 4)
			{ // a player choose a card
				int counttt = 0;
				// means that a player can not buy any availabe card
				//bool haveEnoughEnergyPoints = (p->getEnergyPoints() > myMap->cards.at(cardNumber - 1).getCost());
				/*while (cardNumber > 4)
				{
				cout << "PLEASE choose from the AVAILABLE cards." << endl;
				cin >> cardNumber;
				}*/
				bool haveEnoughEnergyPoints = (p->getEnergyPoints() >= myMap->cards.at(cardNumber).getCost());
				while (!haveEnoughEnergyPoints)
				{
					cout << "You don't have enough points to buy this card...please choose another card \n";
					counttt++;
					cout << endl << counttt + 1 << endl;
					if ((counttt == 3) || (counttt == myMap->cards.size()))
					{
						cout << "Sorry but You don't have enough energy points to buy any of the cards!" << endl;
						p->setCanBuy(false);
						break;
					}
					if (cardNumber < 4)
					{
						cardNumber++;
						
					}
					haveEnoughEnergyPoints = (p->getEnergyPoints() >= myMap->cards.at(cardNumber).getCost());
				}
				if ((counttt != 3) && (counttt <= myMap->cards.size()))
				{
					int set = p->getEnergyPoints() - (myMap->cards.at(cardNumber).getCost());
					p->setEnergyPoints(set);
					if (p->getEnergyPoints() <= 0)
						p->setEnergyPoints(0);
					p->cards.push_back(myMap->cards.at(cardNumber));
					vector<Cards> newC;
					for (int m = 0; m < myMap->cards.size(); m++) {
						if (m != cardNumber)
							newC.push_back(myMap->cards.at(m));
					}
					cout << endl << "\nThis is your new card, you got: " << (myMap->cards.at(cardNumber).getCardName()) << endl;
					cout << endl << "Your energy points are now: " << p->getEnergyPoints() << endl;
					p->setCardsFrMap(false);
					p->setCardsFrHand(true);
					myMap->setCards(newC);
					p->setVCardsFrMap(myMap);
					NotifyCard();
				}
			}
		}

		else
		{
		cout << endl << "Opp! Sorry: there are no more cards in the deck!"
			<< endl << "You cannot buy any cards." << endl;
		p->setCanBuy(false);
		//p->isTurn = false;
		}
		//p->isTurn = false;
	} while (((input == 'y') || (input == 'Y')) && (p->getCanBuy() == true));
}

void aggressiveBehavior::displayStats(Player* p) {
	NotifyStats();
}
void aggressiveBehavior::displayDice(Player* p) {
	NotifyDice();
}
void aggressiveBehavior::displayCards() {
	NotifyCard();
}
aggressiveBehavior::~aggressiveBehavior()
{
}

