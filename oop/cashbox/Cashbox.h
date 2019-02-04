#ifndef CASHBOX_H
#define CASHBOX_H

#include "Person.h"

// Определение класса Касса:
class Cashbox
{
	public:  // открытые поля:
		// Конструктор с 1м параметрам устанавливающим кассира:
		Cashbox(Person* cashier);
		
		// Метод для установки клиента:
		void setClient(Person* client);
		
		// Метод для вывода информации о кассе:
		void print();
	private:  // закрытые поля:
		Person* cashier;  // кассир - поле типа Person.
		Person* client;  // клиент - поле типа Person.
};

#endif
