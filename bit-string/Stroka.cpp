#include "Stroka.h"

// Конструктор по умолчанию:
Stroka::Stroka():
	razmer(0),
	simvoly(0)
{
}

// Конструктор по нуль-терминированной инициализирующей строке:
Stroka::Stroka(const char* in_stroka) :
	razmer(Stroka::dlina(in_stroka) + 1)  // +1 для нуль-символа в конце.
{
	simvoly = new char[razmer];
	char* ptr = this->simvoly;

	while (*ptr++ = *in_stroka++);
	
	// При использовании операции постинкремента значение переменной сначала используется в выражении, 
	// а потом увеличивается на 1.
	
	// По другому предыдущую строку можно переписать следующим образом:
	/*
	
	*ptr = *in_stroka
	while (*ptr)
	{
		ptr++;
		in_stroka++;
		*ptr = *in_stroka;
	}
	
	*/
}

// Явный конструктор копирования.
// Существует четыре случая вызова конструктора копирования:
//  - когда объект является возвращаемым значением;
//  - когда объект передается (функции) по значению в качестве аргумента;
//  - когда объект конструируется на основе другого объекта (того же класса);
//  - когда компилятор генерирует временный объект (как в первом и втором случаях выше; как явное преобразование и т. д.).
Stroka::Stroka(const Stroka& stroka)
{
	this->razmer = stroka.razmer;
	this->simvoly = new char[this->razmer];
	if (this->simvoly != 0) {
		kopir(this->simvoly, stroka.simvoly, this->razmer);
	}
}

// Функция для покирования kol элементов в строку stroka1 из строки stroka2:
void Stroka::kopir(char* const stroka1, char* const stroka2, int kol)
{
	for (int i = 0; i < kol; ++i)
	{
		stroka1[i] = stroka2[i];
	}
}

// Конструктор по длине строки:
Stroka::Stroka(const int dlina):
	razmer(dlina + 1)  // +1 для нуль-символа в конце.
{
	simvoly = new char[razmer];
	
	*this->simvoly = '\0';
	// У разыменования (*) приоритет ниже, чем у выбора по указателю (->).
	
	for (int i = 1; i <= dlina; ++i)
	{
		this->simvoly[i] = '\0';  // обнуление строки.
	}
}

Stroka::~Stroka()
{
	if (this->simvoly != 0) {
		delete[] this->simvoly;
	}
}


int Stroka::dlina_stroki() const
{    
    return Stroka::dlina(this->simvoly);
}

int Stroka::dlina(const char* stroka)
{
    const char* ptr = stroka;  // указатель на начало строки.
    
    if (ptr == 0)
    {
    	return 0;
	}
    
    // Движемся до конца нуль-терминированной строки.
    // Концом строки считается первый встретившийся специальный нуль-символ.
    // Нуль-символ - это (NUL из кода ASCII, со значением 0x00).
    
    while (*ptr != '\0') ptr++;
    
    return ptr - stroka;
}

// Переопределение оператора присваивания = (равно):

Stroka& Stroka::operator=(const char* in_stroka)
{
	Stroka vr(in_stroka);  // создание временной строки.
	
	// Обмен значений:
	char *ptr = this->simvoly;
	this->simvoly = vr.simvoly;
	vr.simvoly = ptr;
	
	int razmer = this->razmer;
	this->razmer = vr.razmer;
	vr.razmer = razmer;
	
	return *this;
}

Stroka& Stroka::operator=(const Stroka& stroka)
{
	Stroka vr(stroka.simvoly);  // создание временной строки.
	
	// Обмен значений:
	char *ptr = this->simvoly;
	this->simvoly = vr.simvoly;
	vr.simvoly = ptr;
	
	int razmer = this->razmer;
	this->razmer = vr.razmer;
	vr.razmer = razmer;
	
	return *this;
}

// Операция конкатенации двух строк:
Stroka Stroka::operator+(const Stroka& stroka)
{
	int dlina1 = this->dlina_stroki(),
		dlina2 = stroka.dlina_stroki();
	
    Stroka vr(dlina1 + dlina2);  // создание временной строки.
    
    for (int i = 0; i < dlina1; i++) {
    	vr.simvoly[i] = this->simvoly[i];
	}

    for (int j = 0; j < dlina2; j++) {
    	vr.simvoly[dlina1 + j] = stroka.simvoly[j];
	}
	
    return vr;
}

// Переопределение оператора индексации (нач. с нуля):

char& Stroka::operator[](int nomer)
{
	return this->simvoly[nomer];
}

// Функция для сравнения строк:
int Stroka::sr(const Stroka& stroka1, const Stroka& stroka2)
{
    int i = 0;
    while ( (stroka1.simvoly[i] != '\0') 
		||  (stroka2.simvoly[i] != '\0') )
    {
        if (stroka1.simvoly[i] > stroka2.simvoly[i])
        {
        	// Первый символ, который не соответствует
        	// имеет большее значение в stroka1, чем в stroka2.
        	return 1;
		}
        
		if (stroka1.simvoly[i] < stroka2.simvoly[i])
		{
        	// Первый символ, который не соответствует
        	// имеет меньшее значение в stroka1, чем в stroka2.
			return -1;
		}

        ++i;
    }
    return 0;  // обе строки равны.
}

// Операции сравнения двух строк:

bool operator==(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) == 0;
}

bool operator!=(const Stroka& stroka1, const Stroka& stroka2)
{
	return !(stroka1 == stroka2);
}

bool operator<(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) < 0;
}

bool operator<=(const Stroka& stroka1, const Stroka& stroka2)
{
	return (stroka1 == stroka2) || (stroka1 < stroka2);
}

bool operator>(const Stroka& stroka1, const Stroka& stroka2)
{
	return Stroka::sr(stroka1, stroka2) > 0;
}

bool operator>=(const Stroka& stroka1, const Stroka& stroka2)
{
	return (stroka1 == stroka2) || (stroka1 > stroka2);
}

// Переопределение оператора перенаправления <<:
// (нужно чтобы можно было использовать объект строки например с cout)
std::ostream& operator<<(std::ostream& stream, Stroka& stroka) 
{
	stream << stroka.simvoly;
	return stream;
}

// Переопределение оператора перенаправления >>:
// (нужно чтобы можно было использовать объект строки например с cin)
std::istream& operator>>(std::istream& stream, Stroka& stroka)
{
	stream >> stroka.simvoly;
	return stream;
}

