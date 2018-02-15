#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "nodelib.hpp"
#include "nodelib.cpp"  // ����� ����� ���������������� ��������� ����� � .cpp �����.

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

// ������� ���������� ������� ���������� ����� � ������� ������ �� �������� (�� ����� � ������):
template <class T>
void reverse(Node<T> * &head) {
	if (!head) {  // ���� ������ ����:
		cout << "������ ����!" << endl;
		return;
	}

	if (!head->NextNode()) {  // ���� � ������ ���� �������,
		return;  // �� �������� ������� �� ����� ������.
	}

	Node<T> *reverseHead = 0;  // ������ ������, ������� ����� � �������� �������.
	Node<T> *newLast = 0;  // ��������� �� ��������� ���� � ������ � �������� ��������.
	while (head->NextNode()) {  // ������������ ������ � �������� ��������:
	
		// ���������� �� ��������� ���� ����� ������:
		Node<T> *penult = 0;
		Node<T> *last = head;
		while (last->NextNode()) {
			penult = last;
			last = last->NextNode();
		}  // �� ���������� �����, penult - ����� ������������� ����, � last ����� ��������� ���� � ������.

		penult->DeleteAfter();  // ������� ��������� ����, �.�. �� ����� ����������� � ���������� ������ � �������� �������.
		
		if (!reverseHead) {  // ���� ������ ������ � �������� ������� ��� �� ���������, �� ���������:
			reverseHead = newLast = last;
		} else {  // ���� ������ ��� ����, �� ��������� ��������� ����� ����, ����� ���������� ���� � ������ � �������� ��������:
			newLast->InsertAfter(last);
			newLast = last;
		}
	}
	newLast->InsertAfter(head);  // ��������� � ������ � �������� �������� ��������� ����, ������� ������ ��� ������� ��������� ������.
	head = reverseHead;  // ������ ������ ������.
}

void test1(void) {
	int M[] = { 1, 2, 3, 4, 5 };
	Node<int> *head = BuildNodeList(M, 5);	
	
	cyrillic();
	
	cout << "�������� �������: " << endl;
	PrintNodeList(head);
	
	reverse(head);
	
	cout << endl << endl << "�������� �������: " << endl;
	PrintNodeList(head);
	cout << endl;	
}

void test2(void) {
	int i, N;
	int *M;
	
	cout << "������� � ���������� ������ �������: ";
	cin >> N;
	M = new int[N];
	srand(time(NULL));  // �������������� ������������ ���������� ��������� ����� (����� ������ �������� ������ ��������� �����).
	for (i = 0; i < N; i++ ) {
		M[i] = rand() % 10;  // ��������� ���������� ������ ����� � ��������� [0; 10).
	}
	
	Node<int> *head = BuildNodeList(M, N);	
	
	cout << "�������� �������: " << endl;
	PrintNodeList(head);
	
	reverse(head);
	
	cout << endl << endl << "�������� �������: " << endl;
	PrintNodeList(head);
	cout << endl;	
	
	delete [] M;
}

int main(int argc, char** argv) {
	cyrillic();
	
	cout << "���� � 1 (�������������)" << endl;
	test1();
	
	cout << endl << endl << "���� � 2 (���������)" << endl;
	test2();
	
	system("pause");
	return 0;
}

