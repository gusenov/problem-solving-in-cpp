#include "Person.h"
#include <iostream>

using namespace std;

// ����������� ��� ����������, ��������������� �������� �������� �� ���������:
Person::Person()
{
}

// ����������� � 4 ����������� ������, ������, ������, �����, 
// ��� ������������� ����� (���, �������, ��������, �������) ������:
Person::Person(const char* firstName, const char* lastName, const char* patronymic, int age)
// ���������� ������������� �������, ����������� ����� ���������, � ���� ��������� const. 
// ���� �������� ����� ����� "*", ���� const �����, �� ��� ��������� � �������� ������; ���� ������ � � �������� ���������.
{
	Person::strCopy(this->firstName, firstName);
	Person::strCopy(this->lastName, lastName);
	Person::strCopy(this->patronymic, patronymic);
	this->age = age;
}

Person::~Person()
{
}


// ����� ��� ��������� �������� �������, � ��������� �� ������������ ����� ( ������� >= 0 � <= 200 ):
bool Person::setAge(int age)
{
	if (age >= 0 && age <= 200) {
		this->age = age;
		return true;
	}
	
	return false;
}

// ����� ��� ��������� ����� �������, ��������� ����� ������:
bool Person::setFirstName(const char* firstName)
{
	if (checkStrLen(firstName) < STR_LEN) {
		Person::strCopy(this->firstName, firstName);
	}
	
	return false;
}

// ����� ��� ��������� ������� �������, ��������� ����� ������:
bool Person::setLastName(const char* lastName)
{
	if (checkStrLen(lastName)) {
		Person::strCopy(this->lastName, lastName);
	}
	
	return false;
}

// ����� ��� ��������� �������� �������, ��������� ����� ������:
bool Person::setPatronymic(const char* patronymic)
{
	if (checkStrLen(patronymic)) {
		Person::strCopy(this->patronymic, patronymic);
	}
	
	return false;
}


// ����� ��� ��������� �������� �������:
int Person::getAge()
{
	return this->age;
}

// ����� ��� ��������� ����� �������:
const char* Person::getFirstName()
{
	return this->firstName;
}

// ����� ��� ��������� ������� �������:
const char* Person::getLastName()
{
	return this->lastName;
}

// ����� ��� ��������� �������� �������:
const char* Person::getPatronymic()
{
	return this->patronymic;
}


// ����� ������ ���������� � ������� �� �����:
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
	
	cout << "������: ����� ������ ����������� ����. ����������!\n";
	return false;
}

// ����������� �������, ������� ���������� ����� ������.
// ��� �������� ����� ����������� ������ �������.
// ����-������ ������ � ����� ������ �� ���������.
// ������ ������ ������������ ����-��������.
int Person::strLen(const char* str)
{
    const char* ptr = str;  // ��������� �� ������ ������.
    
    if (ptr == 0) { return 0; }
    
    // �������� �� ����� ����-��������������� ������.
    // ������ ������ ��������� ������ ������������� ����������� ����-������.
    // ����-������ - ��� (NUL �� ���� ASCII, �� ��������� 0x00).
    
    while (*ptr != '\0') ptr++;
    
    return ptr - str;
    
    /* ������:
    
     0   1   2   3   4   5   6  <- ������ � ����.
	 1   2   3   4   5   6   7  <- ������ � �������.
    425 426 427 428 429 430 431 <- ����� � ������.
	 c   �   �   �   �   �   0
     
    str = 425
    ptr = 431
    strLen = ptr - str = 431 - 425 = 6
    
    */
}

void Person::strCopy(char* const dest, const char* src)
{
	// ����� ���������� ������:
	int srcStrLen = Person::strLen(src);
	
	int i;
	
	// ��������� ��� ����� � ������-��������, ����� ����������, 
	// �.�. �� ���� ����� ����� ������ ����-������.
	// ����� ��������� ����� ���������� ������.
	for (i = 0; i < STR_LEN - 1 && i < srcStrLen; ++i)
		dest[i] = src[i];
	
	// � ����� ������ ������������� ����-������:
	dest[i] = '\0';
}



