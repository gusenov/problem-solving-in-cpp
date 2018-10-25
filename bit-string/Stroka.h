#ifndef STROKA_H
#define STROKA_H

#include <fstream>  // библиотека для работы с файлами.

// Класс СТРОКА, реализующий текстовую строку:
class Stroka
{
	// Дружественные функции:
	friend std::ostream& operator<<(std::ostream& stream, Stroka& stroka);
	friend std::istream& operator>>(std::istream& stream, Stroka& stroka);
	
	public:
		// Конструктор по умолчанию:
		Stroka();
		
		// Конструктор по нуль-терминированной инициализирующей строке:
		Stroka(const char* in_stroka);  // in_stroka - это инициализирующая строка.
		
		// Существует мнемоническое правило, позволяющее легко запомнить, к чему относится const. 
		// Надо провести черту через "*", 
		// если const слева, то оно относится к значению данных; 
		// если справа — к значению указателя.
		
		// Явный конструктор копирования:
		Stroka(const Stroka& stroka);
		// const означает, что через переменную stroka нельзя изменить объект.
		
		// Функция для покирования kol элементов в строку stroka1 из строки stroka2:
		static void kopir(char* const stroka1, char* const stroka2, int kol);
		
		// Конструктор по длине строки:
		Stroka(const int dlina);
		
		~Stroka();
		
		// Определение длины:
		int dlina_stroki() const;
		static int dlina(const char* stroka);
		
		// Операторы могут быть перегружены как функции-члены класса.
		// Левым аргументом оператора всегда выступает объект *this. 
		// Операторы = -> [] () могут быть перегружены только как методы (функции-члены), 
		// но не как функции.
		
		// Переопределение оператора присваивания = (равно):
		Stroka& operator=(const char* in_stroka);
		Stroka& operator=(const Stroka& stroka);
		
		// Операция конкатенации двух строк:
		Stroka operator+(const Stroka& stroka);
		
		// Переопределение оператора индексации (нач. с нуля):
		char& operator[](int nomer);
		
		// Функция для сравнения строк:
		static int sr(const Stroka& stroka1, const Stroka& stroka2);
		
	protected:
		// Цепочка символов переменной длины:
		char* simvoly;
		
		int razmer;
};

// Операторы могут быть перегружены и как отдельные функции.

// Операции сравнения двух строк:
bool operator==(const Stroka& stroka1, const Stroka& stroka2);
bool operator!=(const Stroka& stroka1, const Stroka& stroka2);
bool operator<(const Stroka& stroka1, const Stroka& stroka2);
bool operator<=(const Stroka& stroka1, const Stroka& stroka2);
bool operator>(const Stroka& stroka1, const Stroka& stroka2);
bool operator>=(const Stroka& stroka1, const Stroka& stroka2);

#endif
