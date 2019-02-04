#ifndef PERSON_H
#define PERSON_H

#define STR_LEN 20

// ����������� ������ Person:
class Person
{
	public:  // �������� ����:
		// ����������� ��� ����������, ��������������� �������� �������� �� ���������:
		Person();
		
		// ����������� � 4 ����������� ������, ������, ������, �����, 
		// ��� ������������� ����� (���, �������, ��������, �������) ������:
		Person(const char* firstName, const char* lastName, const char* patronymic, const int age);
		
		~Person();
		
		
		// ����� ��� ��������� �������� �������, � ��������� �� ������������ ����� ( ������� >= 0 � <= 200 ):
		bool setAge(int age);
		
		// ����� ��� ��������� ����� �������, ��������� ����� ������:
		bool setFirstName(const char* firstName);
		
		// ����� ��� ��������� ������� �������, ��������� ����� ������:
		bool setLastName(const char* lastName);
		
		// ����� ��� ��������� �������� �������, ��������� ����� ������:
		bool setPatronymic(const char* patronymic);
		
		
		// ����� ��� ��������� �������� �������:
		int getAge();
		
		// ����� ��� ��������� ����� �������:
		const char* getFirstName();
		
		// ����� ��� ��������� ������� �������:
		const char* getLastName();
		
		// ����� ��� ��������� �������� �������:
		const char* getPatronymic();
		
		
		// ����� ������ ���������� � ������� �� �����:
		print();
		
	private:  // �������� ����:
		char firstName[STR_LEN];  // ���	- ������ ( STR_LEN �������� ).
		char lastName[STR_LEN];  // ������� - ������ ( STR_LEN �������� ).
		char patronymic[STR_LEN];  // �������� - ������ ( STR_LEN �������� ).
		int age;  // ������� - ����� �����.
		
		static bool checkStrLen(const char* s);
		static int strLen(const char* s);
		static void strCopy(char* const dest, const char* src);
};

#endif
