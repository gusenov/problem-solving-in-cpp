#include <iostream>
#include "queuelib.hpp"

using namespace std;

// �����������:
Queue::Queue(void): front(0), rear(0), count(0) {
}

// �������� ������� � ����� �������:
void Queue::QInsert(const QDataType& item) {
	if (count == MaxQSize) {  // ���� ���������, ��������� ���������� ���������:
		cerr << "Queue full!" << endl;
		exit(1);
	}
	
	// ��������� count � ����������� item � Qlist:
	count++;
	qlist[rear] = item;
	
	rear = (rear + 1) % MaxQSize;  // �������� rear ���� �� ����� (��� ����) �� 0 �� MaxQSize - 1.
	
	/*
	������:
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

// ������� ������� �� ������ �������:
QDataType Queue::QDelete(void) {
	QDataType temp;
	if (!count) {  // ���� �����, ��������� ���������� ���������:
		cerr << "Queue empty!" << endl;
		exit(1);
	}
	temp = qlist[front];  // ������� �������� �� ������ �������.
	
	// ��������� count � ���������� ������ �������:
	count--;
	front = (front + 1) % MaxQSize;
	
	return temp;  // ������� ���������.
}

// �������� �������:
void Queue::ClearQueue(void) {
	front = 0;
	rear = 0;
	count = 0;
}

// ������� ������ ������� ��� ��������:
QDataType Queue::QFront(void) const {
	if (!count) {  // ���� �����, ��������� ���������� ���������:
		cerr << "Queue empty!" << endl;
		exit(1);
	}
	return qlist[front];  // ������� ���������.
}

// ������� �����?
int Queue::QEmpty(void) const {
	return !count;
}

// ������� �����?
int Queue::QFull(void) const {
	return count == MaxQSize;
}

// ���������� ����� �������:
int Queue::QLength(void) const {
	return count;
}

