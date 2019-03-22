// Матрица инцидентности — одна из форм представления графа, 
// в которой указываются связи между инцидентными элементами графа (ребро (дуга) и вершина). 
// Столбцы матрицы соответствуют ребрам, строки — вершинам. 
// Ненулевое значение в ячейке матрицы указывает связь между вершиной и ребром (их инцидентность).

#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

#include "GraphRepresentation.h"

// Матрица инциденций:
class IncidenceMatrix : public GraphRepresentation
{
	public:
		IncidenceMatrix();
		IncidenceMatrix(const char* fileName);
		~IncidenceMatrix();
		
		int isEdgeBetween(int vertex1, int vertex2);
		int getEdgeWeightBetween(int vertex1, int vertex2);
	protected:
		int** incidenceMatrix;
};

#endif
