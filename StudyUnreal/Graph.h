#pragma once

#include "stack.h" // º¯°æ
#include <stack>
#include <queue>
#include "queue.h" // º¯°æ

class Graph
{
private:
	int count;
	bool* isVisited;
	Node** graph;
public:
	void InitializeGraph(int nodeCount);
	void AddEdge(int from, int to);
	void DeleteEdge(int node, int deleteEdge);
	void ShowGraphEdge(int node);
	bool visitVertex(int node);
	void BreadthFirstSerch(int node); //Queue ³ÊºñÅ½»ö
	void DepthFirstSerch(int node); //Stack ±íÀÌÅ½»ö
private:
	Node* CreateNode(int data);
public:
	Graph();
	~Graph();
};