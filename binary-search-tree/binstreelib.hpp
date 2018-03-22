#ifndef BIN_S_TREE_HPP
#define BIN_S_TREE_HPP

#include <iostream>
#include "treenodelib.hpp"

// Бинарным деревом поиска (binary search tree) называется бинарное дерево, строящееся по принципу: 
// для каждого узла значение данных в левом поддереве меньше, чем в этом узле, а в правом - больше либо равно.

// Класс бинарного дерева поиска:
template <class T>  // класс BinSTree основан на шаблоне, параметр которого T - тип данных узла.
class BinSTree {

	template <class U>
	friend int NodeLevel(const BinSTree<U> &t, const U& elem);

private:
	
	TreeNode<T> *root;  // указатель на корень дерева.
	TreeNode<T> *current;  // указатель на текущий узел.
	
	int size; // число узлов в дереве.
	
	TreeNode<T> * FindNode(const T& item, TreeNode<T> * &parent) const;  // закрытый метод FindNode осуществляет поиск узла по значению данных.

public:
	
	BinSTree(void);  // конструктор.
	BinSTree(const BinSTree<T> & tree);  // конструктор копирования.
	~BinSTree(void);  // деструктор.
	BinSTree<T>& operator=(const BinSTree<T> & tree);  // перегруженный оператор присваивания.
	int Find(T& item);  // поиск узла.
	void Insert(const T & item);  // вставка данных в дерево.
	void Delete(const T & item);  // удаление данных из дерева.
	void ClearTree(void);  // очистка дерева.
	int TreeEmpty(void) const;  // дерево пусто?
	int TreeSize(void) const;  // размер дерева.
	void Update(const T & item);  // обновить дерево.
	
	void Print(void (*visit)(T &item));
	
};

// Конструктор:
template <class T>
BinSTree<T>::BinSTree(void): root(0), current(0), size(0) {
}

// Так как класс BinSTree содержит указатель на динамические данные, он должен иметь конструктор копирования:
template <class T>
BinSTree<T>::BinSTree(const BinSTree<T> & tree) {
	root = CopyTree(tree.root);  // конструктор вызывает внешнюю функцию CopyTree для создания копии дерева в динамической памяти.
	current = root;
	size = tree.size;
}

// Деструктор:
template <class T>
BinSTree<T>::~BinSTree(void) {
	DeleteTree(root);
}

// Перегруженный оператор присваивания работает аналогично конструктору копирования, 
// за исключением того, что перед созданием копии дерева он удаляет "старое" дерево вызовом DeleteTree:
template <class T>
BinSTree<T>& BinSTree<T>::operator=(const BinSTree<T> & tree) {
   DeleteTree(root);
   root = CopyTree(tree.root);
   current = root;
   size = tree.size;
   return *this;  // возвращает ссылку на объект - левый операнд операции присваивания, что позволяет осуществить каскадный вызов операции.
}

// Метод Find осуществляет поиск данных в дереве по ключу:
// (ключ должен входить в состав полей параметра item, передаваемого функции Find по ссылке)
template <class T>
int BinSTree<T>::Find(T& item) {
	TreeNode<T> *parent;
	current = FindNode(item,parent);  // для поиска узла метод использует закрытую функцию FindNode.
	if (current) {  // если поиск увенчался успехом,
		item = current->data;  // item будет содержать "полные" данные узла, найденного по этому ключу
		return 1;  // и функция Find возвращает 1.
	}
	else
		return 0;
}

// Закрытый метод FindNode осуществляет поиск узла по значению данных:
template <class T>
TreeNode<T> * BinSTree<T>::FindNode(const T& item, TreeNode<T> * &parent) const {
	TreeNode<T> *t = root;
	parent = 0;
	
	while (t) {
		// Поиск элемента в дереве осуществляется с применением операции "==" для сравнения данных узла с параметром item.
		// Предполагается, что эта операция определена для типа T. 
		// В случае, если T  - структурный тип, оператор "==" должен быть перегружен для данного типа.
		// При этом может быть организовано сравнение структур по ключу и функция FindNode будет искать данные по ключу.
		if (item == t->data)
			break;
		else {
			
			parent = t;  // через параметр  parent, переданный по ссылке, возвращается указатель на родителя этого узла.
			// Указатель на родителя может потребоваться, например, при удалении найденного узла для восстановления структуры дерева.
			
			if (item < t->data)
				t = t->left;
			else
				t = t->right;
		}
	}
	
	return t;  // возвращаемым значением является указатель на  найденный узел.
}

// Метод Insert принимает в качестве параметра новый элемент данных и вставляет его в подходящее место на дереве:
template <class T>
void BinSTree<T>::Insert(const T & item) {
	TreeNode<T> *t = root,  // t - текущий узел.
				*parent = 0,  // parent - предыдущий.
				*newNode = new TreeNode<T>(item);  // //newNode - вставляемый.
	
	// Функция итеративно проходит путь по дереву, пока не найдет точку вставки:
	while (t) {  // остановиться на пустом дереве.
		parent = t;  // обновить указатель parent.
		
		// И идти направо или налево в зависимости от значения данных:
		if (item < t->data)
			t = t->left;
		else
			t = t->right;
	}
	
	// В этот момент становится известным родитель вставляемого узла.
	// Далее функция определяет, каким сыном - левым или правым - будет вставляемый узел и присоединяет его к родителю.
	
	if (!parent)  // если дерево пусто:
		root = newNode;  // вставить в качестве корня.
	
	else if (item < parent->data)  // если item меньше данных родителя:
		parent ->left = newNode;  // вставить левым сыном.
	else  
		parent->right = newNode;  // вставить правым сыном.
	
	current = newNode;  // сделать новый узел текущим.
	size++;  // и увеличить size.
}

// Операция Delete удаляет из дерева узел с заданным ключом:
// (ключ является одним из полей параметра item)
template <class T>
void BinSTree<T>::Delete(const T & item) {
	TreeNode<T> *DNodePtr,  // указатель на удаляемый узел D.
				*PNodePtr,  // указатель на родителя P удаляемого узла D.
				*RNodePtr;  // указатель на замещающий узел R.
	
	// Сначала с помощью метода FindNode устанавливается место этого узла на дереве и определяется указатель на его родителя.
	// Найти узел, данные которого совпадают с item.
	// Получить его адрес и адрес его родителя.
	DNodePtr = FindNode(item, PNodePtr);

	// Если искомый узел отсутствует, операция завершается:	
	if (!DNodePtr)  // если такой узел не найден:
		return;  // выйти из функции.
	
	
	// Удаление узла требует ряда проверок, чтобы определить, куда присоединить сыновей удаляемого узла. 
	// Поддеревья должны быть присоединены таким образом, чтобы сохранилась структура бинарного дерева поиска.
	
	// При удалении узла возможны четыре ситуации:
	
	
	// Если D имеет NULL-указатель, заменяющим узлом является тот, что находится на другой ветви:
	// № 2 - удаляемый узел D имеет левого сына, но не имеет правого:
	if (!DNodePtr->right)
		RNodePtr = DNodePtr->left;  // необходимо присоединить его левое поддерево к родителю.
		// (иными словами, заменяющим узлом R будет левый сын удаляемого)
	// № 3 - удаляемый узел имеет правого сына, но не имеет левого:
	else if (!DNodePtr->left)
		RNodePtr = DNodePtr->right;  // необходимо присоединить его правое поддерево к родителю.
		// (ситуация аналогична предыдущей, за исключением того, что замещающим узлом будет правый сын удаляемого)
	
	
	// № 4 - удаляемый узел имеет обоих сыновей:
	else {  // узел D имеет двух сыновей:
		
		TreeNode<T> * PofRNodePtr = DNodePtr;  // указатель на родителя PR узла R.
		RNodePtr = DNodePtr->left;  // переходим в левое поддерево узла D.
		
		while (RNodePtr->right) {  // спускаемся "вправо", пока не найдем замену:
			PofRNodePtr = RNodePtr;
			RNodePtr = RNodePtr->right;
		}
		
		if (PofRNodePtr == DNodePtr)  // левый сын узла D является заменяющим:
			RNodePtr->right = DNodePtr->right;  // присоединить правое поддерево узла D к R.
		else {
			PofRNodePtr->right = RNodePtr->left;  // присоединить левое поддерево узла R к его родителю.
			
			// Связать узел R с сыновьями D:
			RNodePtr->left =  DNodePtr->left;
			RNodePtr->right =  DNodePtr->right;
		}
	}
	
	// Осталось присоединить узел R к узлу P:
	
	if (!PNodePtr)  // у узла D нет родителя - он являлся корнем:
		root = RNodePtr;  // назначить новый корень - узел R.
	
	// С какой стороны присоединить узел R к узлу P?
	else if (DNodePtr->data < PNodePtr->data)  // слева:
		PNodePtr->left = RNodePtr;
	else  // справа:
		PNodePtr->right = RNodePtr;
	
	
	// После удаления узла D из дерева и его замены функция Delete уничтожает этот узел и уменьшает на единицу переменную size:
	delete DNodePtr;  // удалить узел D из памяти.
	size--;  // уменьшить размер дерева.
}

// Очистка дерева:
template <class T>
void BinSTree<T>::ClearTree(void) {
	DeleteTree(root); 
	root = current = 0;
	size=0;
}

// Дерево пусто?
template <class T>
int BinSTree<T>::TreeEmpty(void) const {
	return !size;
}

// Размер дерева:
template <class T>
int BinSTree<T>::TreeSize(void) const {
	return size;
}

// Метод Update служит для обновления текущего узла и вставки новых данных:
template <class T>
void BinSTree<T>::Update(const T& item) {
	// Он принимает в качестве параметра ссылку на элемент данных и, если определен текущий узел, сравнивает его значение с этим элементом.
	
	if (current && current->data == item)  // если они равны, производится обновление узла:
		// Напомним, что сравнение новых данных со значением текущего узла производится не по всем полям типа T, 
		// а только по ключевому полю, остальные поля могут отличаться и в результате обновления примут новые значения.
		current->data = item;
		
	else  // в противном случае, а также если текущий узел не определен, новые данные включаются  в  дерево  вызовом Insert:
		Insert(item);
}

template <class T>
void BinSTree<T>::Print(void (*visit)(T &item)) {
	Inorder(root, visit);
}

#endif
