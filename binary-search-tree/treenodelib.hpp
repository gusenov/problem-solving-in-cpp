#ifndef TREE_NODE_LIB_HPP
#define TREE_NODE_LIB_HPP

#include <iostream>

// ����� BinSTree ����� ������������� ��� TreeNode, 
// ��� � ���������� �������� �������� ������� BinSTree ������ � �������� ������ TreeNode:
template <class T>
class BinSTree;  // ��� ����� ��� ���������� �������� �������� ������.

// ����� ���� ��������� ������:
template <class T>  // ����� TreeNode  ������� �� �������, �������� T �������� - ��� ������ ���� data.
class TreeNode {
	
	template <class U>
	friend int NodeLevel(const BinSTree<U> &t, const U& elem);
	
	friend class BinSTree<T>;

private:
	
	TreeNode<T> *left;
	TreeNode<T> *right;

public:
	
	T data;  // ���� ������.
	// ��� ���� �������� ��������, ������� ������ ����� ������ ������ � ������ ����, �� �� ����� �������� ��������� ������.
	
	// �� ��������� ���������� ������������� 0, �, ����� �������, ���� ���������������� ��� ����:
	TreeNode(const T& item, TreeNode<T> *lptr = 0, TreeNode<T> *rptr = 0);
	
	TreeNode<T> *Left(void) const;  // ��������� �� ������ ����.
	
	TreeNode<T> *Right(void) const;  // ��������� �� ������� ����.
};

template <class T>
void Inorder(TreeNode<T> *t, void (*visit)(T &item));  // �������, ����������� ������������ ����� ����������� ������.

void Print(char* &item);  // ������� ������ ������.
// ��� ������ �� ����� ������ ����� ���������� ��������� ��������� �����:
//  Inorder(root, Print);

template <class T>
TreeNode<T> * CopyTree(TreeNode<T> *t);  // ������� � ������������ ������ ����� ������, ������ �������� ������� �� � �������� ���������.

template <class T>
void DeleteTree(TreeNode<T> * t);  // ������� �� ������������ ������ ���� ������, ��������� �� ������ �������� ������� �� � �������� ���������.

#include "treenodelib.hpp"

template <class T>
TreeNode<T>::TreeNode(const T& item, TreeNode<T> *lptr, TreeNode<T> *rptr): data(item), left(lptr), right(rptr) {
}

template <class T>
TreeNode<T> * TreeNode<T>::Left(void) const {
	return left;
}

template <class T>
TreeNode<T> * TreeNode<T>::Right(void) const {
	return right;
}

// �������, ����������� ������������ ����� ����������� ������:
template <class T>
void Inorder(TreeNode<T> *t, void (*visit)(T &item)) {
	// ������� �������� ��� ������������ ������ ����������� ��������� ������ ���������:
	//  1) ����������� ������ ���������;
	//  2) ��������� ����;
	//  3) ����������� ������� ���������.
	// ����� ����������� ���������� LNR-������������ (left, node, right).
	
	if (t) {  // ����������� ����������� �� ������ ��������� (t == 0).
		Inorder(t->Left(), visit);  // ������ ����� ���������.
		(*visit)(t->data);  // �������� ����.
		Inorder(t->Right(), visit);  // ������ ������ ���������.
	}
}

// ��������, � ��� ������� ������, ��������� �� �����, ������ ������� ����� ��� char*, �.�. �������� ����������� �� ������. 
// ������ ������ ������-������  ���������� root.  
// ��� ���������� ������� �� ����� ������ ������, ��������� ������������ ������� �����������. 
// ������� ������ ������ � ����� ������ ������ ���� �������� ���������:
void Print(char* &item) {
	std::cout << '\n' << item;
}

// ������� CopyTree ������� � ������������ ������ ����� ������, ������ �������� ������� �� � �������� ���������:
template <class T>
TreeNode<T> * CopyTree(TreeNode<T> *t) {
	if (!t)
		return 0;
	
	// ������� ��������� �������� ����� ����������� ����������� ������.
	// ��� ������� ���� ������� ����������� ������� ��������� ����� ��� ������ � ������� �����������, ����� ��������� ��� ����:
	
	TreeNode<T> *newlptr = 0, *newrptr = 0, *newnode;
	
	if (t->Left())
		newlptr = CopyTree(t->Left());
	
	if (t->Right())
		newrptr = CopyTree(t->Right());
	
	newnode = new TreeNode<T>(t->data, newlptr, newrptr);
	
	if (!newnode) {
		std::cout << "Memory allocation error";
		exit(1);
	}
	
	return newnode;
} 

// ������� DeleteTree ������� �� ������������ ������ ���� ������, ��������� �� ������ �������� ������� �� � �������� ���������:
template <class T>
void DeleteTree(TreeNode<T> * t) {
	if (t) {
		DeleteTree(t->Left());
		DeleteTree(t->Right());
		delete t;
	}
}

#endif

