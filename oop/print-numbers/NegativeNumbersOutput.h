#ifndef NEGATIVENUMBERSOUTPUT_H
#define NEGATIVENUMBERSOUTPUT_H

#include "NumbersOutput.h"

// Класс вывода отрицательных чисел:
class NegativeNumbersOutput : public NumbersOutput
{
	public:
	protected:
		virtual bool check(int number);
};

#endif
