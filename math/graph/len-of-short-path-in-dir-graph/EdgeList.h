#ifndef EDGELIST_H
#define EDGELIST_H

#include "GraphRepresentation.h"

// Список рёбер:
class EdgeList : public GraphRepresentation
{
	public:
		EdgeList();
		EdgeList(const char* fileName);
		~EdgeList();
		
		int isEdgeBetween(int vertex1, int vertex2);
		int getEdgeWeightBetween(int vertex1, int vertex2);
	protected:
		int** edgesList;
};

#endif
