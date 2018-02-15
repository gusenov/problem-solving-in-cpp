#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <windows.h>

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

// Функция вычисляющая значение вещественного типа (float), 
// соответствующее двоичному представлению числа с фиксированной точкой с n разрядами под целую часть, 
// которое содержится в строке s. 
float Str2Float(char *s, int n) {
	float result = 0;
	int i, base = 1;

	i = n - 1;
	while (i < strlen(s)) {
		
		// В случае обнаружения недопустимого символа в строке s функция должна вывести на экран сообщение об ошибке и вернуть -1.
		if (s[i] != '0' && s[i] != '1') {
			std::cout << "Ошибка! В строке '" << s << "' обнаружен недопустимый символ '" << s[i] << "'!" << std::endl;
			return -1;
		}
		
		if (i <= n - 1) {  // перевод целой части:
			result += (s[i] - '0') * base;
			base *= 2;
			
			if (--i == -1) {  // переход на перевод дробной части:
				i = n;
				base = 2;
			}
		
		} else if (i >= n) {  // перевод дробной части:
			result += (s[i] - '0') * (1.0 / base);
			base *= 2;
			i++;
		}
		
	}
	
	return result;
}

int main(int argc, char** argv) {
	char *s = "1011101101";
	int n = 5;
	float result;
	
	cyrillic();
	
	result = Str2Float(s, n);
	if (result == -1) {
		system("pause");
		return EXIT_FAILURE;
	}
	
	std::cout << std::fixed << std::setprecision(5) << result << std::endl;  // 10111.01101 = (2^4) + (2^2) + (2^1) + (2^0) + (2^(-2)) + (2^(-3)) + (2^(-5)) = 23.40625
	
	system("pause");
	return EXIT_SUCCESS;
}

