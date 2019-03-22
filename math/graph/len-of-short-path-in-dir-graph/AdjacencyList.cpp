#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
}

AdjacencyList::AdjacencyList(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// ������ ������ ����� �������� ����� n, 
		// ������������ ���������� ���� �����:
		fin >> edgesCnt;
		
		adjacencyList = new int*[edgesCnt];
		
		// ����������� n ����� �������� ������ ���������, ��� i-�� ������ ������ �������� ��������� �������:
		// Ni gi1 gi2 ... giNi , 
		// ��� Ni - ���������� ������� � i-�� �������� ������ �����; 
		//     gi1 gi2 ... giNi - ������������������ (������) ������, ������� � i-�� �������� ����� G.
		for (int i = 0; i < edgesCnt; ++i) {
			int cnt;
			fin >> cnt;
			
			adjacencyList[i] = new int[cnt];
			for (int j = 0; j < cnt; ++j) {
				fin >> adjacencyList[i][j];
			}
		}
	}
}

AdjacencyList::~AdjacencyList()
{
	if (adjacencyList) {
		for (int i = 0; i < edgesCnt; ++i) {
			delete [] adjacencyList[i];
		}
		delete [] adjacencyList;
	}
}

int AdjacencyList::isEdgeBetween(int vertex1, int vertex2)
{
	return 0;
}

int AdjacencyList::getEdgeWeightBetween(int vertex1, int vertex2)
{
	return 1;
}

