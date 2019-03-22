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
			std::cout << "Ошибка при чтении файла!\n";
		}
	} catch (const std::ifstream::failure& e) {
		std::cout << "Возникло исключение при чтении файла!\n";
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
