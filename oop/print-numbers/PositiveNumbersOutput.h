#ifndef POSITIVENUMBERSOUTPUT_H
#define POSITIVENUMBERSOUTPUT_H

#include "NumbersOutput.h"

// ����� ������ ������������� �����:
class PositiveNumbersOutput : public NumbersOutput
{
	public:
	protected:
		virtual bool check(int number);
};

#endif
