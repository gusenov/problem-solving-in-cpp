#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <windows.h>
#include "BitovayaStroka.h"

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

void testy(void)
{
	// Тест конструктора по нуль-терминированной инициализирующей строке:
	Stroka str1("STROKA");
	// Все строковые литералы имеют нуль-символ в конце.
	
	assert(str1.dlina_stroki() == 6);

	// Тест конструктора копирования:
	Stroka str2 = Stroka(str1);
	assert(str2.dlina_stroki() == 6);
	
	// Тест конструктора по размеру:
	Stroka str3(6);

	// Тест оператора присваивания:	
	str1 = "TEST";
	assert(str1.dlina_stroki() == 4);
	str2 = str1;
	assert(str2.dlina_stroki() == 4);
	
	// Тест операции конкатенации двух строк:
	str1 = "DVE ";
	str2 = "STROKI";
	str3 = str1 + str2;
	assert(str3.dlina_stroki() == 10);
	
	// Тесты на сравнение строк:
	str1 = "AAA";
	str2 = "AAA";
	assert(str1 == str2);
	str2 = "BBB";
	assert(str1 != str2);
	assert(str1 < str2);
	assert(str2 > str1);
	
	// Тесты БИТОВОЙ_СТРОКИ:
	
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
	cout << "\tПобитовое ИЛИ для двух строк\n";
	cout << "---------------------------------------------------------------------\n\n";
	
	int buffer;
	do {
		cout << "Введите макс. длину входных битовых строк >";
		cin >> buffer;
	} while (buffer <= 0);
	
	BitovayaStroka bit1(buffer);
	cout << "\nВведите первую битовую строку>";
	cin >> bit1;
	cout << "Вы ввели первую битовую строку: " << bit1 << endl;
	
	BitovayaStroka bit2(buffer);
	cout << "\nВведите вторую битовую строку>";
	cin >> bit2;
	cout << "Вы ввели вторую битовую строку: " << bit2 << endl;
	
	BitovayaStroka bit = bit1 | bit2;
	cout << "\nРезультат операции побитовое ИЛИ: " << bit << endl;
	
	cout << "\nПроверка:\n";
	cout << setw(buffer) << bit1 << endl;
	cout << setw(buffer) << bit2 << endl;
	cout << setw(buffer) << bit << endl;
	
	system("pause");
}

int main(int argc, char** argv)
{
	testy();  // набор тестов.
	primer();  // пример использования.
	return EXIT_SUCCESS;
}
