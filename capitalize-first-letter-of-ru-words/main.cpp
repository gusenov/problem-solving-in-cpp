// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <string>  // строковый тип.
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

int main() {
	cyrillic();  // вкл. кириллицу.
	
	string ruSentence;
	// Ввод предложения на русском языке:
	getline(cin, ruSentence);
	
	for (int index = 0; index < ruSentence.length(); index++) {
		// Если символ является начальным ИЛИ
		// перед символом стоит пробел, то:
		if (index == 0 || ruSentence.at(index - 1) == ' ') {
			// считаем, что этот символ является началом слова.
			
			// Если первый символ слова находится в диапазоне от 'а' до 'я', то:
			if (ruSentence.at(index) >= 'а' && ruSentence.at(index) <= 'я') {
				
				// Вычисляем индекс буквы по порядку
				// (а - 0, б - 1, в - 2, …, я - 31):
				int letterIndex = ruSentence.at(index) - 'а';
				
				// Прибавляем индекс буквы к заглавной 'А', 
				// чтобы получить нужную заглавную букву:
				ruSentence.at(index) = 'А' + letterIndex;
			}
		}
	}
	
	// Вывод преобразованной строки:
	cout << ruSentence;
	
	// Пауза перед выходом из программы
	// (программа ждёт ввода любого символа):
	getchar();

	// Возврат нуля,
	// что означает успешное завершение программы:
	return 0;
}

