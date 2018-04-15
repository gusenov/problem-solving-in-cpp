// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <iostream>  // ввод/вывод.
#include <cstdlib>  // константа EXIT_SUCCESS.
#include <cmath>  // функция pow().
#include <iomanip>  // std::setw для задания ширины при выводе; std::fixed и std::setprecision() для форматирования вещественных чисел.
#include <windows.h>  // нужно для функций SetConsoleOutputCP и SetConsoleCP.

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

// Выделение памяти под матрицу n*m:
float** matalloc(int n, int m) {
    float** mat = new float*[n];
    for (int i = 0; i < n; i++) { 
        mat[i] = new float[m];
        for (int j = 0; j < m; j++) {
        	mat[i][j] = 0;
		}
    }
    return mat;
}

// Освобождение памяти под матрицу:
void matfree(float** mat, int n) {
	for (int i = 0; i < n; ++i) {
		delete[] mat[i];
	}
	delete[] mat;
}

// Ввод матрицы:
void matinput(float** mat, int n, int m) {	
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
}

// Вывод матрицы:
void matprint(float** mat, int n, int m) {	
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << std::setw(8) << std::fixed << std::setprecision(2) << mat[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для вычисления значения определителя матрицы:
float matdeterminant(float** mat, int n) {
	float det = 0;
	
	if (n < 1) {
		// ОШИБКА!
	
	} else if (n == 1) {
		// Для матрицы первого порядка значение детерминанта равно единственному элементу этой матрицы:
		det = mat[0][0];
	
	} else if (n == 2) {
		// Для матрицы 2*2 определитель вычисляется как:
		det = mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
	
	// Для матрицы n*n определитель вычисляется разложением по строке:
	} else {
		// Выделение памяти под дополнительный минор:
		float** m = matalloc(n - 1, n - 1);
			
		for (int j1 = 0; j1 < n; j1++) {
		
			// Вычисление дополнительного минора к элементу mat[0][j1]:	
			for (int i = 1; i < n; i++) {  // начиная i с 1 вычеркиваем первую строку.
				int j2 = 0;
				for (int j = 0; j < n; j++) {
					if (j == j1) {
						// Вычеркиваем j1-й столбец:
						continue;
					}
					m[i - 1][j2] = mat[i][j];
					j2++;
				}
			}
			
			// Вычисление определителя по рекурсивной формуле:
			det += pow(-1.0, j1 + 2.0) * mat[0][j1] * matdeterminant(m, n - 1);
		}
		
		// Освобождение памяти выделенной под дополнительный минор.
		matfree(m, n - 1);
	}
	
	return det;
}

// Функция для получения союзной (присоединённой) квадратной матрицы:
void matcofactor(float **mat, int n, float **out) {
	
	// Выделение памяти под дополнительный минор:
	float** c = matalloc(n - 1, n - 1);
	
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
		
			// Получение дополнительного минора
			// путём вычёркивания i-й строки и j-го столбца:
			int i1 = 0;
			for (int ii = 0; ii < n; ii++) {
				if (ii == i)
					continue;
				int j1 = 0;
				for (int jj = 0; jj < n; jj++) {
					if (jj == j)
						continue;
					c[i1][j1] = mat[ii][jj];
					j1++;
				}
				i1++;
			}
			
			float det = matdeterminant(c, n - 1);  // вычисление определителя.
			
			// Алгебраическое дополнение элемента mat[i][j]:
			out[i][j] = pow(-1.0, i + j + 2.0) * det;
		}
	}
	
	// Освобождение памяти занятой под дополнительный минор:
	matfree(c, n - 1);
}

// Функция для получения транспонированной квадратной матрицы:
void mattranspose(float** mat, int n) {
	// Замена строк на столбцы:
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			float t = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = t;
		}
	}
}

// Функция для получения обратной квадратной матрицы
// с помощью матрицы алгебраических дополнений:
void matinverse(float** mat, int n, float** inverseofmat) {
	matcofactor(mat, n, inverseofmat);  // присоединённая матрица.
	mattranspose(inverseofmat, n);  // транспонированная присоединённая матрица.
	float det = matdeterminant(mat, n);  // значение определителя исходной матрицы.
	
	// Вычисление обратной матрицы:
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			inverseofmat[i][j] /= det;
		}
	}
}

// Заполение матрицы следующими элементами:
//  1  2  0
// -1  1  1
//  1  2  3
// Для отладки.
void matexample1(float** mat, int n, int m) {
	if (n == 3 && m == 3) {
		mat[0][0] = 1;  mat[0][1] = 2; mat[0][2] = 0;
		mat[1][0] = -1; mat[1][1] = 1; mat[1][2] = 1;
		mat[2][0] = 1;  mat[2][1] = 2; mat[2][2] = 3;
	}
}

int main(int argc, char** argv) {
	cyrillic();  // вкл. кириллицу.

	int n, m;
	cout << "Введите n и m -> ";
	cin >> n >> m;
	//n = m = 3;  // DEBUG.
	
	if (n != m) {
		cout << "Для неквадратных матриц и вырожденных матриц обратных матриц не существует." << endl;

	} else {
		float** srcmat = matalloc(n, m);
		
		cout << "Введите элементы матрицы:" << endl;
		matinput(srcmat, n, m);
		//matexample1(srcmat, n, m);  // DEBUG.
		
		cout << "Вывод исходной матрицы:" << endl;
		matprint(srcmat, n, m);
		
		float det = matdeterminant(srcmat, n);
		cout << "Определитель = " << det << endl;
		
		if (det == 0) {
			cout << "Квадратная матрица обратима тогда и только тогда," << endl << 
				" когда она невырожденная, то есть её определитель не равен нулю." << endl;
		} else {
			// Выделение памяти под обратную матрицу:
			float** inverseofmat = matalloc(n, m);

			matinverse(srcmat, n, inverseofmat);
			
			cout << "Вывод обратной матрицы:" << endl;
			matprint(inverseofmat, n, m);

			// Освобождение памяти под обратную матрицу:
			matfree(inverseofmat, n);
		}
		
		matfree(srcmat, n);
	}

	// Возврат нуля, 
	// что означает успешное завершение программы: 
	return EXIT_SUCCESS;
}

