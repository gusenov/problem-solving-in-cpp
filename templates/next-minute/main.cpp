#include <iostream>
#include <cstdlib>
#include "nextminute.h"
#include <windows.h>

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
	
	time t;
	int ihours, iminutes, iseconds;
	double dhours, dminutes, dseconds;
	int choice;
	
	cout << "Меню:\n"
		 << "\t1) Ввести структуру «время» (часы, минуты, секунды).\n"
		 << "\t2) Ввести 3 целочисленных параметра: часы, минуты, секунды.\n"
		 << "\t3) Ввести 2 целочисленных параметра: часы, минуты.\n"
		 << "\t4) Ввести 3 параметра с плавающей точкой: часы, минуты, секунды.\n"
		 << "\t5) Ввести 2 параметра с плавающей точкой: часы, минуты.\n"
		 << "\t6) Выход.\n";
	
	do {
		
		cout << "Введите пункт меню>";
		cin >> choice;
		
		if (choice == 6)
			break;

		switch (choice) {
			case 1:
				cout << "Введите через пробел часы, минуты, секунды>";
				cin >> t.hours >> t.minutes >> t.seconds;
				cout << "Следующая минута:\n";
				t = nextMinute(t);
				printTime(t);
				break;
			
			case 2:
				cout << "Введите через пробел часы, минуты, секунды>";
				cin >> ihours >> iminutes >> iseconds;
				cout << "Следующая минута:\n";
				t = nextMinute(ihours, iminutes, iseconds);
				printTime(t.hours, t.minutes, t.seconds);
				break;
			case 3:
				cout << "Введите через пробел часы, минуты>";
				cin >> ihours >> iminutes;
				cout << "Следующая минута:\n";
				t = nextMinute(ihours, iminutes);
				printTime(t.hours, t.minutes);
				break;
				
			case 4:
				cout << "Введите через пробел часы, минуты, секунды>";
				cin >> dhours >> dminutes >> dseconds;
				cout << "Следующая минута:\n";
				t = nextMinute(dhours, dminutes, dseconds);
				printTime(t.hours, t.minutes, t.seconds);
				break;
			case 5:
				cout << "Введите через пробел часы, минуты>";
				cin >> dhours >> dminutes;
				cout << "Следующая минута:\n";
				t = nextMinute(dhours, dminutes);
				printTime(t.hours, t.minutes);
				break;
		}
		
		cout << endl;
	
	} while (1);
	
	system("pause");
	return EXIT_SUCCESS;
}

