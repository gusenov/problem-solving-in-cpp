#include <iostream>
#include <iomanip> 
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
	// Для замены шрифта кликаете правой кнопкой на надписи "Командная строка" окна консоли. 
	// В открывшемся меню выбираете "Свойства". 
	// В появившемся окне выбираете вкладку "Шрифт" и там выбираете "Lucida Console". 
}

// Функция для выделения памяти под двумерный массив размером n x n:
float** newSquareMatrix(int n) {
	float** m = new float*[n];
	for (int i = 0; i < n; ++i) {
		m[i] = new float[n];
	}
	return m;
}

// Функция для освобождения памяти выделенной под двумерный массив размером n x n:
void freeSquareMatrix(float** mat, int n) {
	for (int i = 0; i < n; ++i) {
		delete [] mat[i];
	}
	delete [] mat;
}

// Функция для заполнения случайными числами двумерного массива:
void randomFillSquareMatrix(float** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = rand() % 100;  // генерация случайного целого числа в диапазоне [0; 100).
		}
	}
}

// Функция для ввода элементов двумерного массива:
void inputElementsOfSquareMatrix(float** mat, int n) {
	cout << "Введите элементы двумерного массива: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
}

// Функция для вывода массива на экран:
void printSquareMatrix(const char* title, float** mat, int n) {
	cout << title << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << std::setw(8) << std::fixed << std::setprecision(2) << mat[i][j] << " ";
		}
		cout << endl;
	}
}

// Функция для вычисления среднего арифметического двумерного массива:
float avgOfSquareMatrix(float** mat, int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			avg += mat[i][j];
		}
	}
	return avg / (n * n);
}

// Функция для деления элементов двумерного массива на заданное значение:
void divideElementsOfSquareMatrixBy(float** mat, int n, float val) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] /= val;
		}
	}
}

int main(int argc, char** argv) {
	cyrillic();  // переход на кириллицу.
	srand(time(0));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).

	int n;
	cout << "n -> ";
	cin >> n;
	
	float** A = newSquareMatrix(n);
	
	randomFillSquareMatrix(A, n);
	//inputElementsOfSquareMatrix(A, n);
	
	printSquareMatrix("Исходный двумерный массив:", A, n);
	
	float avg = avgOfSquareMatrix(A, n);
	cout << "Среднее арифметическое элементов двумерного массива: " << avg << endl;
	
	divideElementsOfSquareMatrixBy(A, n, avg);
	printSquareMatrix("Преобразованный двумерный массив:", A, n);
	
	freeSquareMatrix(A, n);
	
	system("pause");
	
	return 0;
}

