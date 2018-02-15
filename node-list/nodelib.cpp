#include <iostream>
#include "nodelib.hpp"

using namespace std;

// �����������:
template <class T>
Node<T>::Node(const T& item, Node<T> *ptrnext): data(item), next(ptrnext) {
}

// ������� ���������:
template <class T>
void Node<T>::InsertAfter(Node<T> *p) {
	p->next = next;
	next = p;
}

// �������� ����������:
template <class T>
Node<T> * Node<T>::DeleteAfter(void) {
	if (next == 0)  // ���� ��� ����������, ���������� NULL:
		return 0;
	
	Node<T> *tempPtr = next;  // ��������� ����� ���������� ����.
	next = tempPtr->next;  // ������� ��������� �� ����, ��������� �� ���������.
	
	return tempPtr;  // ���������� ��������� �� ��������� ����.
}

// ��������� ������ ����������:
template <class T>
Node<T> * Node<T>::NextNode(void) const {
	return next;
}

// �������� �������� ������ �� �������:
template <class T>
Node<T> *BuildNodeList(T M[], int n) {
	Node<T> *head = 0;
	for (int i = n - 1; i >= 0; i--)
		head = new Node<T>(M[i], head);
	return head;  // ���������� ��������� �� ������ ������.
}

// ������ �������� ������:
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
