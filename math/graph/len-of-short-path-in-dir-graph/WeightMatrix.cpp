#include "WeightMatrix.h"

WeightMatrix::WeightMatrix()
{
}

WeightMatrix::WeightMatrix(const char* fileName):
	AdjacencyMatrix(fileName)
{
}

WeightMatrix::~WeightMatrix()
{
}

int WeightMatrix::isEdgeBetween(int vertex1, int vertex2)
{
	return 0;
}

int WeightMatrix::getEdgeWeightBetween(int vertex1, int vertex2)
{
	return 1;
}
