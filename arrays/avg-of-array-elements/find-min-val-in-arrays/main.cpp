#include <iostream>
#include <cstdlib>
#include <ctime>
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

const int ARRAY_SZ = 5;  // размер массивов.

using namespace std;

// Функция для заполнения массива случайными числами:
void fillArray(float *arr, int sz) {
	for (int idx = 0; idx < sz; idx++) {
		arr[idx] = rand() % 100 + 1;  // генерация случайного целого числа в диапазоне [1; 100].
	}
}

// Функция для вывода массива на экран:
void printArray(const char *title, float *arr, int sz) {
	cout << title << endl;
	for (int idx = 0; idx < sz; idx++) {
		cout << arr[idx] << " ";
	}
	cout << endl;
}

// Функция для поиска минимального значения в массиве:
float findMinVal(float *arr, int sz) {
	float minVal = arr[0];
	for (int idx = 1; idx < sz; idx++) {
		if (arr[idx] < minVal) {
			minVal = arr[idx];
		}
	}
	return minVal;
}

// Функция для деления элементов массива на заданное число:
void divArrayBy(float *arr, int sz, float val) {
	for (int idx = 0; idx < sz; idx++) {
		arr[idx] /= val;
	}
}

int main(int argc, char** argv) {
	cyrillic();  // переход на кириллицу.
	srand(time(0));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).

	float A[ARRAY_SZ];
	fillArray(A, ARRAY_SZ);
	printArray("Исходный массив A:", A, ARRAY_SZ);
	float minValA = findMinVal(A, ARRAY_SZ);
	cout << "Минимальное значение в массиве A: " << minValA << endl;
	divArrayBy(A, ARRAY_SZ, minValA);
	printArray("Преобразованный массив A:", A, ARRAY_SZ);
	
	cout << endl;
	
	float B[ARRAY_SZ];
	fillArray(B, ARRAY_SZ);
	printArray("Исходный массив B:", B, ARRAY_SZ);
	float minValB = findMinVal(B, ARRAY_SZ);
	cout << "Минимальное значение в массиве B: " << minValB << endl;
	divArrayBy(B, ARRAY_SZ, minValB);
	printArray("Преобразованный массив B:", B, ARRAY_SZ);
	
	return 0;
}
