#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Edge.h"
#include "Tiles.h"
using namespace std;
class Vertex
{
public:
	Vertex();
	Vertex(string nom, int ID);
	Vertex(string nom, int ID, vector <Vertex> owns);
	~Vertex();
	string getName();
	int getID();
	bool getCanSelectB();
	void setCanSelectB(bool set);
	bool getCanSelectU();
	void setCanSelectU(bool set);
	void setID(int id);
	void setUnits(Tiles* tl);
	void addEdge(Edge edge);
	void addEdges(vector <Edge> edge);
	void showEdges();
	vector <Edge> getEdges();
	void owns(Vertex has);
	void showOwner();
	vector <Vertex> getOwner();
	string getNameByID(int id);
	vector <Tiles*> getUnits();
	vector <vector<Tiles*>> tiles;
	vector <Tiles*> units;

private:
	string name;
	vector <Vertex> owner;
	vector <Edge> edges;
	int ID;
	bool canSelectU;
	bool canSelectB;
};

