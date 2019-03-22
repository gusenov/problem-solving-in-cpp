#include <iostream>
#include "GraphRepresentation.h"
#include "IncidenceMatrix.h"
#include "AdjacencyMatrix.h"
#include "EdgeList.h"
#include "AdjacencyList.h"
#include "WeightMatrix.h"
#include <windows.h>

using namespace std;

// ������� �� ���������:
void cyrillic() {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ � ��� ��������� �Lucida Console�. 
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
		dist[i] = INT_MAX,  // �������� �������� ����� ������ �������������.
		sptSet[i] = false;
	
	// �������� ������� start ����� ������ 0, 
	// ������ ��� ��� ������� � ��������:
	dist[start] = 0;
	
	for (int count = 0; count < V - 1; count++) {
		// ������� ����� �������, ������� ����� ����������� �����:
		int u = minDistance(dist, sptSet, V);
		
		sptSet[u] = true;
		
		// ���������� ��� ������� � ������� �� ��������� ������� ���� ����, 
		// �� ���������� ������ �����������:
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && g.isEdgeBetween(u, v) > 0 && dist[u] != INT_MAX)
				// ������ �� ������������� ������ �������� ����� ������ 
				// ����� ��������� ����� � ������ ���� �� ��������� ������� � ��������������� �������, 
				// �� ������ � ��� ������, ���� ���������� ����� ����� ������ ����������� �������� �����:
				if (dist[u] + g.getEdgeWeightBetween(u, v) < dist[v])
					dist[v] = dist[u] + g.getEdgeWeightBetween(u, v);
	}
	
	cout << "����� ����������� ����:\n";
	for (int i = 0; i < V; i++) 
		if (dist[i] == INT_MAX)
			cout << "\t��� ���� � ������� " << i + 1 << "!\n";
		else
			cout << "\t�� ������� " << i + 1 << " = " << dist[i] << ".\n";
	
	delete [] sptSet;
	delete [] dist;
}

int main(int argc, char** argv) {
	cyrillic();
	
	cout << "������� ��������� �������>";
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

