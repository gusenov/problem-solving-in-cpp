#include "Person.h"
#include <iostream>

using namespace std;

// Конструктор без параметров, устанавливающий значения свойство по умолчанию:
Person::Person()
{
}

// Конструктор с 4 параметрами строка, строка, строка, число, 
// для инициализации полей (имя, фамилия, отчество, возраст) класса:
Person::Person(const char* firstName, const char* lastName, const char* patronymic, int age)
// Существует мнемоническое правило, позволяющее легко запомнить, к чему относится const. 
// Надо провести черту через "*", если const слева, то оно относится к значению данных; если справа — к значению указателя.
{
	Person::strCopy(this->firstName, firstName);
	Person::strCopy(this->lastName, lastName);
	Person::strCopy(this->patronymic, patronymic);
	this->age = age;
}

Person::~Person()
{
}


// Метод для установки возраста персоны, с проверкой на правильность ввода ( возраст >= 0 и <= 200 ):
bool Person::setAge(int age)
{
	if (age >= 0 && age <= 200) {
		this->age = age;
		return true;
	}
	
	return false;
}

// Метод для установки имени персоны, проверять длину строки:
bool Person::setFirstName(const char* firstName)
{
	if (checkStrLen(firstName) < STR_LEN) {
		Person::strCopy(this->firstName, firstName);
	}
	
	return false;
}

// Метод для установки фамилии персоны, проверять длину строки:
bool Person::setLastName(const char* lastName)
{
	if (checkStrLen(lastName)) {
		Person::strCopy(this->lastName, lastName);
	}
	
	return false;
}

// Метод для установки отчества персоны, проверять длину строки:
bool Person::setPatronymic(const char* patronymic)
{
	if (checkStrLen(patronymic)) {
		Person::strCopy(this->patronymic, patronymic);
	}
	
	return false;
}


// Метод для получения возраста персоны:
int Person::getAge()
{
	return this->age;
}

// Метод для получения имени персоны:
const char* Person::getFirstName()
{
	return this->firstName;
}

// Метод для получения фамилии персоны:
const char* Person::getLastName()
{
	return this->lastName;
}

// Метод для получения отчества персоны:
const char* Person::getPatronymic()
{
	return this->patronymic;
}


// Метод вывода информации о персоне на экран:
Person::print()
{
	cout << this->lastName << " " 
	     << this->firstName << " " 
		 << this->patronymic;
}
		
		
bool Person::checkStrLen(const char* s) {
	if (Person::strLen(s) < STR_LEN) {
		return true;
	}
	
	cout << "ОШИБКА: Длина строки превосходит макс. допустимую!\n";
	return false;
}

// Статическая функция, которая возвращает длину строки.
// При подсчёте длины учитываются только символы.
// Нуль-символ символ в конце строки не считается.
// Строка должна оканчиваться нуль-символом.
int Person::strLen(const char* str)
{
    const char* ptr = str;  // указатель на начало строки.
    
    if (ptr == 0) { return 0; }
    
    // Движемся до конца нуль-терминированной строки.
    // Концом строки считается первый встретившийся специальный нуль-символ.
    // Нуль-символ - это (NUL из кода ASCII, со значением 0x00).
    
    while (*ptr != '\0') ptr++;
    
    return ptr - str;
    
    /* Пример:
    
     0   1   2   3   4   5   6  <- индекс с нуля.
	 1   2   3   4   5   6   7  <- индекс с единицы.
    425 426 427 428 429 430 431 <- адрес в памяти.
	 c   т   р   о   к   а   0
     
    str = 425
    ptr = 431
    strLen = ptr - str = 431 - 425 = 6
    
    */
}

void Person::strCopy(char* const dest, const char* src)
{
	// Длина копируемой строки:
	int srcStrLen = Person::strLen(src);
	
	int i;
	
	// Заполняем все места в строке-приёмнике, кроме последнего, 
	// т.к. на этом месте будет стоять нуль-символ.
	// Также учитываем длину копируемой строки.
	for (i = 0; i < STR_LEN - 1 && i < srcStrLen; ++i)
		dest[i] = src[i];
	
	// В конце строки устанавливаем нуль-символ:
	dest[i] = '\0';
}



