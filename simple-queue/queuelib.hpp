#ifndef QUEUE_LIB_HPP
#define QUEUE_LIB_HPP

const int MaxQSize = 10;  // макс. размер очереди.
typedef int QDataType;  // элементы очереди имеют тип int.

class Queue {
private:
	QDataType qlist[MaxQSize];  // массив очереди.
	int front;  // индекс первого элемента.
	int rear;  // индекс места вставки.
	int count;  // общее количество элементов.
public:
	Queue(void);  // конструктор.
	void QInsert(const QDataType& item);  // вставить элемент в конец очереди.
	QDataType QDelete(void);  // извлечь элемент из начала очереди.
	void ClearQueue(void);  // очистить очередь.
	QDataType QFront(void) const;  // считать первый элемент без удаления.
	int QEmpty(void) const;  // очередь пуста?
	int QFull(void) const;  // очередь полна?
	int QLength(void) const;  // возвратить длину очереди.
	void QInsertFront(const QDataType &item);  // метод, вставляющий элемент в начало очереди.
	
	void debugPrint(void);  // отладочный вывод.
};

#endif

