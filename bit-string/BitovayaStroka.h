#ifndef BITOVAYASTROKA_H
#define BITOVAYASTROKA_H

#include "Stroka.h"

// ����� �������_������:
class BitovayaStroka : public Stroka
{
	// ������������� �������:
	
	friend BitovayaStroka operator|(const BitovayaStroka& bit1, const BitovayaStroka& bit2);
	// const ��������, ��� ����� ���������� ������ �������� ������.
	
	friend std::istream& operator>>(std::istream& stream, BitovayaStroka& bit);
	
	public:
		// ����������� �� ����-��������������� ���������������� ������:
		BitovayaStroka(const char* in_bit_stroka);
		
		// ����� ����������� �����������:
		BitovayaStroka(const BitovayaStroka& stroka);
		// const ��������, ��� ����� ���������� stroka ������ �������� ������.
		
		// ����������� �� ����� ������� ������:
		BitovayaStroka(const int dlina);
		
		~BitovayaStroka();
	protected:
		
		// ���������� ������� ��������, 
		// ���� � ������� ���������������� ������ ��������� ����� �������, 
		// �������� �� ����������.
		void fix();
};

#endif
