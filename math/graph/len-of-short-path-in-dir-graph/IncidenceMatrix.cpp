#include "IncidenceMatrix.h"

IncidenceMatrix::IncidenceMatrix()
{
}

IncidenceMatrix::IncidenceMatrix(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// В первой строке файла даны два числа: 
		// n - количество вершин графа, 
		// m - количество рёбер графа.
		fin >> verticesCnt >> edgesCnt;
		
		incidenceMatrix = new int*[verticesCnt];
		
		// Далее содержится матрица инциденций размером (n x m):
		for (int n = 0; n < verticesCnt; ++n) {
			incidenceMatrix[n] = new int[edgesCnt];
			for (int m = 0; m < edgesCnt; ++m) {
				fin >> incidenceMatrix[n][m];
			}
		}
	}
}

IncidenceMatrix::~IncidenceMatrix()
{
	if (incidenceMatrix) {
		for (int n = 0; n < verticesCnt; ++n) {
			delete [] incidenceMatrix[n];
		}
		delete [] incidenceMatrix;
	}
}

int IncidenceMatrix::isEdgeBetween(int vertex1, int vertex2)
{
	for (int m = 0; m < edgesCnt; ++m) {
		// Если vertex1 инцидентна ребру m, и является его концом
		// И    vertex2 инцидентна ребру m, и является его началом:
		if (incidenceMatrix[vertex1][m] < 0 && incidenceMatrix[vertex2][m] > 0)
			return -1;
		
		else if (incidenceMatrix[vertex1][m] != 0 && incidenceMatrix[vertex2][m] != 0)
			return 1;
	}
	
	return 0;
}

int IncidenceMatrix::getEdgeWeightBetween(int vertex1, int vertex2)
{
	return 1;
}
