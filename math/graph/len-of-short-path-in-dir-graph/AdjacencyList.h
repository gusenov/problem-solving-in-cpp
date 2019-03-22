#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "GraphRepresentation.h"

// Список смежности:
class AdjacencyList : public GraphRepresentation
{
	public:
		AdjacencyList();
		AdjacencyList(const char* fileName);
		~AdjacencyList();
		
		int isEdgeBetween(int vertex1, int vertex2);
		int getEdgeWeightBetween(int vertex1, int vertex2);
	protected:
		int** adjacencyList;
};

#endif
