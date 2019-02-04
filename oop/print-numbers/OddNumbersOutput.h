#ifndef ODDNUMBERSOUTPUT_H
#define ODDNUMBERSOUTPUT_H

#include "NumbersOutput.h"

// Класс вывода нечетных чисел:
class OddNumbersOutput : public NumbersOutput
{
	public:
	protected:
		virtual bool check(int number);
};

#endif
