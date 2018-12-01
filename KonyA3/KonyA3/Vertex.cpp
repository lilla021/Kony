#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Tiles.h"
using namespace std;
Vertex::Vertex()
{
}
Vertex::Vertex(string nom, int id)
{
	name = nom;
	ID = id;
	canSelectB = true;
	canSelectU = true;
}
Vertex::Vertex(string nom, int id, vector <Vertex> has)
{
	name = nom;
	ID = id;
	owner = has;
	canSelectB = true;
	canSelectU = true;
}
void Vertex::addEdge(Edge edge)
{
	edges.push_back(edge);
}
void Vertex::addEdges(vector <Edge> edge)
{
	for (size_t i = 0; i < edges.size(); i++)
	{
		edges.push_back(edge[i]);
	}
}
void Vertex::showEdges()
{
	for (size_t i = 0; i < edges.size(); i++)
	{
		cout << edges[i].getIDFrom() << " " << edges[i].getIDTo() << endl;
	}
}
vector <Edge> Vertex::getEdges()
{
	return edges;
}
vector <Tiles*> Vertex::getUnits()
{
	return units;
}
void Vertex::owns(Vertex has)
{
	owner.push_back(has);
}
void Vertex::showOwner()
{
	for (int i = 0; i < owner.size(); i++)
	{
		cout << owner[i].getName();
		cout << " | ";
	}
}
vector <Vertex> Vertex::getOwner()
{
	return owner;
}
string Vertex::getName()
{
	return name;
}
string Vertex::getNameByID(int id)
{
	if (id == ID)
		return name;
}
int Vertex::getID()
{
	return ID;
}
bool Vertex::getCanSelectB()
{
	return canSelectB;
}
void Vertex::setCanSelectB(bool set)
{
	canSelectB = set;
}
bool Vertex::getCanSelectU()
{
	return canSelectU;
}
void Vertex::setCanSelectU(bool set)
{
	canSelectU = set;
}
void Vertex::setID(int id)
{
	ID = id;
}
void Vertex::setUnits(Tiles* tl)
{
	units.push_back(tl);
}

Vertex::~Vertex()
{
}

