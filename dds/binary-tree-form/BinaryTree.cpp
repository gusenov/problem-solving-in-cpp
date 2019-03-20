#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>

#define COUNT 10 

using namespace std;

BinaryTree::BinaryTree(): root(0) {
}

void BinaryTree::insert(const int& value) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->value = value;
	newNode->left = 0;
	newNode->right = 0;

	TreeNode* currentNode = root;
	TreeNode* parent = 0;
	
	// Цикл итеративно проходит путь по дереву, пока не найдет точку вставки:
	while (currentNode) {
		parent = currentNode;
		
		// Идти налево, если новое значение меньше значения текущего узла:
		if (value < currentNode->value)
			currentNode = currentNode->left;
		
		// Идти направо, если новое значение больше или равно значению текущего узла
		else
			currentNode = currentNode->right;
	}
	
	if (!parent) {
		root = newNode;
	} else if (value < parent->value) {
		parent->left = newNode;
	} else {
		parent->right = newNode;
	}
}

// Вывод бинарного дерева на экран:
void BinaryTree::print() {
	cout << "Вывод бинарного дерева на экран:\n";
	print(root, 0);
	cout << endl;
}

// Вывод бинарного дерева на экран:
void BinaryTree::print(struct TreeNode* node, int space) {
    if (node == 0) return;
    space += COUNT;
  
    print(node->right, space);  
  
    cout << endl;  
    for (int i = COUNT; i < space; ++i)  
        cout << " ";
    cout << node->value << endl;  
  
    print(node->left, space);  

}

// Вывести на экран только элементы, являющиеся листьями:
void BinaryTree::printLeafs() {
	cout << "Элементы, являющиеся листьями:\n";
	printLeafs(root);
	cout << endl;
}

void BinaryTree::printLeafs(struct TreeNode* node) {
	if (node) {
		if (node->left || node->right) {
			printLeafs(node->left);
			printLeafs(node->right);
		} else {
			cout << node->value << " ";
		}
	}
}

BinaryTree::~BinaryTree() {
	// Очистить динамическую память, занимаемую бинарным деревом:
	clearMemory(root);
}

// Очистить динамическую память, занимаемую бинарным деревом:
void BinaryTree::clearMemory(struct TreeNode* node) {
	if (node) {
		clearMemory(node->left);
		clearMemory(node->right);
		free(node);
	}
}
