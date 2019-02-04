#include <iostream>
#include <string>
#include <windows.h>
#include "Pair.h"

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

int main(int argc, char** argv) {
	cyrillic();
	
	cout << "\tПример № 1\n";
	cout << "Создание пары из чисел 115 и 36.\n";
	Pair<int> myInts(115, 36);
	cout << "Максимальное число: " << myInts.getMax() << endl;
	
	cout << "\n\tПример № 2\n";
	cout << "Создание пары из числа 1000 и строки 'string'.\n";
	Pair<int, string> myValues(1000, "string");
	try {
		cout << "Попытка взять максимум…" << endl;
		cout << myValues.getMax() << endl;
	} catch (const char* errorMessage) {
		cout << errorMessage << endl;
	}
	
	system("pause");
	return 0;
}
