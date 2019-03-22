// ������� ������������� � ���� �� ���� ������������� �����, 
// � ������� ����������� ����� ����� ������������ ���������� ����� (����� (����) � �������). 
// ������� ������� ������������� ������, ������ � ��������. 
// ��������� �������� � ������ ������� ��������� ����� ����� �������� � ������ (�� �������������).

#ifndef INCIDENCEMATRIX_H
#define INCIDENCEMATRIX_H

#include "GraphRepresentation.h"

// ������� ����������:
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
