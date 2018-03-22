#include <iostream>
#include "queuelib.hpp"

using namespace std;

// Конструктор:
Queue::Queue(void): front(0), rear(0), count(0) {
}

// Вставить элемент в конец очереди:
void Queue::QInsert(const QDataType& item) {
	if (count == MaxQSize) {  // если заполнена, завершить выполнение программы:
		cerr << "Queue full!" << endl;
		exit(1);
	}
	
	// Увеличить count и скопировать item в Qlist:
	count++;
	qlist[rear] = item;
	
	rear = (rear + 1) % MaxQSize;  // значение rear идет по кругу (как часы) от 0 до MaxQSize - 1.
	
	/*
	Пример:
	MaxQSize = 10
	rear = 0
	rear = (0 + 1) % MaxQSize = 1 % 10 = 1
	rear = (1 + 1) % MaxQSize = 2 % 10 = 2
	...
	rear = (9 + 1) % MaxQSize = 10 % 10 = 0
	rear = (0 + 1) % MaxQSize = 1 % 10 = 1
	rear = (1 + 1) % MaxQSize = 2 % 10 = 2
	*/
}

// Извлечь элемент из начала очереди:
QDataType Queue::QDelete(void) {
	QDataType temp;
	if (!count) {  // если пуста, завершить выполнение программы:
		cerr << "Queue empty!" << endl;
		exit(1);
	}
	temp = qlist[front];  // считать значение из начала очереди.
	
	// Уменьшить count и продвинуть начало очереди:
	count--;
	front = (front + 1) % MaxQSize;
	
	return temp;  // вернуть результат.
}

// Очистить очередь:
void Queue::ClearQueue(void) {
	front = 0;
	rear = 0;
	count = 0;
}

// Считать первый элемент без удаления:
QDataType Queue::QFront(void) const {
	if (!count) {  // если пуста, завершить выполнение программы:
		cerr << "Queue empty!" << endl;
		exit(1);
	}
	return qlist[front];  // вернуть результат.
}

// Очередь пуста?
int Queue::QEmpty(void) const {
	return !count;
}

// Очередь полна?
int Queue::QFull(void) const {
	return count == MaxQSize;
}

// Возвратить длину очереди:
int Queue::QLength(void) const {
	return count;
}

