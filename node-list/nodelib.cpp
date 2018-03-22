#include <iostream>
#include "nodelib.hpp"

using namespace std;

// Конструктор:
template <class T>
Node<T>::Node(const T& item, Node<T> *ptrnext): data(item), next(ptrnext) {
}

// Вставка следующим:
template <class T>
void Node<T>::InsertAfter(Node<T> *p) {
	p->next = next;
	next = p;
}

// Удаление следующего:
template <class T>
Node<T> * Node<T>::DeleteAfter(void) {
	if (next == 0)  // если нет следующего, возвратить NULL:
		return 0;
	
	Node<T> *tempPtr = next;  // сохранить адрес удаляемого узла.
	next = tempPtr->next;  // текущий указывает на узел, следующий за удаляемым.
	
	return tempPtr;  // возвратить указатель на удаляемый узел.
}

// Получение адреса следующего:
template <class T>
Node<T> * Node<T>::NextNode(void) const {
	return next;
}

// Создание связного списка из массива:
template <class T>
Node<T> *BuildNodeList(T M[], int n) {
	Node<T> *head = 0;
	for (int i = n - 1; i >= 0; i--)
		head = new Node<T>(M[i], head);
	return head;  // возвращает указатель на голову списка.
}

// Печать связного списка:
template <class T>
void PrintNodeList(Node<T> * head) {
	if (!head) {
		cout << "\nList empty";
		return;
	}
	cout << '\n';
	while (head) {
		cout << head->data << '\t';
		head = head->NextNode();
	}
}
