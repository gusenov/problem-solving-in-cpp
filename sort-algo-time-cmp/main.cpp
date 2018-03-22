#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <windows.h>

#include "arr.hpp"
#include "rnd.hpp"
#include "sort.hpp"

const size_t PRINT_FIRST_EL = 8;  // количество выводимых на экран элементов.
const size_t COL_W_1 = 25;  // ширина 1-го столбца.
const size_t COL_W_2 = 10;  // ширина 2-го столбца.
const size_t COL_W_3 = 10;  // ширина 3-го столбца.

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

// Функция для замера выполнения сортировки целочисленного массива:
double timer(void (*sort)(int*, size_t), int* a, size_t n) {
	clock_t start = clock();  // старт.
	sort(a, n);  // сортировка.
	return (double)(clock() - start) / CLOCKS_PER_SEC;  // вычисление разницы в секундах.
}

// Функция для замера выполнения сортировки вещественного массива:
double timer(void (*sort)(float*, size_t), float* a, size_t n) {
	clock_t start = clock();  // старт.
	sort(a, n);  // сортировка.
	return (double)(clock() - start) / CLOCKS_PER_SEC;  // вычисление разницы в секундах.
}

// Процедура для отладочного вывода элементов массивов после сортировки:
void printSortedArrays(int* intArr, size_t n, float* floatArr, size_t m) {
	
	std::cout << "Первые " << PRINT_FIRST_EL << " элементов сорт. целочисленного массива:" << std::endl;
	printArr(intArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // вывод на экран первых PRINT_FIRST_EL элементов.
	
	std::cout << "Первые " << PRINT_FIRST_EL << " элементов сорт. вещественного массива:" << std::endl;
	printArr(floatArr, m > PRINT_FIRST_EL ? PRINT_FIRST_EL : m);  // вывод на экран первых PRINT_FIRST_EL элементов.
	
}

int main(int argc, char** argv) {
	bool debug = false;  // нужно ли выводить отсортированные массивы?
	
	cyrillic();  // настроить русский язык.
	srand(time(0));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).
	
	size_t n;
	std::cout << "Введите количество элементов в массиве -> ";
	std::cin >> n;
	
	// Создание случайного целочисленного массива размера n:
	int* srcRndIntArr = newRndIntArr(n);
	std::cout << "Первые " << PRINT_FIRST_EL << " элементов целочисленного массива:" << std::endl;
	printArr(srcRndIntArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // вывод на экран первых PRINT_FIRST_EL элементов.
	
	// Создание случайного вещественного массива размера n:
	float* srcRndFloatArr = newRndFloatArr(n);
	std::cout << "Первые " << PRINT_FIRST_EL << " элементов вещественного массива:" << std::endl;
	printArr(srcRndFloatArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // вывод на экран первых PRINT_FIRST_EL элементов.
	
	std::cout << std::endl << "Оценка времени работы различных функций сортировки массивов различных типов: " << std::endl;
	
	int* tmpIntArr = newArrFrom(srcRndIntArr, n);  // указатель на целочисленный массив, который будет сортироваться.
	float* tmpFloatArr = newArrFrom(srcRndFloatArr, n);  // указатель на вещественный массив, который будет сортироваться.
	
	// Вывод заголовка таблицы:
	std::cout << std::endl << std::setw(COL_W_1) << "Алгоритм " 
			  << std::setw(COL_W_2) << "int " 
			  << std::setw(COL_W_3) << "float " 
			  << std::endl;

	// Быстрая сортировка:
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // подготовка временного целочисленного массива, который будет сортироваться.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // подготовка временного вещественного массива, который будет сортироваться.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "Быстрая сортировка " 
			  << std::setw(COL_W_2 - 2) << timer(quickSort, tmpIntArr, n) << "s "  // время сортировки целочисленного массива.
			  << std::setw(COL_W_3 - 2) << timer(quickSort, tmpFloatArr, n) << "s "  // время сортировки вещественного массива.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // вывод отсортированных массивов.
	assert(isNonDesc(tmpIntArr, n));  // проверка на то, что целочисленный массив отсортировался верно.
	assert(isNonDesc(tmpFloatArr, n));  // проверка на то, что вещественный массив отсортировался верно.

	// Сортировка Шелла:	  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // подготовка временного целочисленного массива, который будет сортироваться.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // подготовка временного вещественного массива, который будет сортироваться.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "Сортировка Шелла " 
			  << std::setw(COL_W_2 - 2) << timer(shellSort, tmpIntArr, n) << "s "  // время сортировки целочисленного массива.
			  << std::setw(COL_W_3 - 2) << timer(shellSort, tmpFloatArr, n) << "s "  // время сортировки вещественного массива.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // вывод отсортированных массивов.
	assert(isNonDesc(tmpIntArr, n));  // проверка на то, что целочисленный массив отсортировался верно.
	assert(isNonDesc(tmpFloatArr, n));  // проверка на то, что вещественный массив отсортировался верно.

	// Сортировка вставками:		  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // подготовка временного целочисленного массива, который будет сортироваться.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // подготовка временного вещественного массива, который будет сортироваться.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "Сортировка вставками " 
			  << std::setw(COL_W_2 - 2) << timer(insertionSort, tmpIntArr, n) << "s "  // время сортировки целочисленного массива.
			  << std::setw(COL_W_3 - 2) << timer(insertionSort, tmpFloatArr, n) << "s "  // время сортировки вещественного массива.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // вывод отсортированных массивов.
	assert(isNonDesc(tmpIntArr, n));  // проверка на то, что целочисленный массив отсортировался верно.
	assert(isNonDesc(tmpFloatArr, n));  // проверка на то, что вещественный массив отсортировался верно.

	// Сортировка выбором:
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // подготовка временного целочисленного массива, который будет сортироваться.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // подготовка временного вещественного массива, который будет сортироваться.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "Сортировка выбором " 
			  << std::setw(COL_W_2 - 2) << timer(selectionSort, tmpIntArr, n) << "s "  // время сортировки целочисленного массива.
			  << std::setw(COL_W_3 - 2) << timer(selectionSort, tmpFloatArr, n) << "s "  // время сортировки вещественного массива.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // вывод отсортированных массивов.
	assert(isNonDesc(tmpIntArr, n));  // проверка на то, что целочисленный массив отсортировался верно.
	assert(isNonDesc(tmpFloatArr, n));  // проверка на то, что вещественный массив отсортировался верно.

	// Сортировка пузырьком:	  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // подготовка временного целочисленного массива, который будет сортироваться.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // подготовка временного вещественного массива, который будет сортироваться.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "Сортировка пузырьком " 
			  << std::setw(COL_W_2 - 2) << timer(bubbleSort, tmpIntArr, n) << "s "  // время сортировки целочисленного массива.
			  << std::setw(COL_W_3 - 2) << timer(bubbleSort, tmpFloatArr, n) << "s "  // время сортировки вещественного массива.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // вывод отсортированных массивов.
	assert(isNonDesc(tmpIntArr, n));  // проверка на то, что целочисленный массив отсортировался верно.
	assert(isNonDesc(tmpFloatArr, n));  // проверка на то, что вещественный массив отсортировался верно.


	// Освобождение ресурсов:
	
	delete tmpIntArr;
	delete tmpFloatArr;
	
	delete srcRndIntArr;
	delete srcRndFloatArr;
	
	
	system("pause");
	return EXIT_SUCCESS;
}

