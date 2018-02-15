#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "matrixlib.hpp"

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

// Вспомогательная функция для заполнения матрицы случайными числами:
void fillrandom(Matrix &M, int max=1) {
	int i, j, no;  // индексы.
	double value;  // переменная для хранения сгенерированного случайного значения.
	
	for (i = 0; i < M.getysize(); i++) {
		for (j = 0; j < M.getxsize(); j++) {
			no = i * M.getxsize() + j + 1;  // индекс элемента матрицы [i][j] в последовательной системе индексации.
			
			if (max == 1) {
				value = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);  // генерация случайного вещественного числа в диапазоне [0.0; 1.0].
			} else {
				value = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / max));  // генерация случайного вещественного числа в диапазоне [0.0; max].
			}

			// Функция rand() генерирует числа в диапазоне от 0 до RAND_MAX.
			// RAND_MAX — это константа, определённая в библиотеке <cstdlib>.
			// RAND_MAX = (2 ^ 15) - 1 = 32767, но оно может быть и больше, в зависимости от компилятора.
			
			M(no) = value;
			// M2.Matrix::operator()(no) = value;
		}
	}
}

// Функция перегрузки операции "%" для вычисления объединения матриц по вертикали:
Matrix & Matrix::operator % (Matrix &M) const {
	// Чтобы исключить копирование данных и вызов конструктора для локальной копии объекта, параметр M передается по ссылке.
	
	int i, j = 1;

	// Объект-результат создается функцией operator% в динамической памяти, а возвращается ссылка на этот объект.
	Matrix *result = new Matrix(this->ysize + M.ysize, this->xsize, 0);

	// Копируем элементы первого операнда в результирующую матрицу:
	for (i = 1; i <= this->ysize * this->xsize; i++) {
		if (this->temporary) {  // operator() не работает на "временных" матрицах, поэтому:
			result->Array[j - 1] = this->Array[i - 1];
		} else {
			(*result)(j) = (*this)(i);
		}
		j++;
	}
	
	// Копируем элементы второго операнда в результирующую матрицу:
	for (i = 1; i <= M.ysize * M.xsize; i++) {
		if (M.temporary) {  // operator() не работает на "временных" матрицах, поэтому:
			result->Array[j - 1] = M.Array[i - 1];
		} else {
			(*result)(j) = M.Matrix::operator()(i);
		}
		j++;
	}
	
	// Операнды объекты-матрицы уничтожаются, если они "временные":
	if (this->temporary) {
		printf("ОТЛАДКА. Удаление объекта-операнда по адресу: '%p'.\n", this);
		delete this;
	}
	if (M.temporary) {
		printf("ОТЛАДКА. Удаление объекта-операнда по адресу: '%p'.\n", &M);
		delete &M;
	}

	printf("ОТЛАДКА. Возврат объекта-результата по адресу: '%p'.\n", result);

	result->temporary = 1;
	return (*result); // результат - ссылка на новую "временную" матрицу.
	
	// Вызывающая сторона обязана позаботиться о том, чтобы не потерять ссылку на безымянный динамический объект.
}

void test1(void) {
	cout << "Матрица №1 (первый операнд):" << endl;
	Matrix M1(3, 4, 0);
	fillrandom(M1);  // заполнить матрицу случайными значениями в диапазоне [0.0; 1.0].
	M1.show();
	
	cout << endl << "Матрица №2 (второй операнд):" << endl;
	Matrix M2(8, 4, 0);
	fillrandom(M2, 9.9);  // заполнить матрицу случайными значениями в диапазоне [0.0; 9.9].
	M2.show();
	
	cout << endl << "Результирующая матрица (результат операции M1 % M2):" << endl;
	Matrix& result = M1 % M2;
	result.show();
	
	// delete &result;
	// Вызывать деструктор для result не нужно потому что внутри функции show()
	
	cout << "ОТЛАДКА. Конец исполнения функции test1()" << endl;
}

void test2(void) {
	cout << "M1: " << endl;
	Matrix M1(1, 8, 0);
	fillrandom(M1);
	M1.show();
	
	cout << "M2: " << endl;
	Matrix M2(2, 8, 0);
	fillrandom(M2);
	M2.show();
	
	cout << "M3: " << endl;
	Matrix M3(3, 8, 0);
	fillrandom(M3);
	M3.show();
	
	cout << "M4: " << endl;
	Matrix M4(4, 8, 0);
	fillrandom(M4);
	M4.show();
	
	cout << endl << "Результат операции (M1 % M2) % (M3 % M4): " << endl;
	Matrix& result = (M1 % M2) % (M3 % M4);
	result.show();
	
	cout << "ОТЛАДКА. Конец исполнения функции test2()" << endl;
}

int main(int argc, char** argv) {
	cyrillic();

	// Вывод вещественного числа с точностью до 2 чисел после запятой:
	cout.setf(ios::fixed);
	cout.precision(2);
	
	srand(time(NULL));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).
	
	cout << "\tТест №1" << endl;
	test1();
	
	cout << "\tТест №2" << endl;
	test2();
	
	system("pause");
	return 0;
}

