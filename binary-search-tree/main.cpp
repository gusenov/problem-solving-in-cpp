#include <iostream>
#include <string>
#include "treenodelib.hpp"
#include "binstreelib.hpp"
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

// Итерационная функция, которая определяет глубину узла с данными elem на бинарном дереве поиска:
template <class T>
int NodeLevel(const BinSTree<T> &t, const T& elem) {
	// Путь от корня к узлу дерева дает меру, называемую уровнем (level) узла.
	// Уровень корня принято считать за 0.
	// Максимальный уровень узлов дерева есть его глубина (depth). 
	int level = 0;
	
	TreeNode<T> *node = t.root;
	
	while (node) {
		// Поиск элемента в дереве осуществляется с применением операции "==" для сравнения данных узла с параметром item.
		// Предполагается, что эта операция определена для типа T. 
		// В случае, если T  - структурный тип, оператор "==" должен быть перегружен для данного типа.
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
	
	return -1;  // возвращает -1, если такого узла нет на дереве.
}

// Тестирование построения бинарного дерева:
void testTreeNode() {
	TreeNode<char*> D((char*)"D", 0, 0);
	TreeNode<char*> E((char*)"E", 0, 0);
	TreeNode<char*> B((char*)"B", &D, &E);
	TreeNode<char*> F((char*)"F", 0, 0);
	TreeNode<char*> C((char*)"C", 0, &F);
	TreeNode<char*> A((char*)"A", &B, &C);
	Inorder(&A, Print);  // симметричный: D-B-E-A-C-F.
}

// Функция выводящая значение узла бинарного дерева поиска:
void PrintBinSTree(int &item) {
	std::cout << '\n' << item;
}

// Тестирование определения глубины узлов бинарного дерева поиска:
void testBinSTree() {
	int i;
	int values[] = { 10, 7, 15, 2, 8, 1, 6, 9, 4, 3, 5 };
	int len = sizeof(values) / sizeof(int);
	BinSTree<int> bst;
	
	cout << "Узлы бинарного дерева поиска в симметричном порядке: " << endl;
	for (i = 0; i < len; i++ ) {
		bst.Insert(values[i]);
	}
	bst.Print(PrintBinSTree);
	
	cout << endl << endl << "Глубина: " << endl << endl;
	for (i = 0; i < len; i++ ) {
		cout << "Уровень узла со значением " << values[i] << " = " << NodeLevel(bst, values[i]) << endl;
	}
	cout << endl;
}

int main(int argc, char** argv) {
	cyrillic();
	
	testBinSTree();
	
	system("pause");
	return 0;
}

