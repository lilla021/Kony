#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Graph.h"
Graph::Graph()
{}
Graph::Graph(vector<Vertex>allRegions, vector<Vertex>allZones)
{
	regions = allRegions;
	zones = allZones;
}
//ACCESSORS
vector <Vertex> Graph::getZones()
{
	return zones;
}
vector <Vertex> Graph::getRegions()
{
	return regions;
}
vector <Edge> Graph::getEdges()
{
	return edges;
}


void Graph::addEdges()
{
	createListEdges();
	V = edges.size();
	adj = new list<int>[V];
	for (int i = 0; i < edges.size(); i++)
	{
		adj[edges.at(i).getIDFrom()].push_back(edges.at(i).getIDTo());
	}
	visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
}
/*void Graph::DFSUtil(int v, bool visited[])
{
visited[v] = true;
cout << endl << findNameRegionZone(v) << " -> ";
list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
if (!visited[*i])
DFSUtil(*i, visited);
}
void Graph::DFS(int v)
{
bool *visited = new bool[V];
for (int i = 0; i < V; i++)
visited[i] = false;
DFSUtil(v, visited);
}*/
string Graph::findNameRegionZone(int id) {
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == id) {
			return regions.at(i).getNameByID(id);
		}
	}
	for (size_t i = 0; i < zones.size(); i++)
	{
		if (zones.at(i).getID() == id) {
			return zones.at(i).getNameByID(id);
		}
	}
}
void Graph::createListEdges() {
	for (int i = 0; i < zones.size(); i++)
	{
		for (size_t j = 0; j < zones.at(i).getEdges().size(); j++)
		{
			edges.push_back(zones.at(i).getEdges().at(j));
		}
	}
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getName().compare("Manhattan") != 0) {
			for (size_t j = 0; j < regions.at(i).getEdges().size(); j++)
			{
				edges.push_back(regions.at(i).getEdges().at(j));
			}
		}
	}
}
vector<int> Graph::availableNodes(int v, vector<Vertex> regions)
{
	vector<int> idAvailables;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		if (isRegion(*i)) {
			if (capacityVisited(regions, *i)) {
				cout << endl << "(" << *i << ") " << findNameRegionZone(*i) << ", ";
				idAvailables.push_back(*i);
			}
		}
		//else {
		// if (!visited[*i]) {
		//  cout << endl << "(" << *i << ") " << findNameRegionZone(*i) << ", ";
		//  idAvailables.push_back(*i);
		// }
		//} 
	}
	return idAvailables;
}
int Graph::getUpperManhattan(int v)
{
	int idAvailable = 0;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) {
		if (!isRegion(*i)) {
			idAvailable = *i;
		}
	}
	return idAvailable;
}
vector<int> Graph::availableRegions(vector<Vertex> regionsVisited)
{
	vector<int> idAvailables;
	list<int>::iterator i;
	bool inList = false;
	for (int i = 0; i < regions.size() - 1; i++) // except Manhattan
	{
		if (visited[regions.at(i).getID()] == false) {
			idAvailables.push_back(regions.at(i).getID());
		}
		else
		{
			if (capacityVisited(regionsVisited, regions.at(i).getID())) {
				idAvailables.push_back(regions.at(i).getID());
			}
		}
	}
	return idAvailables;
}
bool Graph::capacityVisited(vector<Vertex> regions, int id) {
	int counter = 0;
	for (int i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == id)
		{
			counter++;
		}
	}
	if (counter < 2) {
		return true;
	}
	return false;
}
vector<bool> Graph::manhattanAvailable()
{
	vector<bool> manhAvailable;
	manhAvailable.push_back(visited[1]);
	manhAvailable.push_back(visited[2]);
	return manhAvailable;
}
bool Graph::isRegion(int id) {
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == id) {
			return true;
		}
	}
	return false;
}
Vertex Graph::findVertexById(int id) {
	for (size_t i = 0; i < regions.size(); i++)
	{
		if (regions.at(i).getID() == id) {
			return regions.at(i);
		}
	}
	for (size_t i = 0; i < zones.size(); i++)
	{
		if (zones.at(i).getID() == id) {
			return zones.at(i);
		}
	}
}
void Graph::visitNode(int v, int idFree)
{
	visited[v] = true;
	visited[idFree] = false;
	//cout << endl << findNameRegionZone(v) << " -> ";
	//list<int>::iterator i;
	//for (i = adj[v].begin(); i != adj[v].end(); ++i) {
	//if (!visited[*i]) {
	//}
	//}
	//DFSUtil(*i, visited);
}
void Graph::visitNodeFirstTime(int v)
{
	visited[v] = true;
}
/*
void Graph::setTiles(vector<Vertex>* vov, vector<Tiles> vot)
{
int count = 0;
vector<Tiles> name;
for (int i = 0; i < vov->size(); i++) { // going into the 4 regions
for (int j = 0; j < 3; j++) { // going into the 3 vectors of each region
for (int z = 0; z < 3; z++) {  // goinf into the 3 vetors of each vector (3 vectors) inside the ONE REGION
//if (count < vot.size()) {
name.push_back(vot.at(count));
count++;
//}
}
vov->at(i).tiles.push_back(name);
for (int k = 0; k < name.size(); k++) { //to clean the vector NAME bcs we will use it again in the loop
name.pop_back();
}
}
}
}
*/
void Graph::setTiles(vector<Vertex>* vov, vector<Tiles>* vot) {
	int count = 0;
	vector<Tiles*> name;
	for (int i = 0; i < vov->size(); i++) { // going into the 4 regions
		for (int j = 0; j < 3; j++) { // going into the 3 vectors of each region
			for (int z = 0; z < 3; z++) {  // going into the 3 vetors of each vector (3 vectors) inside the ONE REGION
				name.push_back(&(vot->at(count)));
				count++;
			}
			vov->at(i).tiles.push_back(name);
			for (int k = 0; k < name.size(); k++) { //to clean the vector NAME bcs we will use it again in the loop
				name.pop_back();
			}
		}
	}
}
void Graph::showGraph(Graph graph) {
	for (int i = 0; i < graph.regions.size(); i++) {
		cout << graph.regions.at(i).getName() << " has the following tiles:\n";
		for (int j = 0; j < 3; j++)
		{
			cout << endl << "Stack " << j + 1 << ":" << endl;
			for (int k = 0; k < 3; k++)
			{
				cout << graph.regions.at(i).tiles.at(j).at(k)->getName() << "\n";
			}
		}
		cout << "\n";
	}
}

Graph::~Graph()
{
	//delete visited;
	visited = NULL;
}

