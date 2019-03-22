#include <iostream>
#include "GraphRepresentation.h"
#include "IncidenceMatrix.h"
#include "AdjacencyMatrix.h"
#include "EdgeList.h"
#include "AdjacencyList.h"
#include "WeightMatrix.h"
#include <windows.h>

using namespace std;

// Переход на кириллицу:
void cyrillic() {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» и там выбираете «Lucida Console». 
}

int minDistance(int dist[], bool sptSet[], int sz) 
{ 
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < sz; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 

void dijkstra(GraphRepresentation& g, int start) {
	int V = g.getVerticesCnt();
	
	int* dist = new int[V];
	bool* sptSet = new bool[V];
	
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX,  // присвоим вершинам метки равные бесконечности.
		sptSet[i] = false;
	
	// Присвоим вершине start метку равную 0, 
	// потому как эта вершина — источник:
	dist[start] = 0;
	
	for (int count = 0; count < V - 1; count++) {
		// Выберем такую вершину, которая имеет минимальную метку:
		int u = minDistance(dist, sptSet, V);
		
		sptSet[u] = true;
		
		// Рассмотрим все вершины в которые из выбранной вершины есть путь, 
		// не содержащий вершин посредников:
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && g.isEdgeBetween(u, v) > 0 && dist[u] != INT_MAX)
				// Каждой из рассмотренных вершин назначим метку равную 
				// сумме выбранной метки и длинны пути из выбранной вершины в рассматриваемую вершину, 
				// но только в том случае, если полученная сумма будет меньше предыдущего значения метки:
				if (dist[u] + g.getEdgeWeightBetween(u, v) < dist[v])
					dist[v] = dist[u] + g.getEdgeWeightBetween(u, v);
	}
	
	cout << "Длина кратчайшего пути:\n";
	for (int i = 0; i < V; i++) 
		if (dist[i] == INT_MAX)
			cout << "\tнет пути в вершину " << i + 1 << "!\n";
		else
			cout << "\tдо вершины " << i + 1 << " = " << dist[i] << ".\n";
	
	delete [] sptSet;
	delete [] dist;
}

int main(int argc, char** argv) {
	cyrillic();
	
	cout << "Введите начальную вершину>";
	int startVertex;
	cin >> startVertex;

	GraphRepresentation* g1 = new IncidenceMatrix("input/incidence-matrix-digraph.txt");
	dijkstra(*g1, startVertex - 1);
	delete g1;
	
	GraphRepresentation* g2 = new AdjacencyMatrix("input/adjacency-matrix-digraph.txt");
	dijkstra(*g2, startVertex - 1);
	delete g2;

	GraphRepresentation* g3 = new EdgeList("input/edges-list-digraph.txt");
	delete g3;	
	
	GraphRepresentation* g4 = new AdjacencyList("input/adjacency-list-digraph.txt");
	delete g4;
	
	GraphRepresentation* g5 = new WeightMatrix("input/weight-matrix-digraph.txt");
	delete g5;
	
	system("pause");
	return 0;
}

