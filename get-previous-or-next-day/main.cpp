// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <iostream>  // ввод/вывод.
#include <windows.h>  // нужно для функций SetConsoleOutputCP и SetConsoleCP.

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

// Использование пространства имён
// стандартной библиотеки:
using namespace std;

// Количество дней в месяцах:
const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Дата некоторого дня характеризуется тремя натуральными числами:
struct Date {
	int g;  // год.
	int m;  // порядковый номер месяца.
	int n;  // число.
};

// Функция определяющая, является ли год високосным?
bool isLeapYear(int year) {	
	if (year % 400 == 0)
		return true;
	
	if (year % 100 == 0)
		return false;
	
	return year % 4 == 0;
}

// Функция для получения следующего дня:
Date nextDay(Date date) {
	date.n++;
	if (date.n > daysPerMonth[date.m - 1] || (date.m == 2 && date.n == 29 && !isLeapYear(date.g))) {
	    date.n = 1;
	    date.m++;
	    if (date.m == 13) {
	        date.m = 1;
	        date.g++;
	    }
	}
	return date;
}

// Функция для получения предыдущего дня:
Date prevDay(Date date) {
	date.n--;
	if (date.n == 0) {
		date.m--;
	    if (date.m == 0) {
	        date.m = 12;
	        date.g--;
	    }
	    if (date.m == 2 && isLeapYear(date.g))
	    	date.n = 29;
	    else
	    	date.n = daysPerMonth[date.m - 1];
	}
	return date;
}

int main() {
	cyrillic();  // вкл. кириллицу.
	
	Date myDate;
	
	cout << "Введите год -> ";
	cin >> myDate.g;
	
	cout << "Введите месяц -> ";
	cin >> myDate.m;
	
	cout << "Введите день -> ";
	cin >> myDate.n;
	
	Date prevDate = prevDay(myDate);
	cout << "Дата предыдущего дня = " << prevDate.n << "." << prevDate.m << "." << prevDate.g << " г." << endl;
	
	Date nextDate = nextDay(myDate);
	cout << "Дата следующего дня = " << nextDate.n << "." << nextDate.m << "." << nextDate.g << " г." << endl;
	
	// Пауза перед выходом из программы 
	// (программа ждёт ввода любого символа): 
	cin.get();
	cin.get();

	// Возврат нуля, 
	// что означает успешное завершение программы: 
	return 0;
}
