// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len <= 0) throw "Create BitField with negative length!";

	BitLen = len;
	MemLen = BitLen / 8 + (BitLen % 8 ? 1 : 0);
	pMem = new TELEM[MemLen];
	for (int n = 0; n < MemLen; ++n)
		pMem[n] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int n = 0; n < MemLen; ++n)
		pMem[n] = bf.pMem[n];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n / 8;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (n % 8);
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n < 0) throw "Set bit with negative index!";
	else if (n >= BitLen) throw "Set bit with too large index!";

	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n < 0) throw "Clear bit with negative index!";
	else if (n >= BitLen) throw "Clear bit with too large index!";

	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n < 0) throw "Get bit with negative index!";
	else if (n >= BitLen) throw "Get bit with too large index!";

	return (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n % 8);

	// Пример, n = 3:
	//
	// 76543210     № бита
	//
	// 01001010     pMem[GetMemIndex(n)]
	// 00001000     GetMemMask(n)
	//
	// 00001000     pMem[GetMemIndex(n)] & GetMemMask(n)
	//
	// >>>00001000  (pMem[GetMemIndex(n)] & GetMemMask(n)) >> (n % 8)
	// 00000001XXX
	//
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	TBitField tmp(bf);
	tmp.BitLen = BitLen;
	tmp.MemLen = MemLen;

	BitLen = bf.BitLen;
	MemLen = bf.MemLen;

	TELEM *pMemTmp = pMem;
	pMem = tmp.pMem;
	tmp.pMem = pMemTmp;

	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	for (int i = 0; i < BitLen && i < bf.BitLen; ++i)
	if (GetBit(i) != bf.GetBit(i)) return 0;

	if (BitLen > bf.BitLen) {
		for (int i = bf.BitLen; i < BitLen; ++i)
		if (GetBit(i) != 0) return 0;
	}

	else if (bf.BitLen > BitLen) {
		for (int i = BitLen; i < bf.BitLen; ++i)
		if (bf.GetBit(i) != 0) return 0;
	}

	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField result(BitLen > bf.BitLen ? BitLen : bf.BitLen);

	for (int i = 0; i < BitLen && i < bf.BitLen; ++i)
	if (GetBit(i) || bf.GetBit(i)) result.SetBit(i);

	if (BitLen > bf.BitLen) {
		for (int i = bf.BitLen; i < BitLen; ++i)
		if (GetBit(i)) result.SetBit(i); else result.ClrBit(i);

	}
	else if (bf.BitLen > BitLen) {
		for (int i = BitLen; i < bf.BitLen; ++i)
		if (bf.GetBit(i)) result.SetBit(i); else result.ClrBit(i);
	}

	return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField result(BitLen > bf.BitLen ? BitLen : bf.BitLen);

	for (int i = 0; i < BitLen && i < bf.BitLen; ++i)
	if (GetBit(i) && bf.GetBit(i)) result.SetBit(i);

	if (BitLen > bf.BitLen)
	for (int i = bf.BitLen; i < BitLen; ++i) result.ClrBit(i);

	else if (bf.BitLen > BitLen)
	for (int i = BitLen; i < bf.BitLen; ++i) result.ClrBit(i);

	return result;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField result(BitLen);
	for (int i = 0; i < result.BitLen; ++i)
	if (GetBit(i)) result.ClrBit(i); else result.SetBit(i);
	return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	char ch;
	istr.get(ch);
	int n = 0;
	while (!istr.eof()) {
		switch (ch) {
		case '1': bf.SetBit(n); break;
		case '0': bf.ClrBit(n); break;
		default: break;
		}
		++n;
		istr.get(ch);
	}
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	for (int n = 0; n < bf.BitLen; ++n)
		ostr << bf.GetBit(n) ? '1' : '0';
	return ostr;
}

