#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

#include "GraphRepresentation.h"

// Матрица смежности:
class AdjacencyMatrix : public GraphRepresentation
{
	public:
		AdjacencyMatrix();
		AdjacencyMatrix(const char* fileName);
		~AdjacencyMatrix();
		
		int isEdgeBetween(int vertex1, int vertex2);
		int getEdgeWeightBetween(int vertex1, int vertex2);
	protected:
		int** adjacencyMatrix;
};

#endif
