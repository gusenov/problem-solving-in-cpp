#include <iostream>
#include <string>
#include "treenodelib.hpp"
#include "binstreelib.hpp"
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

// ������������ �������, ������� ���������� ������� ���� � ������� elem �� �������� ������ ������:
template <class T>
int NodeLevel(const BinSTree<T> &t, const T& elem) {
	// ���� �� ����� � ���� ������ ���� ����, ���������� ������� (level) ����.
	// ������� ����� ������� ������� �� 0.
	// ������������ ������� ����� ������ ���� ��� ������� (depth). 
	int level = 0;
	
	TreeNode<T> *node = t.root;
	
	while (node) {
		// ����� �������� � ������ �������������� � ����������� �������� "==" ��� ��������� ������ ���� � ���������� item.
		// ��������������, ��� ��� �������� ���������� ��� ���� T. 
		// � ������, ���� T  - ����������� ���, �������� "==" ������ ���� ���������� ��� ������� ����.
		if (elem == node->data)
			return level;
		else {			
			if (elem < node->data)
				node = node->left;
			else
				node = node->right;
			level++;
		}
	}
	
	return -1;  // ���������� -1, ���� ������ ���� ��� �� ������.
}

// ������������ ���������� ��������� ������:
void testTreeNode() {
	TreeNode<char*> D((char*)"D", 0, 0);
	TreeNode<char*> E((char*)"E", 0, 0);
	TreeNode<char*> B((char*)"B", &D, &E);
	TreeNode<char*> F((char*)"F", 0, 0);
	TreeNode<char*> C((char*)"C", 0, &F);
	TreeNode<char*> A((char*)"A", &B, &C);
	Inorder(&A, Print);  // ������������: D-B-E-A-C-F.
}

// ������� ��������� �������� ���� ��������� ������ ������:
void PrintBinSTree(int &item) {
	std::cout << '\n' << item;
}

// ������������ ����������� ������� ����� ��������� ������ ������:
void testBinSTree() {
	int i;
	int values[] = { 10, 7, 15, 2, 8, 1, 6, 9, 4, 3, 5 };
	int len = sizeof(values) / sizeof(int);
	BinSTree<int> bst;
	
	cout << "���� ��������� ������ ������ � ������������ �������: " << endl;
	for (i = 0; i < len; i++ ) {
		bst.Insert(values[i]);
	}
	bst.Print(PrintBinSTree);
	
	cout << endl << endl << "�������: " << endl << endl;
	for (i = 0; i < len; i++ ) {
		cout << "������� ���� �� ��������� " << values[i] << " = " << NodeLevel(bst, values[i]) << endl;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	cyrillic();
	
	testBinSTree();
	
	system("pause");
	return 0;
}

