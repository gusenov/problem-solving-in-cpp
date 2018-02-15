#ifndef BIN_S_TREE_HPP
#define BIN_S_TREE_HPP

#include <iostream>
#include "treenodelib.hpp"

// �������� ������� ������ (binary search tree) ���������� �������� ������, ���������� �� ��������: 
// ��� ������� ���� �������� ������ � ����� ��������� ������, ��� � ���� ����, � � ������ - ������ ���� �����.

// ����� ��������� ������ ������:
template <class T>  // ����� BinSTree ������� �� �������, �������� �������� T - ��� ������ ����.
class BinSTree {

	template <class U>
	friend int NodeLevel(const BinSTree<U> &t, const U& elem);

private:
	
	TreeNode<T> *root;  // ��������� �� ������ ������.
	TreeNode<T> *current;  // ��������� �� ������� ����.
	
	int size; // ����� ����� � ������.
	
	TreeNode<T> * FindNode(const T& item, TreeNode<T> * &parent) const;  // �������� ����� FindNode ������������ ����� ���� �� �������� ������.

public:
	
	BinSTree(void);  // �����������.
	BinSTree(const BinSTree<T> & tree);  // ����������� �����������.
	~BinSTree(void);  // ����������.
	BinSTree<T>& operator=(const BinSTree<T> & tree);  // ������������� �������� ������������.
	int Find(T& item);  // ����� ����.
	void Insert(const T & item);  // ������� ������ � ������.
	void Delete(const T & item);  // �������� ������ �� ������.
	void ClearTree(void);  // ������� ������.
	int TreeEmpty(void) const;  // ������ �����?
	int TreeSize(void) const;  // ������ ������.
	void Update(const T & item);  // �������� ������.
	
	void Print(void (*visit)(T &item));
	
};

// �����������:
template <class T>
BinSTree<T>::BinSTree(void): root(0), current(0), size(0) {
}

// ��� ��� ����� BinSTree �������� ��������� �� ������������ ������, �� ������ ����� ����������� �����������:
template <class T>
BinSTree<T>::BinSTree(const BinSTree<T> & tree) {
	root = CopyTree(tree.root);  // ����������� �������� ������� ������� CopyTree ��� �������� ����� ������ � ������������ ������.
	current = root;
	size = tree.size;
}

// ����������:
template <class T>
BinSTree<T>::~BinSTree(void) {
	DeleteTree(root);
}

// ������������� �������� ������������ �������� ���������� ������������ �����������, 
// �� ����������� ����, ��� ����� ��������� ����� ������ �� ������� "������" ������ ������� DeleteTree:
template <class T>
BinSTree<T>& BinSTree<T>::operator=(const BinSTree<T> & tree) {
   DeleteTree(root);
   root = CopyTree(tree.root);
   current = root;
   size = tree.size;
   return *this;  // ���������� ������ �� ������ - ����� ������� �������� ������������, ��� ��������� ����������� ��������� ����� ��������.
}

// ����� Find ������������ ����� ������ � ������ �� �����:
// (���� ������ ������� � ������ ����� ��������� item, ������������� ������� Find �� ������)
template <class T>
int BinSTree<T>::Find(T& item) {
	TreeNode<T> *parent;
	current = FindNode(item,parent);  // ��� ������ ���� ����� ���������� �������� ������� FindNode.
	if (current) {  // ���� ����� ��������� �������,
		item = current->data;  // item ����� ��������� "������" ������ ����, ���������� �� ����� �����
		return 1;  // � ������� Find ���������� 1.
	}
	else
		return 0;
}

// �������� ����� FindNode ������������ ����� ���� �� �������� ������:
template <class T>
TreeNode<T> * BinSTree<T>::FindNode(const T& item, TreeNode<T> * &parent) const {
	TreeNode<T> *t = root;
	parent = 0;
	
	while (t) {
		// ����� �������� � ������ �������������� � ����������� �������� "==" ��� ��������� ������ ���� � ���������� item.
		// ��������������, ��� ��� �������� ���������� ��� ���� T. 
		// � ������, ���� T  - ����������� ���, �������� "==" ������ ���� ���������� ��� ������� ����.
		// ��� ���� ����� ���� ������������ ��������� �������� �� ����� � ������� FindNode ����� ������ ������ �� �����.
		if (item == t->data)
			break;
		else {
			
			parent = t;  // ����� ��������  parent, ���������� �� ������, ������������ ��������� �� �������� ����� ����.
			// ��������� �� �������� ����� �������������, ��������, ��� �������� ���������� ���� ��� �������������� ��������� ������.
			
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
	}
	
	return t;  // ������������ ��������� �������� ��������� ��  ��������� ����.
}

// ����� Insert ��������� � �������� ��������� ����� ������� ������ � ��������� ��� � ���������� ����� �� ������:
template <class T>
void BinSTree<T>::Insert(const T & item) {
	TreeNode<T> *t = root,  // t - ������� ����.
				*parent = 0,  // parent - ����������.
				*newNode = new TreeNode<T>(item);  // //newNode - �����������.
	
	// ������� ���������� �������� ���� �� ������, ���� �� ������ ����� �������:
	while (t) {  // ������������ �� ������ ������.
		parent = t;  // �������� ��������� parent.
		
		// � ���� ������� ��� ������ � ����������� �� �������� ������:
		if (item < t->data)
			t = t->left;
		else
			t = t->right;
	}
	
	// � ���� ������ ���������� ��������� �������� ������������ ����.
	// ����� ������� ����������, ����� ����� - ����� ��� ������ - ����� ����������� ���� � ������������ ��� � ��������.
	
	if (!parent)  // ���� ������ �����:
		root = newNode;  // �������� � �������� �����.
	
	else if (item < parent->data)  // ���� item ������ ������ ��������:
		parent ->left = newNode;  // �������� ����� �����.
	else  
		parent->right = newNode;  // �������� ������ �����.
	
	current = newNode;  // ������� ����� ���� �������.
	size++;  // � ��������� size.
}

// �������� Delete ������� �� ������ ���� � �������� ������:
// (���� �������� ����� �� ����� ��������� item)
template <class T>
void BinSTree<T>::Delete(const T & item) {
	TreeNode<T> *DNodePtr,  // ��������� �� ��������� ���� D.
				*PNodePtr,  // ��������� �� �������� P ���������� ���� D.
				*RNodePtr;  // ��������� �� ���������� ���� R.
	
	// ������� � ������� ������ FindNode ��������������� ����� ����� ���� �� ������ � ������������ ��������� �� ��� ��������.
	// ����� ����, ������ �������� ��������� � item.
	// �������� ��� ����� � ����� ��� ��������.
	DNodePtr = FindNode(item, PNodePtr);

	// ���� ������� ���� �����������, �������� �����������:	
	if (!DNodePtr)  // ���� ����� ���� �� ������:
		return;  // ����� �� �������.
	
	
	// �������� ���� ������� ���� ��������, ����� ����������, ���� ������������ ������� ���������� ����. 
	// ���������� ������ ���� ������������ ����� �������, ����� ����������� ��������� ��������� ������ ������.
	
	// ��� �������� ���� �������� ������ ��������:
	
	
	// ���� D ����� NULL-���������, ���������� ����� �������� ���, ��� ��������� �� ������ �����:
	// � 2 - ��������� ���� D ����� ������ ����, �� �� ����� �������:
	if (!DNodePtr->right)
		RNodePtr = DNodePtr->left;  // ���������� ������������ ��� ����� ��������� � ��������.
		// (����� �������, ���������� ����� R ����� ����� ��� ����������)
	// � 3 - ��������� ���� ����� ������� ����, �� �� ����� ������:
	else if (!DNodePtr->left)
		RNodePtr = DNodePtr->right;  // ���������� ������������ ��� ������ ��������� � ��������.
		// (�������� ���������� ����������, �� ����������� ����, ��� ���������� ����� ����� ������ ��� ����������)
	
	
	// � 4 - ��������� ���� ����� ����� �������:
	else {  // ���� D ����� ���� �������:
		
		TreeNode<T> * PofRNodePtr = DNodePtr;  // ��������� �� �������� PR ���� R.
		RNodePtr = DNodePtr->left;  // ��������� � ����� ��������� ���� D.
		
		while (RNodePtr->right) {  // ���������� "������", ���� �� ������ ������:
			PofRNodePtr = RNodePtr;
			RNodePtr = RNodePtr->right;
		}
		
		if (PofRNodePtr == DNodePtr)  // ����� ��� ���� D �������� ����������:
			RNodePtr->right = DNodePtr->right;  // ������������ ������ ��������� ���� D � R.
		else {
			PofRNodePtr->right = RNodePtr->left;  // ������������ ����� ��������� ���� R � ��� ��������.
			
			// ������� ���� R � ��������� D:
			RNodePtr->left =  DNodePtr->left;
			RNodePtr->right =  DNodePtr->right;
		}
	}
	
	// �������� ������������ ���� R � ���� P:
	
	if (!PNodePtr)  // � ���� D ��� �������� - �� ������� ������:
		root = RNodePtr;  // ��������� ����� ������ - ���� R.
	
	// � ����� ������� ������������ ���� R � ���� P?
	else if (DNodePtr->data < PNodePtr->data)  // �����:
		PNodePtr->left = RNodePtr;
	else  // ������:
		PNodePtr->right = RNodePtr;
	
	
	// ����� �������� ���� D �� ������ � ��� ������ ������� Delete ���������� ���� ���� � ��������� �� ������� ���������� size:
	delete DNodePtr;  // ������� ���� D �� ������.
	size--;  // ��������� ������ ������.
}

// ������� ������:
template <class T>
void BinSTree<T>::ClearTree(void) {
	DeleteTree(root); 
	root = current = 0;
	size=0;
}

// ������ �����?
template <class T>
int BinSTree<T>::TreeEmpty(void) const {
	return !size;
}

// ������ ������:
template <class T>
int BinSTree<T>::TreeSize(void) const {
	return size;
}

// ����� Update ������ ��� ���������� �������� ���� � ������� ����� ������:
template <class T>
void BinSTree<T>::Update(const T& item) {
	// �� ��������� � �������� ��������� ������ �� ������� ������ �, ���� ��������� ������� ����, ���������� ��� �������� � ���� ���������.
	
	if (current && current->data == item)  // ���� ��� �����, ������������ ���������� ����:
		// ��������, ��� ��������� ����� ������ �� ��������� �������� ���� ������������ �� �� ���� ����� ���� T, 
		// � ������ �� ��������� ����, ��������� ���� ����� ���������� � � ���������� ���������� ������ ����� ��������.
		current->data = item;
		
	else  // � ��������� ������, � ����� ���� ������� ���� �� ���������, ����� ������ ����������  �  ������  ������� Insert:
		Insert(item);
}

template <class T>
void BinSTree<T>::Print(void (*visit)(T &item)) {
	Inorder(root, visit);
}

#endif
