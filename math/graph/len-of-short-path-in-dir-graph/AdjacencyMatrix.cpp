#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// Первая строка файла содержит число n, 
		// обозначающее количество вершин графа:
		fin >> verticesCnt;
		
		adjacencyMatrix = new int*[verticesCnt];
		
		// Последующие n строк содержат матрицу смежности графа G.
		for (int i = 0; i < verticesCnt; ++i) {
			adjacencyMatrix[i] = new int[verticesCnt];
			for (int j = 0; j < verticesCnt; ++j) {
				fin >> adjacencyMatrix[i][j];
				
				// Для неориентированного графа элемент adjacencyMatrix[i][j] может принимать значения: 
				// 1 - в графе имеется ребро между вершинами i и j; 
				// 0 - в графе отсутствует ребро между данными вершинами.
				
				// Для ориентированного графа число adjacencyMatrix[i][j] может принимать значения: 
				// 1 - в графе имеется дуга, ведущая из вершины i в вершину j; 
				// 0 - таковая дуга в графе отсутствует.

			}
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	if (adjacencyMatrix) {
		for (int i = 0; i < verticesCnt; ++i) {
			delete [] adjacencyMatrix[i];
		}
		delete [] adjacencyMatrix;
	}
}

int AdjacencyMatrix::isEdgeBetween(int vertex1, int vertex2)
{
	// Если число рёбер из вершины vertex1 графа в вершину vertex2 равно 0
	// И    число рёбер из вершины vertex2 графа в вершину vertex1 больше 0:
	if (adjacencyMatrix[vertex1][vertex2] == 0 && adjacencyMatrix[vertex2][vertex1] > 0)
		return -1;
	
	else if (adjacencyMatrix[vertex1][vertex2] > 0 && adjacencyMatrix[vertex2][vertex1] == 0)
		return 1;

	return 0;
}

int AdjacencyMatrix::getEdgeWeightBetween(int vertex1, int vertex2)
{
	return 1;
}

