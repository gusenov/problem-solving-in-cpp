#ifndef NODE_LIB_HPP
#define NODE_LIB_HPP

template <class T>
class Node {
private:
	Node<T> *next;  // ����� ���������� ����.
public:
	T data;
	
	Node(const T& item, Node<T> *ptrnext = 0);  // �����������.	
	void InsertAfter(Node<T> *p);  // ������� ���������.
	Node<T> *DeleteAfter(void);  // �������� ����������.
	Node<T> *NextNode(void) const;  // ��������� ������ ����������.
};

template <class T>
Node<T> *BuildNodeList(T M[], int n);

template <class T>
void PrintNodeList(Node<T> * head);

#endif

