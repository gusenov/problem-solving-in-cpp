#ifndef POSITIVENUMBERSOUTPUT_H
#define POSITIVENUMBERSOUTPUT_H

#include "NumbersOutput.h"

// Класс вывода положительных чисел:
class PositiveNumbersOutput : public NumbersOutput
{
	public:
	protected:
		virtual bool check(int number);
};

#endif
