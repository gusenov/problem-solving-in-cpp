#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

// ��������� ������ "�������� ������":
class BinaryTree
{
	public:
		BinaryTree();
		~BinaryTree();
		
		void insert(const int& value);
		
		// ����� ��������� ������ �� �����:
		void print();
		
		// ������� �� ����� ������ ��������, ���������� ��������:
		void printLeafs();
		
	protected:
		TreeNode* root;

		// ����� ��������� ������ �� �����:
		void print(struct TreeNode* node, int space);
		
		// ������� �� ����� ������ ��������, ���������� ��������:
		void printLeafs(struct TreeNode* node);
		
		// �������� ������������ ������, ���������� �������� �������:
		void clearMemory(struct TreeNode* node);
};

#endif
