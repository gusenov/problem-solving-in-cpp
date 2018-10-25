#ifndef STROKA_H
#define STROKA_H

#include <fstream>  // ���������� ��� ������ � �������.

// ����� ������, ����������� ��������� ������:
class Stroka
{
	// ������������� �������:
	friend std::ostream& operator<<(std::ostream& stream, Stroka& stroka);
	friend std::istream& operator>>(std::istream& stream, Stroka& stroka);
	
	public:
		// ����������� �� ���������:
		Stroka();
		
		// ����������� �� ����-��������������� ���������������� ������:
		Stroka(const char* in_stroka);  // in_stroka - ��� ���������������� ������.
		
		// ���������� ������������� �������, ����������� ����� ���������, � ���� ��������� const. 
		// ���� �������� ����� ����� "*", 
		// ���� const �����, �� ��� ��������� � �������� ������; 
		// ���� ������ � � �������� ���������.
		
		// ����� ����������� �����������:
		Stroka(const Stroka& stroka);
		// const ��������, ��� ����� ���������� stroka ������ �������� ������.
		
		// ������� ��� ����������� kol ��������� � ������ stroka1 �� ������ stroka2:
		static void kopir(char* const stroka1, char* const stroka2, int kol);
		
		// ����������� �� ����� ������:
		Stroka(const int dlina);
		
		~Stroka();
		
		// ����������� �����:
		int dlina_stroki() const;
		static int dlina(const char* stroka);
		
		// ��������� ����� ���� ����������� ��� �������-����� ������.
		// ����� ���������� ��������� ������ ��������� ������ *this. 
		// ��������� = -> [] () ����� ���� ����������� ������ ��� ������ (�������-�����), 
		// �� �� ��� �������.
		
		// ��������������� ��������� ������������ = (�����):
		Stroka& operator=(const char* in_stroka);
		Stroka& operator=(const Stroka& stroka);
		
		// �������� ������������ ���� �����:
		Stroka operator+(const Stroka& stroka);
		
		// ��������������� ��������� ���������� (���. � ����):
		char& operator[](int nomer);
		
		// ������� ��� ��������� �����:
		static int sr(const Stroka& stroka1, const Stroka& stroka2);
		
	protected:
		// ������� �������� ���������� �����:
		char* simvoly;
		
		int razmer;
};

// ��������� ����� ���� ����������� � ��� ��������� �������.

// �������� ��������� ���� �����:
bool operator==(const Stroka& stroka1, const Stroka& stroka2);
bool operator!=(const Stroka& stroka1, const Stroka& stroka2);
bool operator<(const Stroka& stroka1, const Stroka& stroka2);
bool operator<=(const Stroka& stroka1, const Stroka& stroka2);
bool operator>(const Stroka& stroka1, const Stroka& stroka2);
bool operator>=(const Stroka& stroka1, const Stroka& stroka2);

#endif
