#include <iostream>
#include <cstring>
#include <windows.h>  // нужно для функций SetConsoleOutputCP и SetConsoleCP.
#include "Person.h"
#include "Cashbox.h"

using namespace std;

// Переход на кириллицу:
void cyrillic() {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» и там выбираете «Lucida Console». 
}

void echo(const char* str) {
	cout << "\tВы ввели строку: \"" << str << "\" длиной " << strlen(str) << " символов.\n";
}

void inputPersonData(char* const firstName, char* const lastName, char* const patronymic, int& age) {
	// Существует мнемоническое правило, позволяющее легко запомнить, к чему относится const. 
	// Надо провести черту через "*", если const слева, то оно относится к значению данных; если справа — к значению указателя.
	
	cout << "Введите имя: ";
	cin >> firstName;
	echo(firstName);
	
	cout << "Введите фамилию: ";
	cin >> lastName;
	echo(lastName);

	cout << "Введите отчество: ";
	cin >> patronymic;
	echo(patronymic);
	
	cout << "Введите возраст: ";
	cin >> age;
	cout << "Вы ввели число: \"" << age << "\"\n";
}

// Метод main():
int main(int argc, char** argv) {
	cyrillic();
	
	char firstName[STR_LEN];
	char lastName[STR_LEN];
	char patronymic[STR_LEN];
	int age;
	
	// Создать экземпляр класса Person кассир:
	cout << "\t\tВвод информации о кассире:\n";
	inputPersonData(firstName, lastName, patronymic, age);	
	Person* cashier = new Person(firstName, lastName, patronymic, age);
	
	// Вывести информацию о кассире на экран:
	cout << "\n\t\tИнформация о кассире:\n";
	cashier->print();
	cout << endl;
	
	// Создать экземпляр класса касса:
	Cashbox* cashbox = new Cashbox(cashier);

	// Создать экземпляр класса Person клиент:
	cout << "\n\t\tВвод информации о клиенте:\n";
	inputPersonData(firstName, lastName, patronymic, age);	
	Person* client = new Person(firstName, lastName, patronymic, age);
	
	// Установить для класса касса клиента:
	cashbox->setClient(client);
	
	// Вывести информацию о кассе:
	cout << "\n\t\tИнформация о кассе:\n";
	cashbox->print();
	
	// Установить в качестве клиента кассира:
	cout << "\n\n\t\tУстановка в качестве клиента кассира:\n";
	cashbox->setClient(cashier);
	
	delete cashbox;
	delete client;
	delete cashier;
	
	system("pause");
	
	return 0;
}
