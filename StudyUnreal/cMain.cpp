#include "Graph.h"

void main()
{
	Graph graph;

	graph.InitializeGraph(9);

	graph.AddEdge(0, 2);
	graph.AddEdge(0, 1);

	graph.AddEdge(1, 4);
	graph.AddEdge(1, 3);

	graph.AddEdge(2, 8);
	graph.AddEdge(2, 3);

	graph.AddEdge(3, 7);
	graph.AddEdge(3, 6);
	graph.AddEdge(3, 5);

	graph.AddEdge(4, 5);
	graph.AddEdge(4, 6);
	graph.AddEdge(4, 3);

	graph.AddEdge(5, 7);

	graph.AddEdge(6, 5);

	graph.AddEdge(7, 6);

	graph.AddEdge(8, 0);
	graph.AddEdge(8, 7);

	for (int i = 0; i < 9; i++)
	{
		graph.ShowGraphEdge(i);
	}

}