#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "queuelib.hpp"

using namespace std;

// ������� �� ���������:
void cyrillic() {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ � ��� ��������� �Lucida Console�. 
}

// ���������� �����:
void Queue::debugPrint(void) {
	for (int i = 0, j = front; i < count; i++) {
		cout << j << qlist[j++] << " ";
		if (j == MaxQSize) {
			j = 0;
		}
	}
	cout << endl;
}

// �����, ����������� ������� � ������ �������:
void Queue::QInsertFront(const QDataType &item) {
	if (count == MaxQSize) {  // ���� ���������:
		cerr << "Queue full!" << endl;
		exit(1);  // ��������� ���������� ���������.
	
	} else if (this->QEmpty()) {  // ���� ������� �����,
		this->QInsert(item);  // �� ����� ��������������� �������  ������� �������� � ����� �������.
	
	} else {
		count++;  // ��������� count.
		
		front--;
		if (front == -1)
			front = MaxQSize - 1;

		qlist[front] = item;  // ����������� item � Qlist.
	}
}

int main(int argc, char** argv) {
	Queue q;  // �������.
	char cmd;  // �������.
	int el;  // ������� �������.
	
	cyrillic();
	
	cout << "������ �������: " << MaxQSize << endl;
	
	cout << "�������: " << endl;
	cout << "\tf - �������� ��������� ����� � ������;" << endl;
	cout << "\tb - �������� ��������� ����� � �����;" << endl;
	cout << "\td - ������� �� ������." << endl;
	
	srand(time(NULL));  // �������������� ������������ ���������� ��������� ����� (����� ������ �������� ������ ��������� �����).
	
	while (1) {
		cout << "������� �������: ";
		cin >> cmd;
		el = (rand() % 10);  // ��������� ���������� ������ ����� � ��������� [0; 10).
		switch (cmd) {
			case 'f':
				q.QInsertFront(el);
				break;
			case 'b':
				q.QInsert(el);
				break;
			case 'd':
				q.QDelete();
				break;
		}
		q.debugPrint();
	}
	
	system("pause");
	return 0;
}

