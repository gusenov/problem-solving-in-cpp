#ifndef GRAPHREPRESENTATION_H
#define GRAPHREPRESENTATION_H

#include <fstream>

// Структура данных, которая будет использоваться для представления графа в памяти ЭВМ:
class GraphRepresentation
{
	public:
		GraphRepresentation();
		GraphRepresentation(const char* fileName);
		
		virtual ~GraphRepresentation();
		// Деструктор полиморфного базового класса должен объявляться виртуальным. 
		// Только так обеспечивается корректное разрушение объекта производного класса 
		// через указатель на соответствующий базовый класс.
		// Уничтожение объекта производного класса через указатель на базовый класс 
		// с невиртуальным деструктором дает неопределенный результат. 
		// На практике это выражается в том, что будет разрушена только часть объекта, 
		// соответствующая базовому классу.
		
		int getVerticesCnt() const;
		
		// Если результирующее значение < 0 значит vertex1 <- vertex2.
		// Если результирующее значение > 0 значит vertex1 -> vertex2.
		// Если результирующее значение = 0 значит ребро отсутствует.
		virtual int isEdgeBetween(int vertex1, int vertex2) = 0;
		
		virtual int getEdgeWeightBetween(int vertex1, int vertex2) = 0;
		
	protected:
		int verticesCnt;
		int edgesCnt;
		
		std::ifstream fin;
};

#endif
