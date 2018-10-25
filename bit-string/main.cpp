#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <windows.h>
#include "BitovayaStroka.h"

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

void testy(void)
{
	// ���� ������������ �� ����-��������������� ���������������� ������:
	Stroka str1("STROKA");
	// ��� ��������� �������� ����� ����-������ � �����.
	
	assert(str1.dlina_stroki() == 6);

	// ���� ������������ �����������:
	Stroka str2 = Stroka(str1);
	assert(str2.dlina_stroki() == 6);
	
	// ���� ������������ �� �������:
	Stroka str3(6);

	// ���� ��������� ������������:	
	str1 = "TEST";
	assert(str1.dlina_stroki() == 4);
	str2 = str1;
	assert(str2.dlina_stroki() == 4);
	
	// ���� �������� ������������ ���� �����:
	str1 = "DVE ";
	str2 = "STROKI";
	str3 = str1 + str2;
	assert(str3.dlina_stroki() == 10);
	
	// ����� �� ��������� �����:
	str1 = "AAA";
	str2 = "AAA";
	assert(str1 == str2);
	str2 = "BBB";
	assert(str1 != str2);
	assert(str1 < str2);
	assert(str2 > str1);
	
	// ����� �������_������:
	
	BitovayaStroka bit1("1011");
	assert(bit1.dlina_stroki() == 4);
	
	BitovayaStroka bit2("1110");
	assert(bit2.dlina_stroki() == 4);

	BitovayaStroka bit3 = bit1 | bit2;
	assert(bit3.dlina_stroki() == 4);
	assert(bit3 == Stroka("1111"));
}

void primer()
{
	cyrillic();
	
	cout << "---------------------------------------------------------------------\n";
	cout << "\t��������� ��� ��� ���� �����\n";
	cout << "---------------------------------------------------------------------\n\n";
	
	int buffer;
	do {
		cout << "������� ����. ����� ������� ������� ����� >";
		cin >> buffer;
	} while (buffer <= 0);
	
	BitovayaStroka bit1(buffer);
	cout << "\n������� ������ ������� ������>";
	cin >> bit1;
	cout << "�� ����� ������ ������� ������: " << bit1 << endl;
	
	BitovayaStroka bit2(buffer);
	cout << "\n������� ������ ������� ������>";
	cin >> bit2;
	cout << "�� ����� ������ ������� ������: " << bit2 << endl;
	
	BitovayaStroka bit = bit1 | bit2;
	cout << "\n��������� �������� ��������� ���: " << bit << endl;
	
	cout << "\n��������:\n";
	cout << setw(buffer) << bit1 << endl;
	cout << setw(buffer) << bit2 << endl;
	cout << setw(buffer) << bit << endl;
	
	system("pause");
}

int main(int argc, char** argv)
{
	testy();  // ����� ������.
	primer();  // ������ �������������.
	return EXIT_SUCCESS;
}
