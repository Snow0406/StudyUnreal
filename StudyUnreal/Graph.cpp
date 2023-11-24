#include "Graph.h"

void Graph::InitializeGraph(int nodeCount)
{
	graph = new Node * [nodeCount];
	isVisited = new bool[nodeCount];
	for (int i = 0; i < nodeCount; i++)
	{
		graph[i] = NULL;
		isVisited[i] = false;
	}
	count = 0;
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
	count++;
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
		} else nextNode = nextNode->next;
	}
	count--;
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

bool Graph::visitVertex(int node)
{
	return false;
}

void Graph::BreadthFirstSerch(int node)
{
	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (!isVisited[temp]) {
			cout << "방문한 노드 : " << temp << endl;

			isVisited[temp] = true;
			int index = 0;
			Node* tempNode = graph[temp];
			while (tempNode != NULL)
			{
				if (!isVisited[tempNode->data]) {
					q.push(tempNode->data);
				}
				tempNode = tempNode->next;
				index++;
			}
		}
	}
}

void Graph::DepthFirstSerch(int node)
{
	stack<int> s;
	s.push(node);
	
	while (!s.empty())
	{
		int temp = s.top();
		s.pop();
	
		if (!isVisited[temp]) {
			cout << "방문한 노드 : " << temp << endl;
			isVisited[temp] = true;
			int index = 0;
			Node* tempNode = graph[temp];
			while (tempNode != NULL)
			{
				if (!isVisited[tempNode->data]) {
					s.push(temp);
					s.
				}
				tempNode = tempNode->next;
				index++;
			}
		}
	}
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
