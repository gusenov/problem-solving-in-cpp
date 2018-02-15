#ifndef QUEUE_LIB_HPP
#define QUEUE_LIB_HPP

const int MaxQSize = 10;  // ����. ������ �������.
typedef int QDataType;  // �������� ������� ����� ��� int.

class Queue {
private:
	QDataType qlist[MaxQSize];  // ������ �������.
	int front;  // ������ ������� ��������.
	int rear;  // ������ ����� �������.
	int count;  // ����� ���������� ���������.
public:
	Queue(void);  // �����������.
	void QInsert(const QDataType& item);  // �������� ������� � ����� �������.
	QDataType QDelete(void);  // ������� ������� �� ������ �������.
	void ClearQueue(void);  // �������� �������.
	QDataType QFront(void) const;  // ������� ������ ������� ��� ��������.
	int QEmpty(void) const;  // ������� �����?
	int QFull(void) const;  // ������� �����?
	int QLength(void) const;  // ���������� ����� �������.
	void QInsertFront(const QDataType &item);  // �����, ����������� ������� � ������ �������.
	
	void debugPrint(void);  // ���������� �����.
};

#endif

