#ifndef HPP_RND
#define HPP_RND

#include <cstdlib>

// ��������� ��������������� ������������� �����:
int* newRndIntArr(size_t sz);  // [0; RAND_MAX]
int* newRndIntArr(size_t sz, size_t rigth);  // [0; rigth]

// ��������� ��������������� ������������ �����:
float* newRndFloatArr(size_t sz);  // [0; 1]
float* newRndFloatArr(size_t sz, size_t right);  // [0; right]
float* newRndFloatArr(size_t sz, size_t left, size_t right);  // [left; right]

#endif

