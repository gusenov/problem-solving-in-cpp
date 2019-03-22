#ifndef WEIGHTMATRIX_H
#define WEIGHTMATRIX_H

#include "AdjacencyMatrix.h"

// Матрица весов:
class WeightMatrix : public AdjacencyMatrix
{
	public:
		WeightMatrix();
		WeightMatrix(const char* fileName);
		~WeightMatrix();
		
		int isEdgeBetween(int vertex1, int vertex2);
		int getEdgeWeightBetween(int vertex1, int vertex2);
	protected:
};

#endif
