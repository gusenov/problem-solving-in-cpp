#include "rnd.hpp"

// Функция rand() генерирует числа в диапазоне от 0 до RAND_MAX.
// RAND_MAX — это константа, определённая в библиотеке <cstdlib>.
// #define RAND_MAX 0x7fff /* 32767 */
// Для Dev-C++ 5.11 RAND_MAX = 32767, но оно может быть и больше, в зависимости от компилятора.

int* newRndIntArr(size_t sz) {
	int* arr = new int[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = rand();
	}
	return arr;
}

int* newRndIntArr(size_t sz, size_t rigth) {
	int* arr = new int[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = ( rand() % (rigth + 1) );  // генерация случайного целого числа в диапазоне [0; rigth].
	}
	return arr;
}

float* newRndFloatArr(size_t sz) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);  // генерация случайного вещественного числа в диапазоне [0; 1].
	}
	return arr;
}

float* newRndFloatArr(size_t sz, size_t right) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / right));  // генерация случайного вещественного числа в диапазоне [0; right].
	}
	return arr;
}

float* newRndFloatArr(size_t sz, size_t left, size_t right) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = left + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (right - left)));  // генерация случайного вещественного числа в диапазоне [left; right].
	}
	return arr;
}
