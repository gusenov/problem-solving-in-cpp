#ifndef NUMBERSOUTPUT_H
#define NUMBERSOUTPUT_H

// ����������� �����:
class NumbersOutput
{
	public:
		void print(int* array, int arrayLength);
	protected:
		virtual bool check(int number) = 0;
};

#endif
