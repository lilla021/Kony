#pragma once
#include <iostream>
#include <string>
#include <vector>
class Edge
{
public:
	Edge(int idfrom, int idto);
	int IDFrom;
	int IDTo;
	int getIDFrom();
	void setIDFrom(int id);
	int getIDTo();
	void setIDTo(int id);
	~Edge();
};

