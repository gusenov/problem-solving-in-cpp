// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <string>  // строковый тип.
#include <iostream>  // ввод/вывод.

// Использование пространства имён
// стандартной библиотеки:
using namespace std;

// Главная функция:
int main() {
	// Даны строки S и S0:
	string S, S0;
	
	// Ввод строки S:
	getline(cin, S);
	
	// Ввод строки S0:
	getline(cin, S0);
	
	bool isFound = false;
	
	for (int i = S.length() - S0.length(); i >= 0; i--) {
		
		// Проверка равенства подстроки из S строке S0:
		bool isEquals = true;
		for (int j = 0; j < S0.length(); j++) {
			// Если подстрока из S не равна строке S0:
			if (S.at(i + j) != S0.at(j)) {
				isEquals = false;
				break; // выход из цикла по j.
			}
		}
		
		// Если подстрока из S равна S0, то:
		if (isEquals) {
			isFound = true;
			
			// Вывод всех символов из строки S:
			
			// до последней подстроки, совпадающей с S0:
			for (int j = 0; j < i; j++)
				cout << S.at(j);
			
			// после последней подстроки, совпадающей с S0:
			for (int j = i + S0.length(); j < S.length(); j++)
				cout << S.at(j);
			
			break;  // выход из цикла по i.
		}
	}
	
	if (!isFound)
		cout << S;
	
	// Пауза перед выходом из программы
	// (программа ждёт ввода любого символа):
	getchar();
	
	// Возврат нуля, 
	// что означает успешное завершение программы:
	return 0;
}

