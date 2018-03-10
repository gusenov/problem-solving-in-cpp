#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <windows.h>

#include "arr.hpp"
#include "rnd.hpp"
#include "sort.hpp"

const size_t PRINT_FIRST_EL = 8;  // ���������� ��������� �� ����� ���������.
const size_t COL_W_1 = 25;  // ������ 1-�� �������.
const size_t COL_W_2 = 10;  // ������ 2-�� �������.
const size_t COL_W_3 = 10;  // ������ 3-�� �������.

// ������� �� ���������:
void cyrillic() {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ � ��� ��������� �Lucida Console�. 
}

// ������� ��� ������ ���������� ���������� �������������� �������:
double timer(void (*sort)(int*, size_t), int* a, size_t n) {
	clock_t start = clock();  // �����.
	sort(a, n);  // ����������.
	return (double)(clock() - start) / CLOCKS_PER_SEC;  // ���������� ������� � ��������.
}

// ������� ��� ������ ���������� ���������� ������������� �������:
double timer(void (*sort)(float*, size_t), float* a, size_t n) {
	clock_t start = clock();  // �����.
	sort(a, n);  // ����������.
	return (double)(clock() - start) / CLOCKS_PER_SEC;  // ���������� ������� � ��������.
}

// ��������� ��� ����������� ������ ��������� �������� ����� ����������:
void printSortedArrays(int* intArr, size_t n, float* floatArr, size_t m) {
	
	std::cout << "������ " << PRINT_FIRST_EL << " ��������� ����. �������������� �������:" << std::endl;
	printArr(intArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // ����� �� ����� ������ PRINT_FIRST_EL ���������.
	
	std::cout << "������ " << PRINT_FIRST_EL << " ��������� ����. ������������� �������:" << std::endl;
	printArr(floatArr, m > PRINT_FIRST_EL ? PRINT_FIRST_EL : m);  // ����� �� ����� ������ PRINT_FIRST_EL ���������.
	
}

int main(int argc, char** argv) {
	bool debug = false;  // ����� �� �������� ��������������� �������?
	
	cyrillic();  // ��������� ������� ����.
	srand(time(0));  // �������������� ������������ ���������� ��������� ����� (����� ������ �������� ������ ��������� �����).
	
	size_t n;
	std::cout << "������� ���������� ��������� � ������� -> ";
	std::cin >> n;
	
	// �������� ���������� �������������� ������� ������� n:
	int* srcRndIntArr = newRndIntArr(n);
	std::cout << "������ " << PRINT_FIRST_EL << " ��������� �������������� �������:" << std::endl;
	printArr(srcRndIntArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // ����� �� ����� ������ PRINT_FIRST_EL ���������.
	
	// �������� ���������� ������������� ������� ������� n:
	float* srcRndFloatArr = newRndFloatArr(n);
	std::cout << "������ " << PRINT_FIRST_EL << " ��������� ������������� �������:" << std::endl;
	printArr(srcRndFloatArr, n > PRINT_FIRST_EL ? PRINT_FIRST_EL : n);  // ����� �� ����� ������ PRINT_FIRST_EL ���������.
	
	std::cout << std::endl << "������ ������� ������ ��������� ������� ���������� �������� ��������� �����: " << std::endl;
	
	int* tmpIntArr = newArrFrom(srcRndIntArr, n);  // ��������� �� ������������� ������, ������� ����� �������������.
	float* tmpFloatArr = newArrFrom(srcRndFloatArr, n);  // ��������� �� ������������ ������, ������� ����� �������������.
	
	// ����� ��������� �������:
	std::cout << std::endl << std::setw(COL_W_1) << "�������� " 
			  << std::setw(COL_W_2) << "int " 
			  << std::setw(COL_W_3) << "float " 
			  << std::endl;

	// ������� ����������:
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // ���������� ���������� �������������� �������, ������� ����� �������������.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // ���������� ���������� ������������� �������, ������� ����� �������������.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "������� ���������� " 
			  << std::setw(COL_W_2 - 2) << timer(quickSort, tmpIntArr, n) << "s "  // ����� ���������� �������������� �������.
			  << std::setw(COL_W_3 - 2) << timer(quickSort, tmpFloatArr, n) << "s "  // ����� ���������� ������������� �������.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // ����� ��������������� ��������.
	assert(isNonDesc(tmpIntArr, n));  // �������� �� ��, ��� ������������� ������ �������������� �����.
	assert(isNonDesc(tmpFloatArr, n));  // �������� �� ��, ��� ������������ ������ �������������� �����.

	// ���������� �����:	  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // ���������� ���������� �������������� �������, ������� ����� �������������.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // ���������� ���������� ������������� �������, ������� ����� �������������.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "���������� ����� " 
			  << std::setw(COL_W_2 - 2) << timer(shellSort, tmpIntArr, n) << "s "  // ����� ���������� �������������� �������.
			  << std::setw(COL_W_3 - 2) << timer(shellSort, tmpFloatArr, n) << "s "  // ����� ���������� ������������� �������.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // ����� ��������������� ��������.
	assert(isNonDesc(tmpIntArr, n));  // �������� �� ��, ��� ������������� ������ �������������� �����.
	assert(isNonDesc(tmpFloatArr, n));  // �������� �� ��, ��� ������������ ������ �������������� �����.

	// ���������� ���������:		  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // ���������� ���������� �������������� �������, ������� ����� �������������.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // ���������� ���������� ������������� �������, ������� ����� �������������.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "���������� ��������� " 
			  << std::setw(COL_W_2 - 2) << timer(insertionSort, tmpIntArr, n) << "s "  // ����� ���������� �������������� �������.
			  << std::setw(COL_W_3 - 2) << timer(insertionSort, tmpFloatArr, n) << "s "  // ����� ���������� ������������� �������.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // ����� ��������������� ��������.
	assert(isNonDesc(tmpIntArr, n));  // �������� �� ��, ��� ������������� ������ �������������� �����.
	assert(isNonDesc(tmpFloatArr, n));  // �������� �� ��, ��� ������������ ������ �������������� �����.

	// ���������� �������:
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // ���������� ���������� �������������� �������, ������� ����� �������������.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // ���������� ���������� ������������� �������, ������� ����� �������������.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "���������� ������� " 
			  << std::setw(COL_W_2 - 2) << timer(selectionSort, tmpIntArr, n) << "s "  // ����� ���������� �������������� �������.
			  << std::setw(COL_W_3 - 2) << timer(selectionSort, tmpFloatArr, n) << "s "  // ����� ���������� ������������� �������.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // ����� ��������������� ��������.
	assert(isNonDesc(tmpIntArr, n));  // �������� �� ��, ��� ������������� ������ �������������� �����.
	assert(isNonDesc(tmpFloatArr, n));  // �������� �� ��, ��� ������������ ������ �������������� �����.

	// ���������� ���������:	  
	cpArrFromTo(srcRndIntArr, tmpIntArr, n);  // ���������� ���������� �������������� �������, ������� ����� �������������.
	cpArrFromTo(srcRndFloatArr, tmpFloatArr, n);  // ���������� ���������� ������������� �������, ������� ����� �������������.
	std::cout << std::endl 
			  << std::setw(COL_W_1) << "���������� ��������� " 
			  << std::setw(COL_W_2 - 2) << timer(bubbleSort, tmpIntArr, n) << "s "  // ����� ���������� �������������� �������.
			  << std::setw(COL_W_3 - 2) << timer(bubbleSort, tmpFloatArr, n) << "s "  // ����� ���������� ������������� �������.
			  << std::endl;
	if (debug) printSortedArrays(tmpIntArr, n, tmpFloatArr, n);  // ����� ��������������� ��������.
	assert(isNonDesc(tmpIntArr, n));  // �������� �� ��, ��� ������������� ������ �������������� �����.
	assert(isNonDesc(tmpFloatArr, n));  // �������� �� ��, ��� ������������ ������ �������������� �����.


	// ������������ ��������:
	
	delete tmpIntArr;
	delete tmpFloatArr;
	
	delete srcRndIntArr;
	delete srcRndFloatArr;
	
	
	system("pause");
	return EXIT_SUCCESS;
}

