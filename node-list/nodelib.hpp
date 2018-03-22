#ifndef NODE_LIB_HPP
#define NODE_LIB_HPP

template <class T>
class Node {
private:
	Node<T> *next;  // адрес следующего узла.
public:
	T data;
	
	Node(const T& item, Node<T> *ptrnext = 0);  // конструктор.	
	void InsertAfter(Node<T> *p);  // вставка следующим.
	Node<T> *DeleteAfter(void);  // удаление следующего.
	Node<T> *NextNode(void) const;  // получение адреса следующего.
};

template <class T>
Node<T> *BuildNodeList(T M[], int n);

template <class T>
void PrintNodeList(Node<T> * head);

#endif

