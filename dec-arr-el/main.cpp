#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

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

int main(int argc, char** argv) {
	int i;  // �������. 
	int N;  // ������ ��������� �������.
	float m = 0;  // ���������� ������������� ��������� ����������� �������.
	float avg = 0;  // ������� �������� ������������� ��������� ����������� �������.
	float *pt;  // ��������� ��� ��������� � ��������� �������.
	
	cyrillic();
	
	cout << "������� � ���������� ������ �������: ";
	cin >> N;
	
	float *A = new float[N];  // ��� ������ A[N].
	// �������� �� ��, ��� ����� ������ ����� ����������� ������ �������, ����� ���������� float,
	// ������ ��� �������� ����� ����������� �� ��. �������� ������������� ���������,
	// ������� ����� ���� ������ � ������� ������.
	
	pt = A;
	
	// �������� ������� �����������, ��������� ������� ���������� ��������� ����� ������ ����:
	srand(time(NULL));  // �������������� ������������ ���������� ��������� ����� (����� ������ �������� ������ ��������� �����).
	std::cout << "�������� ������: " << std::endl;
	for (i = 0; i < N; i++ ) {
		*(pt + i) = (rand() % 10);  // ��������� ���������� ������ ����� � ��������� [0; 10).
		
		// ��������� ����� ��� �����:
		if (rand() % 2 == 0) {  // ���������� ��������� ����� ����� � ��������� [0; 1] � ���� ������ 0, �� ������ ���� �� �����:
			*(pt + i) = - *(pt + i);  // ��������� � �������� ������� ������������ � ������� ���������.
		}
		
		cout << "������� �" << i + 1 << " = " << A[i] << endl;  // ��� ������ ��������� ������������ �������.
		
		if (*(pt + i) > 0) {  // ������ ������ 0, ������ ��� 0 �� �������� �� ������������� �� ������������� ������.
			m++;
			avg += *(pt + i);  // ��������� � �������� ������� ������������ � ������� ���������.
		}
	}
	avg /= m;  // ������� �������� ������������� ��������� ����������� �������.
	
	cout << endl << "��. �������� ������������� ��������� ����������� ������� = " << avg << endl << endl;
	
	cout << "���������� ���� ��������� �� ��. �������� ������������� ��������� ����������� �������: " << endl;
	
	// ��������� ����������� �������:
	for (i = 0; i < N; i++) { 
		*(pt + i) -= avg;  // ��������� � �������� ������� ������������ � ������� ���������.
		cout << "������� �" << i + 1 << " = " << A[i] << endl;  // ��� ������ ��������� ������������ �������.
	}
	
	delete [] A;
	
	system("pause");
	return 0;
}

