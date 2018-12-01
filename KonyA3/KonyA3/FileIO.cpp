#include <iostream>
#include <fstream>
#include <sstream>
#include "FileIO.h"
using namespace std;
FileIO::FileIO(string name)
{
	fileName = name;
}
void FileIO::readFile()
{
	file.open(fileName);
	if (!file)
	{
		cerr << "Unable to open file " << fileName << endl;
		system("pause");
		exit(1);
	}
	// for first line only
	string line;
	file >> line;
	bool isTitle = false;
	isTitle = isRightTitle(line);
	while (!file.eof())
	{
		file >> line;
		if (line.find("[") != string::npos) {
			isTitle = isRightTitle(line);
		}
		else
		{
			isTitle = false;
		}
		if (!isTitle)
		{
			if (ID == ZONES)
			{
				createVertex(line, false);
			}
			else if (ID == REGIONS)
			{
				createVertex(line, true);
			}
			else if (ID == NEIGHBORS)
			{
				istringstream iss(line);
				string lineRead;
				getline(iss, lineRead, ',');
				int idNeighbor;
				int idRegion;
				bool isZone;
				if (lineRead.find("|") != string::npos)
				{
					idRegion = getIDFromZoneList(lineRead);
					isZone = true;
				}
				else
				{
					idRegion = getIDFromRegionList(lineRead);
					isZone = false;
				}
				while (getline(iss, lineRead, ','))
				{
					if (lineRead.find("|") != string::npos)
					{
						idNeighbor = getIDFromZoneList(lineRead);
					}
					else
					{
						idNeighbor = getIDFromRegionList(lineRead);
					}
					fillEdges(idRegion, idNeighbor, isZone);
				}
			}
		}
	}
	if (ID != 3) // it means it went to all sections in the file
	{
		fileError();
	}
	cout << fileName << " Has succesfully been read!" << endl << "File reading completed." << endl;
	file.close();
}
bool FileIO::isRightTitle(string line)
{
	if (line.find("[") == string::npos && line.find("]") == string::npos) {
		fileError();
	}
	else
	{
		if (line.compare("[Zones]") == 0)
		{
			ID = ZONES;
			return true;
		}
		else if (line.compare("[Regions]") == 0)
		{
			ID = REGIONS;
			return true;
		}
		else if (line.compare("[Neighbors]") == 0)
		{
			ID = NEIGHBORS;
			return true;
		}
		else
		{
			fileError();
		}
	}
}
int FileIO::getIDFromRegionList(string name)
{
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getName().compare(name) == 0) {
			return regions.at(i).getID();
		}
	}
}
int FileIO::getIDFromZoneList(string name)
{
	for (size_t i = 0; i < zones.size(); i++)
	{
		if (zones.at(i).getName().compare(name) == 0) {
			return zones.at(i).getID();
		}
	}
}
void FileIO::fillEdges(int id, int idNeigh, bool isZone) {
	if (isZone) {
		for (size_t i = 0; i < zones.size(); i++)
		{
			if (zones.at(i).getID() == id) {
				Edge edge(id, idNeigh);
				zones.at(i).addEdge(edge);
			}
		}
	}
	else {
		for (size_t i = 0; i < regions.size(); i++)
		{
			if (regions.at(i).getID() == id) {
				Edge edge(id, idNeigh);
				regions.at(i).addEdge(edge);
			}
		}
	}
}
void FileIO::createVertex(string line, bool isRegion) {
	istringstream iss(line);
	getline(iss, line, ',');
	for (int n = 0; n < line.length(); n++)
	{
		if (!isdigit(line[n]))
		{
			fileError();
		}
	}
	stringstream sid(line);
	int x = 0;
	sid >> x;
	compareExistingID(x);
	string name;
	getline(iss, name, ',');
	if (name.compare("Manhattan") == 0) {
		Vertex vertex(name, x, zones);
		regions.push_back(vertex);
	}
	else {
		Vertex vertex(name, x);
		if (isRegion) {
			regions.push_back(vertex);
		}
		else {
			zones.push_back(vertex);
		}
	}
}
void FileIO::compareExistingID(int x) {
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == x) {
			fileError();
		}
	}
	for (size_t i = 0; i < zones.size(); i++)
	{
		if (zones.at(i).getID() == x) {
			fileError();
		}
	}
}
void FileIO::fileError() {
	cout << "Unable to read file " << fileName << " File format error." << endl;
	file.close();
	system("pause");
	exit(1);
}

