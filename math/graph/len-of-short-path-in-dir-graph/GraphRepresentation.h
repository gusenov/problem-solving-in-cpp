#ifndef GRAPHREPRESENTATION_H
#define GRAPHREPRESENTATION_H

#include <fstream>

// ��������� ������, ������� ����� �������������� ��� ������������� ����� � ������ ���:
class GraphRepresentation
{
	public:
		GraphRepresentation();
		GraphRepresentation(const char* fileName);
		
		virtual ~GraphRepresentation();
		// ���������� ������������ �������� ������ ������ ����������� �����������. 
		// ������ ��� �������������� ���������� ���������� ������� ������������ ������ 
		// ����� ��������� �� ��������������� ������� �����.
		// ����������� ������� ������������ ������ ����� ��������� �� ������� ����� 
		// � ������������� ������������ ���� �������������� ���������. 
		// �� �������� ��� ���������� � ���, ��� ����� ��������� ������ ����� �������, 
		// ��������������� �������� ������.
		
		int getVerticesCnt() const;
		
		// ���� �������������� �������� < 0 ������ vertex1 <- vertex2.
		// ���� �������������� �������� > 0 ������ vertex1 -> vertex2.
		// ���� �������������� �������� = 0 ������ ����� �����������.
		virtual int isEdgeBetween(int vertex1, int vertex2) = 0;
		
		virtual int getEdgeWeightBetween(int vertex1, int vertex2) = 0;
		
	protected:
		int verticesCnt;
		int edgesCnt;
		
		std::ifstream fin;
};

#endif
