// InsertStringAtPosition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>  // строковый тип.
#include <iostream>  // ввод/вывод.
#include <windows.h>  // нужно для функций SetConsoleOutputCP и SetConsoleCP.


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

// Главная функция:
int main()
{
	cyrillic(); // вкл. кириллицу.

	string S;  // строка S.
	cout << "Введите строку S -> ";
	getline(cin, S);

	string subStr;  // подстрока.
	cout << "Введите подстроку -> ";
	getline(cin, subStr);
	size_t L = subStr.length();  // длина подстроки.

	size_t N;  // позиция N.
	cout << "Введите позицию N, учитывая, что отсчёт индекса начинается с нуля -> ";
	cin >> N;

	S = S.substr(0, N)  // всё, что до подстроки.
		+ subStr  // подстрока.
		+ S.substr(N, S.length() - N);  // всё, что после подстроки.

	cout << "Результирующая строка: " << endl << S;


	// Пауза перед выходом из программы 
	// (программа ждёт ввода любого символа): 
	cin.get();
	cin.get();
	
	// Возврат нуля, 
	// что означает успешное завершение программы: 
	return 0;
}

