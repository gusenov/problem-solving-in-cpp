#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
}

AdjacencyList::AdjacencyList(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// ѕерва€ строка файла содержит число n, 
		// обозначающее количество рЄбер графа:
		fin >> edgesCnt;
		
		adjacencyList = new int*[edgesCnt];
		
		// ѕоследующие n строк содержат списки смежности, где i-а€ строка списка задаетс€ следующим образом:
		// Ni gi1 gi2 ... giNi , 
		// где Ni - количество смежных с i-ой вершиной вершин графа; 
		//     gi1 gi2 ... giNi - последовательность (список) вершин, смежных с i-ой вершиной графа G.
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

