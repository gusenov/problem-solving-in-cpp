#include "NumbersOutput.h"
#include <iostream>

using namespace std;

void NumbersOutput::print(int* array, int arrayLength)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		if (check(array[i])) {
			cout << array[i] << " ";
		}
	}
	cout << endl;
}

