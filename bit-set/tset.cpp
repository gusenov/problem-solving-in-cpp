// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	MaxPower = mp;
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem >= MaxPower) throw "Insert non existing element!";
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	return MaxPower != s.MaxPower ? 0 : BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return !(*this == s);
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet result(BitField | s.BitField);
	return result;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet result(*this);
	result.InsElem(Elem);
	return result;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet result(*this);
	result.DelElem(Elem);
	return result;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet result(BitField & s.BitField);
	return result;
}

TSet TSet::operator~(void) // дополнение
{
	TSet result(~BitField);
	return result;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int n;
	while (istr >> n) {
		s.InsElem(n);
	}
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	for (int n = 0; n < s.MaxPower; ++n) {
		if (s.IsMember(n)) ostr << n << ' ';
	}
	return ostr;
}

