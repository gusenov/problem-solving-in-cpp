#include "GraphRepresentation.h"
#include <iostream>

GraphRepresentation::GraphRepresentation()
{
}

GraphRepresentation::GraphRepresentation(const char* fileName)
{
	try {
		fin.open(fileName, std::ios::in);
		if (fin.fail()) {
			std::cout << "������ ��� ������ �����!\n";
		}
	} catch (const std::ifstream::failure& e) {
		std::cout << "�������� ���������� ��� ������ �����!\n";
	}
}

GraphRepresentation::~GraphRepresentation()
{
	fin.close();
}

int GraphRepresentation::getVerticesCnt() const
{
	return verticesCnt;
}
