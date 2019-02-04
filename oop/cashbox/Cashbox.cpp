#include "Cashbox.h"
#include <iostream>
#include <cstring>

using namespace std;

// ����������� � 1� ���������� ��������������� �������:
Cashbox::Cashbox(Person* cashier)
{
	this->cashier = cashier;
}

// ����� ��� ��������� �������:
void Cashbox::setClient(Person* client)
{
	// ��������� ����� ������������ ��� ������ ������ strcmp ��� strncmp:
	bool isLastNameEquals = strcmp(client->getLastName(), this->cashier->getLastName()) == 0;
	bool isFirstNameEquals = strcmp(client->getFirstName(), this->cashier->getFirstName()) == 0;
	bool isPatronymicEquals = strncmp(client->getPatronymic(), this->cashier->getPatronymic(), STR_LEN) == 0;
	
	// ���� ��� ������� ��������� � ��� �������, ��������� ��������������:
	if ( isLastNameEquals && isFirstNameEquals && isPatronymicEquals )
	{
		cout << "��������������: ��� ������� ��������� � ��� �������!" << endl;
	}
	
	this->client = client;
}

// ����� ��� ������ ���������� � �����:
void Cashbox::print()
{
	cout << "��� �������: ";
	this->cashier->print();
	
	cout << endl;
	
	cout << "��� �������� �������: ";
	this->client->print();
}

