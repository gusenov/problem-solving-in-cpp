#include "Cashbox.h"
#include <iostream>
#include <cstring>

using namespace std;

// Конструктор с 1м параметрам устанавливающим кассира:
Cashbox::Cashbox(Person* cashier)
{
	this->cashier = cashier;
}

// Метод для установки клиента:
void Cashbox::setClient(Person* client)
{
	// Сравнение строк производится при помощи метода strcmp или strncmp:
	bool isLastNameEquals = strcmp(client->getLastName(), this->cashier->getLastName()) == 0;
	bool isFirstNameEquals = strcmp(client->getFirstName(), this->cashier->getFirstName()) == 0;
	bool isPatronymicEquals = strncmp(client->getPatronymic(), this->cashier->getPatronymic(), STR_LEN) == 0;
	
	// Если ФИО клиента совпадает с ФИО кассира, выводится предупреждение:
	if ( isLastNameEquals && isFirstNameEquals && isPatronymicEquals )
	{
		cout << "ПРЕДУПРЕЖДЕНИЕ: ФИО клиента совпадает с ФИО кассира!" << endl;
	}
	
	this->client = client;
}

// Метод для вывода информации о кассе:
void Cashbox::print()
{
	cout << "ФИО кассира: ";
	this->cashier->print();
	
	cout << endl;
	
	cout << "ФИО текущего клиента: ";
	this->client->print();
}

