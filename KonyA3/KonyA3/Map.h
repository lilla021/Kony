#pragma once
#include "Graph.h"
#include "Tiles.h"
#include "Tokens.h"
#include "Monsters.h"
#include "Cards.h"
#include "Player.h"
//#include "SpecialCards.h"
#include "EnergyCubes.h"
class Player;
class Map
{
public:

	static Map* getInstance();

	//MUTATORS
	void setGraph(Graph grph);
	void setRegions(vector <Vertex> rgns);
	void setZones(vector <Vertex> zns);
	void setEdges(vector <Edge> cons);
	void setPlayers(vector <Player*> pl);
	vector <Player*> getPlayers();
	//to do
	void setCards(vector <Cards> crds);
	
	//void setSpecialCards(vector <SpecialCards> spCrds);
	//void setTokens(vector <<vector> Tokens>*> tok);
	void setTiles(vector <Tiles> tls);
	void setEnergyCubes(EnergyCubes cubes);
	void setMonsters(vector <Monsters*> mons);
	//ACCESSORS
	Graph getGraph();
	vector <Vertex> getRegions();
	vector <Vertex> getZones();
	vector <Edge> getConnections();
	//to do
	vector <Cards> getCards();
	
	//vector <SpecialCards> getSpecialCards();
	//vector <vector <Tokens>*> getTokens();
	vector <Tiles> getTiles();
	EnergyCubes getEnergyCubes();
	vector <Monsters*> getMonsters();

	//METHODS
	void showRegions();
	void showZones();
	void showConns();
	void initializeVectors();
	void displayC();
	//void displayT();
	void displayCube();
	Graph graph;
	vector <Player*> players;
	vector <Cards> cards;
	
private:
	static Map* instance;
	Map();
	~Map();

	//Graph graph;
	vector <Vertex> regions;
	vector <Vertex> zones;
	vector <Edge> connections;
	//vector <Player*> players;
	//to do
	vector <vector <Tokens>*> tokens;
	//vector <Cards> cards;
	//vector <SpecialCards> spCards;
	EnergyCubes energyCubes;
	vector <Tiles> tiles;
	vector <Monsters*> monsters;


};

