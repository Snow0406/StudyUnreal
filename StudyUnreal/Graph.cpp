#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
	graph = new Node * [nodeCount];
	for (int i = 0; i < nodeCount; i++)
	{
		graph[i] = NULL;
	}
}

void Graph::AddEdge(int from, int to)
{
	Node* newNode = new Node{ to, NULL };
	if (graph[from] == NULL) graph[from] = newNode;
	else {
		Node* nextNode = graph[from];
		while (nextNode->next != NULL)
		{
			nextNode = nextNode->next;
		}
		nextNode->next = newNode;
	}
}
/*
node = arr[node]
*/

void Graph::DeleteEdge(int node, int deleteEdge)
{
	if (graph[node] == NULL) return;
	
	Node* preNode = NULL;
	Node* nextNode = graph[node]->next;
	while (nextNode != NULL)
	{
		preNode = nextNode;
		if (nextNode->data == deleteEdge) {
			preNode->next = nextNode->next;
			delete nextNode;
		}
		else nextNode = nextNode->next;
	}
}

void Graph::ShowGraphEdge(int node)
{
	if (graph[node] != NULL) {
		cout << "[" << node << "] : " << "[";
		Node* nextNode = graph[node];
		while (nextNode != NULL)
		{
			printf(" %d", nextNode->data);
			nextNode = nextNode->next;
		}
		cout << " ]" << endl;
		} else cout << "[" << node << "] " << "[NULL]" << endl;
}

Node* Graph::CreateNode(int data)
{
	return nullptr;
}

Graph::Graph()
{
}

Graph::~Graph()
{
}
