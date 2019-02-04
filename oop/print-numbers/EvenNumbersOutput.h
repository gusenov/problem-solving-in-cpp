#ifndef EVENNUMBERSOUTPUT_H
#define EVENNUMBERSOUTPUT_H

#include "NumbersOutput.h"

// Класс вывода четных чисел:
class EvenNumbersOutput : public NumbersOutput
{
	public:
	protected:
		virtual bool check(int number);
};

#endif
