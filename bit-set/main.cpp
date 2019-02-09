#include <iostream>
#include "tbitfield.h"
#include "tset.h"
#include <string>
#include <sstream>

using namespace std;

void printBitField(TBitField& bf) {
	int BitLen = bf.GetLength();
	for (int i = 0; i < BitLen; ++i)
	{
		printf("%d", bf.GetBit(i));
		if ((i + 1) % 8 == 0) printf("|");
	}
}

void or_bit_operation_with_three_bitfields() {
	TBitField bf1(9);
	istringstream is1("100010001");
	is1 >> bf1;

	TBitField bf2(9);
	istringstream is2("000100010");
	is2 >> bf2;

	TBitField bf3(9);
	istringstream is3("010000100");
	is3 >> bf3;

	// 100010001
	// 000100010
	// 010000100
	//
	// 110110111

	TBitField bf4(9);
	istringstream is4("110110111");
	is4 >> bf4;

	TBitField result = bf1 | bf2 | bf3;
	cout << result;
}

int main(int argc, char** argv)
{
	//printf("sizeof(unsigned int) = %d\n", sizeof(unsigned int));
	
	or_bit_operation_with_three_bitfields();
	
	cout << endl;
	TSet set1(10);
	istringstream is1("0 1 2 3 4 5 6 7 9");
	is1 >> set1;
	cout << set1;
	
	printf("\n");
	system("pause");
	return 0;
}

