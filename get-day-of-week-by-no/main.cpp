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

enum week { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thur = 4, Fri = 5, Sat = 6 };

int main() {
	cyrillic();  // вкл. кириллицу.
	
	int k;
	cout << "Введите целое число k (1 <= k <= 365) -> ";
	cin >> k;
	if (k < 1 || k > 365) {
		cout << "Ошибка! k должно быть больше/равно 1 и меньше/равно 365." << endl;
	}
		
	int d;
	cout << "Введите целое число d (1 <= d <= 7) -> ";
	cin >> d;
	if (d < 1 || d > 7) {
		cout << "Ошибка! d должно быть больше/равно 1 и меньше/равно 7." << endl;
	}
	
	cout << "1 января - ";
	switch (d % 7) {
		case Mon:
			cout << "понедельник";
			break;
		case Tue:
			cout << "вторник";
			break;
		case Wed:
			cout << "среда";
			break;
		case Thur:
			cout << "четверг";
			break;
		case Fri:
			cout << "пятница";
			break;
		case Sat:
			cout << "суббота";
			break;
		case Sun:
			cout << "воскресенье";
			break;
	}
	cout << endl;
	
	cout << k << "-й день года - ";

	switch (  ( (k % 7) + (d - 1) ) % 7  ) {
		case Mon:
			cout << "понедельник (рабочий день)";
			break;
		case Tue:
			cout << "вторник (рабочий день)";
			break;
		case Wed:
			cout << "среда (рабочий день)";
			break;
		case Thur:
			cout << "четверг (рабочий день)";
			break;
		case Fri:
			cout << "пятница (рабочий день)";
			break;
		case Sat:
			cout << "суббота";
			break;
		case Sun:
			cout << "воскресенье";
			break;
	}
	cout << endl;
	
	// Пауза перед выходом из программы 
	// (программа ждёт ввода любого символа): 
	cin.get();
	cin.get();

	// Возврат нуля, 
	// что означает успешное завершение программы: 
	return 0;
}
