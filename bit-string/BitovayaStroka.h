#ifndef BITOVAYASTROKA_H
#define BITOVAYASTROKA_H

#include "Stroka.h"

// Класс БИТОВАЯ_СТРОКА:
class BitovayaStroka : public Stroka
{
	// Дружественные функции:
	
	friend BitovayaStroka operator|(const BitovayaStroka& bit1, const BitovayaStroka& bit2);
	// const означает, что через переменную нельзя изменить объект.
	
	friend std::istream& operator>>(std::istream& stream, BitovayaStroka& bit);
	
	public:
		// Конструктор по нуль-терминированной инициализирующей строке:
		BitovayaStroka(const char* in_bit_stroka);
		
		// Явный конструктор копирования:
		BitovayaStroka(const BitovayaStroka& stroka);
		// const означает, что через переменную stroka нельзя изменить объект.
		
		// Конструктор по длине битовой строки:
		BitovayaStroka(const int dlina);
		
		~BitovayaStroka();
	protected:
		
		// Установить нулевое значение, 
		// если в составе инициализирующей строки встречены любые символы, 
		// отличные от допустимых.
		void fix();
};

#endif
