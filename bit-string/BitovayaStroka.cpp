#include "BitovayaStroka.h"

BitovayaStroka::BitovayaStroka(const char* in_bit_stroka):
	Stroka(Stroka::dlina(in_bit_stroka))
	// �������� ������������ ����������� �� �����, 
	// ������� ��������� ����� ������� �������� simvoly,
	// � ������� � ������ ������ ������� ����� ������ simvoly,
	// +1 ������� ��� ����-�������.
{

	// ������ ������� ������ ����� ��������� ������ ������� '0' � '1'.
	// ���� � ������� ���������������� ������ ����� ��������� ����� �������, 
	// �������� �� ����������, �������_������ ��������� ������� ��������.
	
	bool nul = false;
	int dlina = this->razmer - 1;
	for (int i = 0; i < dlina; ++i)
	{
		if (nul)
		{
			(*this)[i] = '0';
		}
		else if (in_bit_stroka[i] != '0' && in_bit_stroka[i] != '1')
		{
			nul = true;
			for (int j = i; j >= 0; --j)
			{
				(*this)[j] = '0';
			}
		}
		else
		{
			(*this)[i] = in_bit_stroka[i];
		}
	}
}

void BitovayaStroka::fix()
{
	bool nul = false;
	int dlina = this->dlina_stroki();
	for (int i = 0; i < dlina; ++i)
	{
		if (nul)
		{
			(*this)[i] = '0';
		}
		else if ((*this)[i] != '0' && (*this)[i] != '1')
		{
			nul = true;
			for (int j = i; j >= 0; --j)
			{
				(*this)[j] = '0';
			}
		}
	}
}

// ����� ����������� �����������:
BitovayaStroka::BitovayaStroka(const BitovayaStroka& stroka):
	Stroka(stroka)
{
}

BitovayaStroka::BitovayaStroka(const int dlina):
	Stroka(dlina)
{
	for (int i = 0; i < dlina; ++i)
	{
		(*this)[i] = '0';  // ��������� ������� ������.
	}
}

BitovayaStroka::~BitovayaStroka()
{
	// ������������ ���������� ���������� �������������.
	// ������� ���������� ���������� �������, � ����� ��������.
}

BitovayaStroka operator|(const BitovayaStroka& bit1, const BitovayaStroka& bit2)
{
	int dlina1 = bit1.dlina_stroki(),  // ����� ������ ������� ������.
		i = dlina1 - 1,  // ������� ��� ������ ������� ������.
		dlina2 = bit2.dlina_stroki(),  // ����� ������ ������� ������.
		j = dlina2 - 1,  // ������� ��� ������ ������� ������.
		dlina = dlina1 >= dlina2 ? dlina1 : dlina2,  // �������������� �����.
		k = dlina - 1;  // ������� ��� �������������� ������� ������.
	char ch1, ch2;
	
    BitovayaStroka vr(dlina);  // �������� ��������� ������� ������.

	while (k >= 0)
	{
		ch1 = i >= 0 ? bit1.simvoly[i--] : '0';
		ch2 = j >= 0 ? bit2.simvoly[j--] : '0';
		vr[k--] = (ch1 == '1' || ch2 == '1') ? '1' : '0';
	}
	
	return vr;
}

// ��������������� ��������� ��������������� >>:
// (����� ����� ����� ���� ������������ ������ ������ �������� � cin)
std::istream& operator>>(std::istream& stream, BitovayaStroka& stroka)
{
	stream >> stroka.simvoly;
	stroka.fix();
	return stream;
}
