#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
using namespace std;
class FileIO
{
public:
	FileIO(string name);
	vector<Vertex> zones;
	vector<Vertex> regions;
	void readFile();
private:
	ifstream file;
	string fileName;
	const int ZONES = 1;
	const int REGIONS = 2;
	const int NEIGHBORS = 3;
	int ID;
	int getIDFromRegionList(string name);
	bool isRightTitle(string line);
	int getIDFromZoneList(string name);
	void fillEdges(int id, int idNeigh, bool isZone);
	void createVertex(string line, bool isRegion);
	void compareExistingID(int x);
	void fileError();
};

