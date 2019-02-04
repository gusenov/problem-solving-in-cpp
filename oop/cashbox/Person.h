#ifndef PERSON_H
#define PERSON_H

#define STR_LEN 20

// Определение класса Person:
class Person
{
	public:  // открытые поля:
		// Конструктор без параметров, устанавливающий значения свойство по умолчанию:
		Person();
		
		// Конструктор с 4 параметрами строка, строка, строка, число, 
		// для инициализации полей (имя, фамилия, отчество, возраст) класса:
		Person(const char* firstName, const char* lastName, const char* patronymic, const int age);
		
		~Person();
		
		
		// Метод для установки возраста персоны, с проверкой на правильность ввода ( возраст >= 0 и <= 200 ):
		bool setAge(int age);
		
		// Метод для установки имени персоны, проверять длину строки:
		bool setFirstName(const char* firstName);
		
		// Метод для установки фамилии персоны, проверять длину строки:
		bool setLastName(const char* lastName);
		
		// Метод для установки отчества персоны, проверять длину строки:
		bool setPatronymic(const char* patronymic);
		
		
		// Метод для получения возраста персоны:
		int getAge();
		
		// Метод для получения имени персоны:
		const char* getFirstName();
		
		// Метод для получения фамилии персоны:
		const char* getLastName();
		
		// Метод для получения отчества персоны:
		const char* getPatronymic();
		
		
		// Метод вывода информации о персоне на экран:
		print();
		
	private:  // закрытые поля:
		char firstName[STR_LEN];  // имя	- строка ( STR_LEN символов ).
		char lastName[STR_LEN];  // фамилия - строка ( STR_LEN символов ).
		char patronymic[STR_LEN];  // отчество - строка ( STR_LEN символов ).
		int age;  // возраст - целое число.
		
		static bool checkStrLen(const char* s);
		static int strLen(const char* s);
		static void strCopy(char* const dest, const char* src);
};

#endif
