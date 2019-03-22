#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// ������ ������ ����� �������� ����� n, 
		// ������������ ���������� ������ �����:
		fin >> verticesCnt;
		
		adjacencyMatrix = new int*[verticesCnt];
		
		// ����������� n ����� �������� ������� ��������� ����� G.
		for (int i = 0; i < verticesCnt; ++i) {
			adjacencyMatrix[i] = new int[verticesCnt];
			for (int j = 0; j < verticesCnt; ++j) {
				fin >> adjacencyMatrix[i][j];
				
				// ��� ������������������ ����� ������� adjacencyMatrix[i][j] ����� ��������� ��������: 
				// 1 - � ����� ������� ����� ����� ��������� i � j; 
				// 0 - � ����� ����������� ����� ����� ������� ���������.
				
				// ��� ���������������� ����� ����� adjacencyMatrix[i][j] ����� ��������� ��������: 
				// 1 - � ����� ������� ����, ������� �� ������� i � ������� j; 
				// 0 - ������� ���� � ����� �����������.

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
	// ���� ����� ���� �� ������� vertex1 ����� � ������� vertex2 ����� 0
	// �    ����� ���� �� ������� vertex2 ����� � ������� vertex1 ������ 0:
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

