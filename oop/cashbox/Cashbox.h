#ifndef CASHBOX_H
#define CASHBOX_H

#include "Person.h"

// ����������� ������ �����:
class Cashbox
{
	public:  // �������� ����:
		// ����������� � 1� ���������� ��������������� �������:
		Cashbox(Person* cashier);
		
		// ����� ��� ��������� �������:
		void setClient(Person* client);
		
		// ����� ��� ������ ���������� � �����:
		void print();
	private:  // �������� ����:
		Person* cashier;  // ������ - ���� ���� Person.
		Person* client;  // ������ - ���� ���� Person.
};

#endif
