#include <iostream>
#include <cstring>
#include <windows.h>  // ����� ��� ������� SetConsoleOutputCP � SetConsoleCP.
#include "Person.h"
#include "Cashbox.h"

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

void echo(const char* str) {
	cout << "\t�� ����� ������: \"" << str << "\" ������ " << strlen(str) << " ��������.\n";
}

void inputPersonData(char* const firstName, char* const lastName, char* const patronymic, int& age) {
	// ���������� ������������� �������, ����������� ����� ���������, � ���� ��������� const. 
	// ���� �������� ����� ����� "*", ���� const �����, �� ��� ��������� � �������� ������; ���� ������ � � �������� ���������.
	
	cout << "������� ���: ";
	cin >> firstName;
	echo(firstName);
	
	cout << "������� �������: ";
	cin >> lastName;
	echo(lastName);

	cout << "������� ��������: ";
	cin >> patronymic;
	echo(patronymic);
	
	cout << "������� �������: ";
	cin >> age;
	cout << "�� ����� �����: \"" << age << "\"\n";
}

// ����� main():
int main(int argc, char** argv) {
	cyrillic();
	
	char firstName[STR_LEN];
	char lastName[STR_LEN];
	char patronymic[STR_LEN];
	int age;
	
	// ������� ��������� ������ Person ������:
	cout << "\t\t���� ���������� � �������:\n";
	inputPersonData(firstName, lastName, patronymic, age);	
	Person* cashier = new Person(firstName, lastName, patronymic, age);
	
	// ������� ���������� � ������� �� �����:
	cout << "\n\t\t���������� � �������:\n";
	cashier->print();
	cout << endl;
	
	// ������� ��������� ������ �����:
	Cashbox* cashbox = new Cashbox(cashier);

	// ������� ��������� ������ Person ������:
	cout << "\n\t\t���� ���������� � �������:\n";
	inputPersonData(firstName, lastName, patronymic, age);	
	Person* client = new Person(firstName, lastName, patronymic, age);
	
	// ���������� ��� ������ ����� �������:
	cashbox->setClient(client);
	
	// ������� ���������� � �����:
	cout << "\n\t\t���������� � �����:\n";
	cashbox->print();
	
	// ���������� � �������� ������� �������:
	cout << "\n\n\t\t��������� � �������� ������� �������:\n";
	cashbox->setClient(cashier);
	
	delete cashbox;
	delete client;
	delete cashier;
	
	system("pause");
	
	return 0;
}
