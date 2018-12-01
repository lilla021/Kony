#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"

Edge::Edge(int idfrom, int idto)
{
	IDFrom = idfrom;
	IDTo = idto;
}
void Edge::setIDFrom(int id)
{
	IDFrom = id;
}
int Edge::getIDFrom()
{
	return IDFrom;
}
void Edge::setIDTo(int id)
{
	IDTo = id;
}
int Edge::getIDTo()
{
	return IDTo;
}

Edge::~Edge()
{
}

