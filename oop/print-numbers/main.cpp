#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "NumbersOutput.h"
#include "EvenNumbersOutput.h"
#include "OddNumbersOutput.h"
#include "PositiveNumbersOutput.h"
#include "NegativeNumbersOutput.h"

#define MIN_ARRAY_LEN 10
#define MAX_ARRAY_LEN 20
#define MAX_ELEM_VAL 1000

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
	cyrillic();
	
	// �������������� ������������ ���������� ��������� ����� 
	// (����� ������ �������� ������ ��������� �����):
	srand(time(0));

	NumbersOutput* numOut;

	// ��������� ����� ��� ������ �����:
	cout << "��������� ������� ��� ������ ����� ������:\n";
	switch (rand() % 4)  // ��������� ���������� ������ ����� � ��������� [0; 4).
	{
		case 0:
			numOut = new EvenNumbersOutput();
			cout << " ����� ������ ������ �����.";
			break;
		case 1:
			numOut = new OddNumbersOutput();
			cout << " ����� ������ �������� �����.";
			break;
		case 2:
			numOut = new PositiveNumbersOutput();
			cout << " ����� ������ ������������� �����.";
			break;
		default:
			numOut = new NegativeNumbersOutput();
			cout << " ����� ������ ������������� �����.";
			break;
	}
	cout << endl;
	
	// �������� ������� �� N (�� MIN_ARRAY_LEN �� MAX_ARRAY_LEN) 
	// ��������� ������������� � ������������� �����:
	int arrayLength = rand() % (MAX_ARRAY_LEN - MIN_ARRAY_LEN + 1) + MIN_ARRAY_LEN;
	int* array = new int[arrayLength];
	for (int i = 0; i < arrayLength; ++i)
	{
		// ��������� ���������� ������ ����� � ��������� [0; MAX_ELEM_VAL):
		array[i] = rand() % MAX_ELEM_VAL;
		
		// ���������� ��������� ����� ����� � ��������� [0; 1] 
		// � ���� ������ 0, �� ������ ���� �� �����:
		if (rand() % 2 == 0)
		{
			array[i] = -array[i];
		}
	}
	cout << "\n������ ������ �� " << arrayLength 
		<< " ��������� ������������� � ������������� �����\n"
		<< " � ��������� [-" << MAX_ELEM_VAL << "; " << MAX_ELEM_VAL << "].\n";
	
	cout << "\n����� ������� �� �����:\n";
	for (int i = 0; i < arrayLength; ++i)
		cout << array[i] << " ";
	cout << endl;
	
	cout << "\n������ ������� � ����� ������:\n";
	numOut->print(array, arrayLength);
	
	delete numOut;
	delete[] array;

	system("pause");
	return 0;
}
