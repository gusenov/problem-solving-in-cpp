#include <iostream>
#include <string>
#include <windows.h>
#include "Pair.h"

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
	
	cout << "\t������ � 1\n";
	cout << "�������� ���� �� ����� 115 � 36.\n";
	Pair<int> myInts(115, 36);
	cout << "������������ �����: " << myInts.getMax() << endl;
	
	cout << "\n\t������ � 2\n";
	cout << "�������� ���� �� ����� 1000 � ������ 'string'.\n";
	Pair<int, string> myValues(1000, "string");
	try {
		cout << "������� ����� ��������" << endl;
		cout << myValues.getMax() << endl;
	} catch (const char* errorMessage) {
		cout << errorMessage << endl;
	}
	
	system("pause");
	return 0;
}
