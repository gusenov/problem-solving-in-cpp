#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "NumbersOutput.h"
#include "EvenNumbersOutput.h"
#include "OddNumbersOutput.h"
#include "PositiveNumbersOutput.h"
#include "NegativeNumbersOutput.h"

#define MIN_ARRAY_LEN 10
#define MAX_ARRAY_LEN 20
#define MAX_ELEM_VAL 1000

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
	
	// Автоматическая рандомизация генератора случайных чисел 
	// (чтобы всегда получать разные случайные числа):
	srand(time(0));

	NumbersOutput* numOut;

	// Случайный класс для вывода чисел:
	cout << "Случайным классом для вывода чисел выбран:\n";
	switch (rand() % 4)  // генерация случайного целого числа в диапазоне [0; 4).
	{
		case 0:
			numOut = new EvenNumbersOutput();
			cout << " класс вывода четных чисел.";
			break;
		case 1:
			numOut = new OddNumbersOutput();
			cout << " класс вывода нечетных чисел.";
			break;
		case 2:
			numOut = new PositiveNumbersOutput();
			cout << " класс вывода положительных чисел.";
			break;
		default:
			numOut = new NegativeNumbersOutput();
			cout << " класс вывода отрицательных чисел.";
			break;
	}
	cout << endl;
	
	// Создание массива из N (от MIN_ARRAY_LEN до MAX_ARRAY_LEN) 
	// случайных положительных и отрицательных чисел:
	int arrayLength = rand() % (MAX_ARRAY_LEN - MIN_ARRAY_LEN + 1) + MIN_ARRAY_LEN;
	int* array = new int[arrayLength];
	for (int i = 0; i < arrayLength; ++i)
	{
		// Генерация случайного целого числа в диапазоне [0; MAX_ELEM_VAL):
		array[i] = rand() % MAX_ELEM_VAL;
		
		// Генерируем случайное целое число в диапазоне [0; 1] 
		// и если выпало 0, то меняем знак на минус:
		if (rand() % 2 == 0)
		{
			array[i] = -array[i];
		}
	}
	cout << "\nСоздан массив из " << arrayLength 
		<< " случайных положительных и отрицательных чисел\n"
		<< " в диапазоне [-" << MAX_ELEM_VAL << "; " << MAX_ELEM_VAL << "].\n";
	
	cout << "\nВывод массива на экран:\n";
	for (int i = 0; i < arrayLength; ++i)
		cout << array[i] << " ";
	cout << endl;
	
	cout << "\nПодача массива в класс вывода:\n";
	numOut->print(array, arrayLength);
	
	delete numOut;
	delete[] array;

	system("pause");
	return 0;
}
