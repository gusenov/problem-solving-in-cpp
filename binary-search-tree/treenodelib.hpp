#ifndef TREE_NODE_LIB_HPP
#define TREE_NODE_LIB_HPP

#include <iostream>

// Класс BinSTree будет дружественным для TreeNode, 
// что в дальнейшем позволит получить методам BinSTree доступ к закрытым данным TreeNode:
template <class T>
class BinSTree;  // это класс так называемых бинарных деревьев поиска.

// Класс узла бинарного дерева:
template <class T>  // класс TreeNode  основан на шаблоне, параметр T которого - тип данных поля data.
class TreeNode {
	
	template <class U>
	friend int NodeLevel(const BinSTree<U> &t, const U& elem);
	
	friend class BinSTree<T>;

private:
	
	TreeNode<T> *left;
	TreeNode<T> *right;

public:
	
	T data;  // поле данных.
	// Это поле является открытым, клиенты класса имеют прямой доступ к данным узла, но не могут изменить структуру дерева.
	
	// По умолчанию указателям присваивается 0, и, таким образом, узел инициализируется как лист:
	TreeNode(const T& item, TreeNode<T> *lptr = 0, TreeNode<T> *rptr = 0);
	
	TreeNode<T> *Left(void) const;  // указатель на левого сына.
	
	TreeNode<T> *Right(void) const;  // указатель на правого сына.
};

template <class T>
void Inorder(TreeNode<T> *t, void (*visit)(T &item));  // функция, реализующая симметричный метод прохождения дерева.

void Print(char* &item);  // функция печати строки.
// Для вывода на экран данных узлов необходимо выполнить следующий вызов:
//  Inorder(root, Print);

template <class T>
TreeNode<T> * CopyTree(TreeNode<T> *t);  // создает в динамической памяти копию дерева, корень которого передан ей в качестве параметра.

template <class T>
void DeleteTree(TreeNode<T> * t);  // удаляет из динамической памяти узлы дерева, указатель на корень которого передан ей в качестве параметра.

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

// Функция, реализующая симметричный метод прохождения дерева:
template <class T>
void Inorder(TreeNode<T> *t, void (*visit)(T &item)) {
	// Порядок операций при симметричном методе прохождения бинарного дерева следующий:
	//  1) прохождение левого поддерева;
	//  2) посещение узла;
	//  3) прохождение правого поддерева.
	// Такое прохождение называется LNR-прохождением (left, node, right).
	
	if (t) {  // прохождение завершается на пустом поддереве (t == 0).
		Inorder(t->Left(), visit);  // пройти левое поддерево.
		(*visit)(t->data);  // посетить узел.
		Inorder(t->Right(), visit);  // пройти правое поддерево.
	}
}

// Допустим, у нас имеется дерево, состоящее из узлов, данные которых имеют тип char*, т.е. являются указателями на строки. 
// Корень дерева опреде-ляется  указателем root.  
// Нам необходимо вывести на экран данные дерева, пользуясь симметричным методом прохождения. 
// Функция печати строки в таком случае должна быть примерно следующей:
void Print(char* &item) {
	std::cout << '\n' << item;
}

// Функция CopyTree создает в динамической памяти копию дерева, корень которого передан ей в качестве параметра:
template <class T>
TreeNode<T> * CopyTree(TreeNode<T> *t) {
	if (!t)
		return 0;
	
	// Функция реализует обратный метод прохождения копируемого дерева.
	// Для каждого узла сначала рекурсивным вызовом создаются копии его левого и правого поддеревьев, потом создается сам узел:
	
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

// Функция DeleteTree удаляет из динамической памяти узлы дерева, указатель на корень которого передан ей в качестве параметра:
template <class T>
void DeleteTree(TreeNode<T> * t) {
	if (t) {
		DeleteTree(t->Left());
		DeleteTree(t->Right());
		delete t;
	}
}

#endif

