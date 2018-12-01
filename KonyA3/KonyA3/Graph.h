#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<iostream>
#include<list>
#include "Tiles.h"
#include "Vertex.h"

class Graph
{
public:
	Graph();
	Graph(vector<Vertex>allRegions, vector<Vertex>allZones);
	void addEdges();
	//void DFS(int v);
	string findNameRegionZone(int id);
	void createListEdges();
	vector <Vertex> getZones();
	vector <Vertex> getRegions();
	vector <Edge> getEdges();

	int V;
	list<int> *adj;
	//void DFSUtil(int v, bool visited[]);
	vector <Vertex> zones;
	vector <Vertex> regions;
	vector <Edge> edges;
	void setTiles(vector <Vertex>* vov, vector<Tiles>* vot);
	void showGraph(Graph graph);
	Vertex findVertexById(int id);
	void visitNode(int v, int idFree);
	void visitNodeFirstTime(int v);
	vector<bool> manhattanAvailable();
	vector<int> availableNodes(int v, vector<Vertex> regions);
	vector<int> availableRegions(vector<Vertex> zones);
	int getUpperManhattan(int v);
	bool isRegion(int id);
	bool capacityVisited(vector<Vertex> regions, int id);
	bool *visited;
	~Graph();
};

