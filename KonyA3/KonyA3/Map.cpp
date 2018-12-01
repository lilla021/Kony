#include "Map.h"
using namespace std;
Map::Map()
{
	regions;
	zones;
	connections;
	cards;
	tiles;
	//tok;
	//spCards;
	energyCubes;
	monsters;
	players;
}
Map* Map::instance = NULL;
Map* Map::getInstance()
{
	if (instance == NULL)
		instance = new Map();
	return instance;
}
vector <Player*> Map::getPlayers()
{
	return this->players;
}
//MUTATORS
void Map::setPlayers(vector <Player*> pl)
{
	this->players = pl;
}
void Map::setGraph(Graph grph)
{
	this->graph = grph;
}
void Map::setRegions(vector <Vertex> rgns)
{
	this->regions = rgns;
}
void Map::setZones(vector <Vertex> zns)
{
	this->zones = zns;
}
void Map::setEdges(vector <Edge> cons)
{
	this->connections = cons;
}
//to do
void Map::setCards(vector <Cards> crds)
{
	this->cards = crds;
}
//void Map::setSpecialCards(vector <SpecialCards> spCrds)
//{
//spCards = spCrds;
//}
//void Map::setTokens(vector <<vector> Tokens* > tok)
//{
//tokens = tok;
//}
void Map::setTiles(vector <Tiles> tls)
{
	this->tiles = tls;
}
void Map::setEnergyCubes(EnergyCubes cubes)
{
	this->energyCubes = cubes;
}
void Map::setMonsters(vector <Monsters*> mons)
{
	this->monsters = mons;
}
//ACCESSORS
Graph Map::getGraph()
{
	return this->graph;
}
vector <Vertex> Map::getRegions()
{
	return this->regions;
}
vector <Vertex> Map::getZones()
{
	return this->zones;
}
vector <Edge> Map::getConnections()
{
	return this->connections;
}
//to do
vector <Cards> Map::getCards()
{
	return this->cards;
}
//vector <SpecialCards> Map::getSpecialCards()
//{
//return spCards;
//}
//vector <<vector> Tokens* > Map::getTokens()
//{
//return tokens;
//}
vector <Tiles> Map::getTiles()
{
	return this->tiles;
}
EnergyCubes Map::getEnergyCubes()
{
	return this->energyCubes;
}
vector <Monsters*> Map::getMonsters()
{
	return this->monsters;
}
//METHODS
/*void Map::showPlayers()
{
for (int i = 0; i < players.size(); i++)
{
//cout << players[i].getMonsterName() << endl;
players[i].displayMonsterStats();
cout << endl;
}
}*/
void Map::showRegions()
{
	for (int i = 0; i < regions.size(); i++)
	{
		cout << this->regions[i].getName();
		cout << endl;
	}
}
void Map::showZones()
{
	for (int i = 0; i < zones.size(); i++)
	{
		cout << this->zones[i].getName();
		cout << endl;
	}
}
void Map::showConns()
{
	for (int i = 0; i < regions.size(); i++)
	{
		cout << this->regions[i].getName() << endl;
		this->regions[i].showEdges();
		cout << endl;
	}
	for (int i = 0; i < this->zones.size(); i++)
	{
		cout << this->zones[i].getName() << endl;
		this->zones[i].showEdges();
		cout << endl;
	}
}
void Map::initializeVectors() {
	for (int i = 0; i < this->graph.regions.size(); i++)
	{
		regions.push_back(this->graph.regions.at(i));
	}
	for (int i = 0; i < this->graph.zones.size(); i++)
	{
		zones.push_back(this->graph.zones.at(i));
	}
	for (int i = 0; i < this->graph.edges.size(); i++)
	{
		connections.push_back(this->graph.edges.at(i));
	}
}
/*void Map::displayT()
{
cout << "You have the following tokens: " << endl;
for (size_t i = 0; i < tokens.size(); i++)
{
cout << tokens*[i].getTokenName() << endl;
}
}*/
void Map::displayC()
{
	cout << endl << "You have the following cards: " << endl;
	for (size_t i = 0; i < this->cards.size(); i++)
	{
		cout << "Card: " << this->cards[i].getCardName() << " - " << "Description: " << this->cards[i].getHowToPlay() << endl;
	}
}
void Map::displayCube()
{
	cout << endl << "You have " << this->getEnergyCubes().getTotal() << " energy cubes." << endl;
}
Map::~Map()
{
	//delete instance;
	instance = NULL;
}

