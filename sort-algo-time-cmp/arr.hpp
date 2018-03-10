#ifndef HPP_ARR
#define HPP_ARR

#include <cstdlib>
#include <iostream>

// ����� ������� �� �����:
void printArr(int* arr, size_t sz);
void printArr(float* arr, size_t sz);

// ����������� �������:
int* cpArrFromTo(int* from, int* to, size_t sz);
float* cpArrFromTo(float* from, float* to, size_t sz);

// ������������ �������:
int* newArrFrom(int* arr, size_t sz);
float* newArrFrom(float* arr, size_t sz);

#endif

