#ifndef HPP_SORT
#define HPP_SORT

#include <cstdlib>

// ������� isNonDesc ���������� true, ���� ������ ����������� �� �������� ���������:
bool isNonDesc(int* arr, size_t n);
bool isNonDesc(float* arr, size_t n);

// ���������� �������:
void selectionSort(int* arr, size_t n);
void selectionSort(float* arr, size_t n);

// ���������� ���������:
void bubbleSort(int *arr, size_t n);
void bubbleSort(float *arr, size_t n);

// ���������� ���������:
void insertionSort(int *arr, size_t n);
void insertionSort(float *arr, size_t n);

// ������� ����������:
void quickSort(int *arr, size_t n);
void quickSort(float *arr, size_t n);

// ���������� �����:
void shellSort(int *arr, size_t n);
void shellSort(float *arr, size_t n);

#endif

