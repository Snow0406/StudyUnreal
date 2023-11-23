#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

class Graph
{
private:
	Node** graph;
public:
	void InitializeGraph(int nodeCount);
	void AddEdge(int from, int to);
	void DeleteEdge(int node, int deleteEdge);
	void ShowGraphEdge(int node);
private:
	Node* CreateNode(int data);
public:
	Graph();
	~Graph();
};