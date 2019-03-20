#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

// Структура данных "бинарное дерево":
class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		
		void insert(const int& value);
		
		// Вывод бинарного дерева на экран:
		void print();
		
		// Вывести на экран только элементы, являющиеся листьями:
		void printLeafs();
		
	protected:
		TreeNode* root;

		// Вывод бинарного дерева на экран:
		void print(struct TreeNode* node, int space);
		
		// Вывести на экран только элементы, являющиеся листьями:
		void printLeafs(struct TreeNode* node);
		
		// Очистить динамическую память, занимаемую бинарным деревом:
		void clearMemory(struct TreeNode* node);
};

#endif
