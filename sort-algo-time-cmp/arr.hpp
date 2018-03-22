#ifndef HPP_ARR
#define HPP_ARR

#include <cstdlib>
#include <iostream>

// Вывод массива на экран:
void printArr(int* arr, size_t sz);
void printArr(float* arr, size_t sz);

// Копирование массива:
int* cpArrFromTo(int* from, int* to, size_t sz);
float* cpArrFromTo(float* from, float* to, size_t sz);

// Клонирование массива:
int* newArrFrom(int* arr, size_t sz);
float* newArrFrom(float* arr, size_t sz);

#endif

