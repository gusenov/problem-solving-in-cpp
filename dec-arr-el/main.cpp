#include <iostream>
#include <cstdlib>
#include <ctime>
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
	int i;  // счетчик. 
	int N;  // размер исходного массива.
	float m = 0;  // количество положительных элементов одномерного массива.
	float avg = 0;  // среднее значение положительных элементов одномерного массива.
	float *pt;  // указатель для обращения к элементам массива.
	
	cyrillic();
	
	cout << "Введите с клавиатуры размер массива: ";
	cin >> N;
	
	float *A = new float[N];  // дан массив A[N].
	// Несмотря на то, что далее массив будет заполняться целыми числами, здесь используем float,
	// потому что элементы будут уменьшаться на ср. значение положительных элементов,
	// которое может быть числом с дробной частью.
	
	pt = A;
	
	// Элементы массива заполняются, используя функцию генератора случайных чисел целого типа:
	srand(time(NULL));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).
	std::cout << "Исходный массив: " << std::endl;
	for (i = 0; i < N; i++ ) {
		*(pt + i) = (rand() % 10);  // генерация случайного целого числа в диапазоне [0; 10).
		
		// Генерация знака для числа:
		if (rand() % 2 == 0) {  // генерируем случайное целое число в диапазоне [0; 1] и если выпало 0, то меняем знак на минус:
			*(pt + i) = - *(pt + i);  // обращение к элементу массива производится с помощью указателя.
		}
		
		cout << "Элемент №" << i + 1 << " = " << A[i] << endl;  // при выводе элементов используются индексы.
		
		if (*(pt + i) > 0) {  // строго больше 0, потому что 0 не является не положительным не отрицательным числом.
			m++;
			avg += *(pt + i);  // обращение к элементу массива производится с помощью указателя.
		}
	}
	avg /= m;  // среднее значение положительных элементов одномерного массива.
	
	cout << endl << "Ср. значение положительных элементов одномерного массива = " << avg << endl << endl;
	
	cout << "Уменьшение всех элементов на ср. значение положительных элементов одномерного массива: " << endl;
	
	// Обработка одномерного массива:
	for (i = 0; i < N; i++) { 
		*(pt + i) -= avg;  // обращение к элементу массива производится с помощью указателя.
		cout << "Элемент №" << i + 1 << " = " << A[i] << endl;  // при выводе элементов используются индексы.
	}
	
	delete [] A;
	
	system("pause");
	return 0;
}

