#ifndef HPP_RND
#define HPP_RND

#include <cstdlib>

// Генерация псевдослучайных целочисленных чисел:
int* newRndIntArr(size_t sz);  // [0; RAND_MAX]
int* newRndIntArr(size_t sz, size_t rigth);  // [0; rigth]

// Генерация псевдослучайных вещественных чисел:
float* newRndFloatArr(size_t sz);  // [0; 1]
float* newRndFloatArr(size_t sz, size_t right);  // [0; right]
float* newRndFloatArr(size_t sz, size_t left, size_t right);  // [left; right]

#endif

