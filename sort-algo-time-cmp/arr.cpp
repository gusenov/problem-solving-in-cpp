#include "arr.hpp"

// Перегрузка функций вывода массива на экран:

void printArr(int* arr, size_t sz) {
    for (size_t i = 0; i < sz; i++)
    	std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void printArr(float* arr, size_t sz) {
    for (size_t i = 0; i < sz; i++)
    	std::cout << arr[i] << " ";
    std::cout << std::endl;
}

// Перегрузка функций копирования массива:

int* cpArrFromTo(int* from, int* to, size_t sz) {
	return (int*)memcpy(to, from, sz * sizeof(int));
}

float* cpArrFromTo(float* from, float* to, size_t sz) {
	return (float*)memcpy(to, from, sz * sizeof(float));
}

// Перегрузка функций клонирования массива:

int* newArrFrom(int* arr, size_t sz) {
	int* copy = new int[sz];
	return (int*)memcpy(copy, arr, sz * sizeof(int));
}

float* newArrFrom(float* arr, size_t sz) {
	float* copy = new float[sz];
	return (float*)memcpy(copy, arr, sz * sizeof(float));
}

