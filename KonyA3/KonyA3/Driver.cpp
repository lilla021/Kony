#include <iostream>
#include "Map.h"
#include "FileIO.h"
#include "Player.h"
#include "Behavior.h"
#include "humanBehavior.h"
#include "aggressiveBehavior.h"
#include "moderateBehavior.h"
using namespace std;
//////PART ONE-almost done
//function that is meant in order to return the players index with the highest totalAttack
int getMaxTotalAttackIndex(vector <Player*> play)
{
	int max = play[0]->getTotalAttack();
	int indexMax = 0;
	for (int i = 1; i < play.size(); i++) {
		if (play[i]->getTotalAttack() > max) {
			max = play[i]->getTotalAttack();
			indexMax = i;
		}
	}
	return indexMax;
}
int main()
{
	//Tokens Ceation//////////////////////////
	vector<Tokens> web;
	for (int i = 0; i < 13; i++) {
		web.push_back(Web());
	}
	vector<Tokens> jin;
	for (int i = 0; i < 13; i++) {
		jin.push_back(Jinx());
	}
	vector<Tokens> souv;
	for (int i = 0; i < 5; i++) {
		souv.push_back(Souvenir());
	}
	vector<Tokens> cara;
	for (int i = 0; i < 13; i++) {
		cara.push_back(Carapace());
	}
	vector<Tokens>* webpointer;
	webpointer = &web;
	vector<Tokens>* jinxpointer;
	jinxpointer = &jin;
	vector<Tokens>* souvpointer;
	souvpointer = &souv;
	vector<Tokens>* carapointer;
	carapointer = &cara;
	vector <vector<Tokens>*> tok{ webpointer, jinxpointer, souvpointer, carapointer };
	//create energycubes
	EnergyCubes enm(1000);
	//create monsters
	Monsters* m1 = new Monsters("Drakonis");
	Monsters* m2 = new Monsters("Mantis");
	Monsters* m3 = new Monsters("Rob");
	Monsters* m4 = new Monsters("Sheriff");
	Monsters* m5 = new Monsters("Kong");
	Monsters* m6 = new Monsters("Captain Fish");
	vector <Monsters*> mnstr{ m1, m2, m3, m4, m5, m6 };
	//create tiles
	HighRise1 high;
	HighRise2 high2;
	Hospital2 hos2;
	Factory2 fac2;
	HighRise3 high3;
	Factory3 fac3;
	Hospital3 hos3;
	vector<Tiles> t;

	for (int i = 0; i < 22; i++) {
		t.push_back(high);
	}
	for (int i = 0; i < 8; i++) {
		t.push_back(high2);
	}
	for (int i = 0; i < 3; i++) {
		t.push_back(hos2);
	}
	for (int i = 0; i < 3; i++) {
		t.push_back(fac3);
	}
	for (int i = 0; i < 3; i++) {
		t.push_back(high3);
	}
	for (int i = 0; i < 3; i++) {
		t.push_back(hos3);
	}
	for (int i = 0; i < 3; i++) {
		t.push_back(fac3);
	}
	//shuffling........
	Tiles s;
	t = s.shuffleTiles(t);
	//create cards
	LongNeck c1;
	TrashThrower c2;
	TrophyHuner c3;
	CanOpener c4;
	PhoenixBlood c5;
	Stomp c6;
	ChinaTownRegular c7;
	Regeneration c8;
	Drain c9;
	Overload c10;
	StatueOfLiberty c11;
	Superstar c12;
	vector<Cards> crds{ c1, c2, c3, c4, c5, c6, c7, c8, c9, c10 };
	//shuffling........
	Cards shufflecrds;
	crds = shufflecrds.shuffleCards(crds);
	//read file
	string fileName;
	cout << endl << "Please choose from one of the following files." << endl;
	cout << endl << "DoesNotExistFile.txt" << endl;
	cout << endl << "FileIO.txt" << endl;
	cout << endl << "formatErrorFile.txt" << endl;
	//cin >> fileName;
	FileIO file("FileIO.txt");
	file.readFile();
	//create graph
	Graph graph(file.regions, file.zones);
	graph.addEdges();
	//set tiles
	graph.setTiles(&(graph.regions), &t);
	//create player vector (will be assigned to map empty)
	vector <Player*> playervector;

	//create map
	//SINGLETON
	Map* myMap = myMap->getInstance();
	myMap->setGraph(graph);
	myMap->setCards(crds);
	myMap->setTiles(t);
	myMap->setEnergyCubes(enm);
	myMap->setMonsters(mnstr);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////MAP IS SET- sort of//////////////////////////////////////////////////
	cout << endl << "----------------------------------------------------------------------------" << endl;
	cout << endl << "  WELCOME TO THE GAME OF KINGS OF NEW YORK!" << endl;
	cout << endl << "----------------------------------------------------------------------------" << endl;

	//srand(time_t(0));
	//******************************DRIVER CHECKS WHICH PLAYER GOES FIRST (ORDER)***********************************************************
	int numPlayers;
	int iMax;
	cout << endl << "How many people are playing? (Minimum 2 players, Maximum 6 players)" << endl;
	cin >> numPlayers;
	//numPlayers = 4; //comp generated
	cout << endl;
	while ((numPlayers != 2) && (numPlayers != 3) && (numPlayers != 4) && (numPlayers != 5) && (numPlayers != 6))
	{
		cout << endl << "That is an invalid entry." << endl
			<< "You must enter a valid number between 2-6" << endl;
		cin >> numPlayers;
		cout << endl;
	}
	const int NUMPLAYERS = numPlayers;

	/////Create Players
	Player* player1 = new Player();
	Player* player2 = new Player();
	Player* player3 = new Player();
	Player* player4 = new Player();
	Player* player5 = new Player();
	Player* player6 = new Player();
	////////Strategy Patterns
	//Instantiate behaviors
	Behavior* human = new humanBehavior();
	Behavior* aggressive = new aggressiveBehavior();
	Behavior* moderate = new moderateBehavior();
	//Set player behaviors
	//human
	
	/*player1->setBehavior(human);
	player2->setBehavior(human);
	player3->setBehavior(human);
	player4->setBehavior(human);
	player5->setBehavior(human);
	player6->setBehavior(human);*/

	//aggressive
	/*player1->setBehavior(aggressive);
	player2->setBehavior(aggressive);
	player3->setBehavior(aggressive);
	player4->setBehavior(aggressive);
	player5->setBehavior(aggressive);
	player6->setBehavior(aggressive);*/
	//moderate
	
	/*player1->setBehavior(moderate);
	player2->setBehavior(moderate);
	player3->setBehavior(moderate);
	player4->setBehavior(moderate);
	player5->setBehavior(moderate);
	player6->setBehavior(moderate);*/

	/////////////////////////////////////////////////////////////////////////TOURNAMENT
	player1->setBehavior(aggressive);
	player2->setBehavior(moderate);
	player3->setBehavior(human);
	player4->setBehavior(aggressive);
	player5->setBehavior(moderate);
	player6->setBehavior(human);


	if (NUMPLAYERS == 2)
	{
		vector <Dice> green;
		vector <Dice> black;
		int blcount = 0;
		int grcount = 0;
		player1->setPlayerId(1);
		//player1->setEnergyPoints(10);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeChooseMonster(myMap, player1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		//player1->executeDisplayStats(player1);
		player2->setPlayerId(2);
		//player2->setEnergyPoints(10);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeChooseMonster(myMap, player2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeDisplayStats(player2);
		/////////////////////////////////////////////////////////////////////TESTINGGGG
		//player1.setLifePoints(8);
		//player2.setLifePoints(9);
		//player1.setSuperStar(true);
		playervector.push_back(player1);
		playervector.push_back(player2);
		//myMap->setPlayers(playervector);

		//looping through to check how much attack were calculated for each player
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			cout << endl << playervector[i]->getMonsterName() << ": Rolling Dice!" << endl;
			black = playervector[i]->getBlDice();
			green = playervector[i]->getGrDice();
			playervector[i]->setBlackcountAttack(black);
			blcount = playervector[i]->getBlackcountAttack();
			playervector[i]->setGreencountAttack(green);
			grcount = playervector[i]->getGreencountAttack();
			playervector[i]->setTotalAttack(blcount, grcount);
			cout << endl << playervector[i]->getMonsterName() << ": Total number of Attack counted  " << playervector[i]->getTotalAttack() << endl;
		}
		iMax = getMaxTotalAttackIndex(playervector);
	}
	if (NUMPLAYERS == 3)
	{
		vector <Dice> green;
		vector <Dice> black;
		int blcount = 0;
		int grcount = 0;
		player1->setPlayerId(1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeChooseMonster(myMap, player1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		//player1->executeDisplayStats(player1);
		player2->setPlayerId(2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeChooseMonster(myMap, player2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		//player2->executeDisplayStats(player2);
		player3->setPlayerId(3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeChooseMonster(myMap, player3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		//player3->executeDisplayStats(player3);
		playervector.push_back(player1);
		playervector.push_back(player2);
		playervector.push_back(player3);
		//myMap->setPlayers(playervector);


		//looping through to check how much attack were calculated for each player
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			cout << endl << playervector[i]->getMonsterName() << ": Rolling Dice!" << endl;
			black = playervector[i]->getBlDice();
			green = playervector[i]->getGrDice();
			playervector[i]->setBlackcountAttack(black);
			blcount = playervector[i]->getBlackcountAttack();
			playervector[i]->setGreencountAttack(green);
			grcount = playervector[i]->getGreencountAttack();
			playervector[i]->setTotalAttack(blcount, grcount);
			cout << endl << playervector[i]->getMonsterName() << ": Total number of Attack counted  " << playervector[i]->getTotalAttack() << endl;
		}
		iMax = getMaxTotalAttackIndex(playervector);
	}
	if (NUMPLAYERS == 4)
	{
		vector <Dice> green;
		vector <Dice> black;
		int blcount = 0;
		int grcount = 0;
		player1->setPlayerId(1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeChooseMonster(myMap, player1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeDisplayStats(player1);
		player2->setPlayerId(2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeChooseMonster(myMap, player2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeDisplayStats(player2);
		player3->setPlayerId(3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeChooseMonster(myMap, player3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeDisplayStats(player3);
		player4->setPlayerId(4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeChooseMonster(myMap, player4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeDisplayStats(player4);

		playervector.push_back(player1);
		playervector.push_back(player2);
		playervector.push_back(player3);
		playervector.push_back(player4);
		//myMap->setPlayers(playervector);

		//looping through to check how much attack were calculated for each player
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			cout << endl << playervector[i]->getMonsterName() << ": Rolling Dice!" << endl;
			black = playervector[i]->getBlDice();
			green = playervector[i]->getGrDice();
			playervector[i]->setBlackcountAttack(black);
			blcount = playervector[i]->getBlackcountAttack();
			playervector[i]->setGreencountAttack(green);
			grcount = playervector[i]->getGreencountAttack();
			playervector[i]->setTotalAttack(blcount, grcount);
			cout << endl << playervector[i]->getMonsterName() << ": Total number of Attack counted  " << playervector[i]->getTotalAttack() << endl;
		}
		iMax = getMaxTotalAttackIndex(playervector);
	}
	if (NUMPLAYERS == 5)
	{
		vector <Dice> green;
		vector <Dice> black;
		int blcount = 0;
		int grcount = 0;
		player1->setPlayerId(1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeChooseMonster(myMap, player1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeDisplayStats(player2);
		player2->setPlayerId(2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeChooseMonster(myMap, player2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeDisplayStats(player2);
		player3->setPlayerId(3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeChooseMonster(myMap, player3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeDisplayStats(player3);
		player4->setPlayerId(4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeChooseMonster(myMap, player4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeDisplayStats(player4);
		player5->setPlayerId(5);
		//cout << endl << "Player " << player5->getPlayerId() << ": ";
		player5->executeChooseMonster(myMap, player5);
		//cout << endl << "Player " << player5->getPlayerId() << ": ";
		player5->executeDisplayStats(player5);

		playervector.push_back(player1);
		playervector.push_back(player2);
		playervector.push_back(player3);
		playervector.push_back(player4);
		playervector.push_back(player5);
		//myMap->setPlayers(playervector);

		//looping through to check how much attack were calculated for each player
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			cout << endl << playervector[i]->getMonsterName() << ": Rolling Dice!" << endl;
			black = playervector[i]->getBlDice();
			green = playervector[i]->getGrDice();
			playervector[i]->setBlackcountAttack(black);
			blcount = playervector[i]->getBlackcountAttack();
			playervector[i]->setGreencountAttack(green);
			grcount = playervector[i]->getGreencountAttack();
			playervector[i]->setTotalAttack(blcount, grcount);
			cout << endl << playervector[i]->getMonsterName() << ": Total number of Attack counted  " << playervector[i]->getTotalAttack() << endl;
		}
		iMax = getMaxTotalAttackIndex(playervector);
	}
	if (NUMPLAYERS == 6)
	{
		vector <Dice> green;
		vector <Dice> black;
		int blcount = 0;
		int grcount = 0;
		player1->setPlayerId(1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeChooseMonster(myMap, player1);
		//cout << endl << "Player " << player1->getPlayerId() << ": ";
		player1->executeDisplayStats(player1);
		player2->setPlayerId(2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeChooseMonster(myMap, player2);
		//cout << endl << "Player " << player2->getPlayerId() << ": ";
		player2->executeDisplayStats(player2);
		player3->setPlayerId(3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeChooseMonster(myMap, player3);
		//cout << endl << "Player " << player3->getPlayerId() << ": ";
		player3->executeDisplayStats(player3);
		player4->setPlayerId(4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeChooseMonster(myMap, player4);
		//cout << endl << "Player " << player4->getPlayerId() << ": ";
		player4->executeDisplayStats(player4);
		player5->setPlayerId(5);
		//cout << endl << "Player " << player5->getPlayerId() << ": ";
		player5->executeChooseMonster(myMap, player5);
		//cout << endl << "Player " << player5->getPlayerId() << ": ";
		player5->executeDisplayStats(player5);
		player6->setPlayerId(6);
		//cout << endl << "Player " << player6->getPlayerId() << ": ";
		player6->executeChooseMonster(myMap, player6);
		//cout << endl << "Player " << player6->getPlayerId() << ": ";
		player6->executeDisplayStats(player6);
		playervector.push_back(player1);
		playervector.push_back(player2);
		playervector.push_back(player3);
		playervector.push_back(player4);
		playervector.push_back(player5);
		playervector.push_back(player6);
		//myMap->setPlayers(playervector);

		//looping through to check how much attack were calculated for each player
		for (int i = 0; i < NUMPLAYERS; i++)
		{
			cout << endl << playervector[i]->getMonsterName() << ": Rolling Dice!" << endl;
			black = playervector[i]->getBlDice();
			green = playervector[i]->getGrDice();
			playervector[i]->setBlackcountAttack(black);
			blcount = playervector[i]->getBlackcountAttack();
			playervector[i]->setGreencountAttack(green);
			grcount = playervector[i]->getGreencountAttack();
			playervector[i]->setTotalAttack(blcount, grcount);
			cout << endl << playervector[i]->getMonsterName() << ": Total number of Attack counted  " << playervector[i]->getTotalAttack() << endl;
		}
		iMax = getMaxTotalAttackIndex(playervector);
	}
	myMap->setPlayers(playervector);
	cout << endl << playervector[iMax]->getMonsterName() << " starts!" << endl;
	
	cout << endl << "---------------------------------------------------------------------------------------" << endl;
	//Shows the game pieces on the map . comment out here...
	//Note: players place there monsters on the region at the begining of their first turn, as seen in part 3
	//cout << endl << "The following regions have the corresponding building tiles:" << endl << endl;
	//graph.showGraph(graph);
	//cout << endl << "---------------------------------------------------------------------------------------" << endl;
	//til here  
	/*
	//Clockwise Rotation. Comment out here...
	int count = 0;
	for (int p = iMax; p < NUMPLAYERS; p++)
	{
	//Part three will go here
	cout << playervector[iMax].getMonsterName() << " TURN :::::::" << endl;
	cout << "Please select a Region that you wish to occupy" << endl;
	count++;
	if (count == NUMPLAYERS) {
	break;
	}
	if (p == NUMPLAYERS - 1)
	{
	p = -1;
	}
	}
	//to here
	*/
	//PART THREE - missing > move(), resolveDice(), and buyCards() 
	bool keepPlaying = true;
	bool lifePointsReached = false;
	int numActivePlayers = NUMPLAYERS;
	int pos = iMax;
	
	int turnCount = 0;
	//game loop
	int stopCondition = 0;
	while (keepPlaying == true)
	{

		//iterate through players
		for (pos; pos < NUMPLAYERS; pos++)
		{
			playervector[pos]->isTurn = true;
			
			//as long as players are still active, they can play
			if ((playervector[pos]->getActivity() == true)&&(playervector[pos]->isTurn == true))
			{
				string name = playervector[pos]->getMonsterName();
				cout << endl << "**********BEGIN TURN**********" << endl;
				cout << endl << name << ": your turn!" << endl;
				//set players on map on first turn
				if ((playervector[pos]->getFirstTurn() == true) && (turnCount != NUMPLAYERS))
				{
					turnCount++;
					//cout << endl << "Please select a region that you wish to occupy" << endl;
					//SET PLAYER IN REGION WITH MOVE FUNCTION
					playervector[pos]->executeSetFirstPosition(myMap, playervector[pos]);//////////////////////////check this out
				}
				////////////////////////////////////////////////////////////////////////////////////////////
				for (int i = 0; i < playervector[pos]->cards.size(); i++)
				{
					string cardname = playervector[pos]->cards.at(i).getCardName();
					if (cardname == "Regeneration")
					{
						playervector[pos]->setLifePoints(playervector[pos]->getLifePoints() + 1);
						if (playervector[pos]->getVictoryPoints() >= 10)
						{
							playervector[pos]->setVictoryPoints(10);
						}
					}
					////////////////////////////////////////////////////////////////////////////////////////////
				}
				//srand(time_t(0));
				//rollDice() called here
				//setStrategy(hum);
				playervector[pos]->executeRollDice(playervector[pos]);//
				playervector[pos]->executeResolveDice(myMap, playervector[pos]);

				/*vector <Dice> rolled = playervector[pos].rollDice(playervector[pos].getBlDice());
				//resolveDice() called here
				playervector[pos].resolveDice(rolled, playervector);*/
				///MOVE()
				if ((playervector[pos]->getLifePoints() <= 0) && (playervector[pos]->getActivity() == true))
				{
					cout << endl << playervector[pos]->getMonsterName() << " has been eliminated this round." << endl;
					cout << "-----You ran out of life points-----" << endl;
					playervector[pos]->setActivity(false);
					numActivePlayers--;
				}
				if ((playervector[pos]->getMonsterName() == name) && (playervector[pos]->getActivity() == true))
				{

					///ASK PLAYER IF THEY WANT TO MOVE
					//char input; 
					//IF PLAYER IN REGION
					bool inRegion = myMap->getGraph().isRegion(playervector[pos]->getRegion().getID());
					if (inRegion)
					{
						// CHECK IF MANHATTAN AVAILABLE
						vector<bool> lowManVisited = myMap->getGraph().manhattanAvailable();
						if (!lowManVisited.at(0))
						{
							playervector[pos]->moveToManhattan(myMap, "Lower-Zone|2-4");
							cout << endl << playervector[pos]->getMonsterName() << " has been placed in Lower Manhattan (2-4)" << endl;
						}
						else if (!lowManVisited.at(1) && playervector.size() > 4) {
							playervector[pos]->moveToManhattan(myMap, "Lower-Zone|5-6");
							cout << endl << playervector[pos]->getMonsterName() << " has been placed in Lower Manhattan (5-6)" << endl;
						}
						else
						{
							playervector[pos]->executeMove(myMap, playervector[pos]);
						}
					}
				}
				else
				{ // player in Manhattan
					playervector[pos]->moveUp(myMap);
				}
				//BUYCARDS()
				//ASK PLAYER IF THEY WANT TO BUYCARDS
				//playervector[pos].buyCards();

				playervector[pos]->executeBuyCards(myMap, playervector[pos]);

				if (playervector.at(pos)->getFirstTurn() == true)
					playervector.at(pos)->setFirstTurn(false);

				
				cout << endl << "**********END TURN**********" << endl;

				//need to check to see if any cards need to be activated here
				if (playervector[pos]->getMonsterName() != name)
				{
					if (numActivePlayers != 0)
					{
						cout << endl << "Players still playing: " << endl;
						for (int k = 0; k < NUMPLAYERS; k++)
						{
							if (playervector[k]->getActivity() == true)
								playervector[k]->executeDisplayStats(playervector[k]);
						}
						keepPlaying = false;
						//break;
					}
				}

				for (size_t i = 0; i < playervector.size(); i++)
				{
					//First player to 20 victory points
					if ((playervector[i]->getVictoryPoints() >= 20) && (playervector[i]->getLifePoints() != 0))
					{
						cout << endl << "Congratulations " << playervector[i]->getMonsterName() << "!" << endl;
						cout << "-----*!YOU ARE THE KING OF NEW YORK!*-----" << endl;
						cout << "You are the first player to reach 20 victory points." << endl;
						system("pause");
						exit(1);
					}
					//player elimination
					if ((playervector[i]->getLifePoints() <= 0)) //&& (playervector[i]->getActivity() == true))
					{
						cout << endl << playervector[i]->getMonsterName() << " has been eliminated this round." << endl;
						cout << "-----You ran out of life points-----" << endl;
						playervector[i]->setActivity(false);
						numActivePlayers--;
					}
				}
				//Last player standing
				if ((numActivePlayers == 1))
				{
					for (size_t l = 0; l < playervector.size(); l++)
					{
						if (playervector[l]->getActivity() == true)
						{
							cout << endl << "Congratulations " << playervector[l]->getMonsterName() << "!" << endl;
							cout << "-----*!YOU ARE THE KING OF NEW YORK!*-----" << endl;
							cout << "You are the last player standing." << endl;
							system("pause");
							exit(1);
						}
					}
				}
				if (numActivePlayers == 0)
				{
					cout << endl << "-----*!END OF GAME!*-----" << endl;
					cout << "All remaining players were eliminated this round, therefore there are no winners." << endl;
					system("pause");
					exit(1);
				}
				//////////////////////////////////////////////////////////////FOR MODERATE
			/*	if (stopCondition = 5)
				{
					cout << endl << "-----*!END OF GAME!*-----" << endl;
					cout << "This is taking too long to win" << endl;
					system("pause");
					exit(1);
				}*/
				
				

				
				playervector.at(pos)->isTurn = false;
					if (pos == (playervector.size() - 1))
						playervector.at(0)->isTurn = true;
					else
						playervector.at(pos + 1)->isTurn = true;
					playervector.at(pos)->rollCounter = 0;
				
				if (pos == (NUMPLAYERS - 1))
					pos = -1;
				//else
					//continue;
			}
			/*if (numActivePlayers > 0)
			{
				cout << endl << "Players still playing: " << endl;
				for (int k = 0; k < NUMPLAYERS; k++)
				{
					if (playervector[k]->getActivity() == true)
						playervector[k]->executeDisplayStats(playervector[k]);
				}
				keepPlaying = false;
			}*/
		}

		system("pause");
		return 0;
	}
}

