#ifndef HPP_SORT
#define HPP_SORT

#include <cstdlib>

// Функции isNonDesc возвращают true, если массив неубывающий по значению элементов:
bool isNonDesc(int* arr, size_t n);
bool isNonDesc(float* arr, size_t n);

// Сортировка выбором:
void selectionSort(int* arr, size_t n);
void selectionSort(float* arr, size_t n);

// Сортировка пузырьком:
void bubbleSort(int *arr, size_t n);
void bubbleSort(float *arr, size_t n);

// Сортировка вставками:
void insertionSort(int *arr, size_t n);
void insertionSort(float *arr, size_t n);

// Быстрая сортировка:
void quickSort(int *arr, size_t n);
void quickSort(float *arr, size_t n);

// Сортировка Шелла:
void shellSort(int *arr, size_t n);
void shellSort(float *arr, size_t n);

#endif

