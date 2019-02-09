// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tset.cpp - Copyright (c) ������� �.�. 04.10.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// ��������� - ���������� ����� ������� ����

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
}

// ����������� �����������
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

// ����������� �������������� ����
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const // �������� ����. �-�� ��-���
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // ������� ���������?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // ��������� �������� ���������
{
	if (Elem >= MaxPower) throw "Insert non existing element!";
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // ���������� �������� ���������
{
	BitField.ClrBit(Elem);
}

// ���������-������������� ��������

TSet& TSet::operator=(const TSet &s) // ������������
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // ���������
{
	return MaxPower != s.MaxPower ? 0 : BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // ���������
{
	return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // �����������
{
	TSet result(BitField | s.BitField);
	return result;
}

TSet TSet::operator+(const int Elem) // ����������� � ���������
{
	TSet result(*this);
	result.InsElem(Elem);
	return result;
}

TSet TSet::operator-(const int Elem) // �������� � ���������
{
	TSet result(*this);
	result.DelElem(Elem);
	return result;
}

TSet TSet::operator*(const TSet &s) // �����������
{
	TSet result(BitField & s.BitField);
	return result;
}

TSet TSet::operator~(void) // ����������
{
	TSet result(~BitField);
	return result;
}

// ���������� �����/������

istream &operator>>(istream &istr, TSet &s) // ����
{
	int n;
	while (istr >> n) {
		s.InsElem(n);
	}
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // �����
{
	for (int n = 0; n < s.MaxPower; ++n) {
		if (s.IsMember(n)) ostr << n << ' ';
	}
	return ostr;
}

