#include "rnd.hpp"

// ������� rand() ���������� ����� � ��������� �� 0 �� RAND_MAX.
// RAND_MAX � ��� ���������, ����������� � ���������� <cstdlib>.
// #define RAND_MAX 0x7fff /* 32767 */
// ��� Dev-C++ 5.11 RAND_MAX = 32767, �� ��� ����� ���� � ������, � ����������� �� �����������.

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
		*(arr + i) = ( rand() % (rigth + 1) );  // ��������� ���������� ������ ����� � ��������� [0; rigth].
	}
	return arr;
}

float* newRndFloatArr(size_t sz) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);  // ��������� ���������� ������������� ����� � ��������� [0; 1].
	}
	return arr;
}

float* newRndFloatArr(size_t sz, size_t right) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / right));  // ��������� ���������� ������������� ����� � ��������� [0; right].
	}
	return arr;
}

float* newRndFloatArr(size_t sz, size_t left, size_t right) {
	float* arr = new float[sz];
	for (int i = 0; i < sz; i++) {
		*(arr + i) = left + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (right - left)));  // ��������� ���������� ������������� ����� � ��������� [left; right].
	}
	return arr;
}
