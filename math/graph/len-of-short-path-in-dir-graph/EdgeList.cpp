#include "EdgeList.h"

EdgeList::EdgeList()
{
}

EdgeList::EdgeList(const char* fileName):
	GraphRepresentation(fileName)
{
	if (!fin.fail()) {
		// Первая строка файла содержит число n, 
		// обозначающее количество рёбер графа:
		fin >> edgesCnt;
		
		edgesList = new int*[edgesCnt];
		
		// Последующие n строк содержат пары чисел, 
		// обозначающих рёбра для ориентированного и дуги для неориентированного графов:
		for (int i = 0; i < edgesCnt; ++i) {
			edgesList[i] = new int[2];
			for (int j = 0; j < 2; ++j) {
				fin >> edgesList[i][j];
			}
		}
	}
}

EdgeList::~EdgeList()
{
	if (edgesList) {
		for (int i = 0; i < edgesCnt; ++i) {
			delete [] edgesList[i];
		}
		delete [] edgesList;
	}
}

int EdgeList::isEdgeBetween(int vertex1, int vertex2)
{
	return 0;
}

int EdgeList::getEdgeWeightBetween(int vertex1, int vertex2)
{
	return 1;
}

