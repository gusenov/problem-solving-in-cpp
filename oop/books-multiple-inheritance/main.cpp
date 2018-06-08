#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>  // нужно для функций SetConsoleOutputCP и SetConsoleCP.

using namespace std;

// Переход на кириллицу:
void cyrillic() {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» и там выбираете «Lucida Console». 
}

typedef unsigned short int ushort;
typedef unsigned long int ulong;

// Абстрактный базовый класс:
class Base
{
public:

	// Деструктор:
	virtual ~Base() {}
	// В языке программирования C++ деструктор полиморфного базового класса должен объявляться виртуальным. 
	// Только так обеспечивается корректное разрушение объекта производного класса через указатель на соответствующий базовый класс.
	
	// Виртуальная функция просмотра текущего состояния объекта:
	virtual void print(ostream& stream) = 0;
	// Виртуальная функция — это функция-член, которую предполагается переопределить в производных классах.
	// Базовый класс содержит функцию, объявленную как виртуальная, 
	// и производный класс определяет ту же функцию. 
	// Функция производного класса вызывается для объектов производного класса, 
	// даже если она вызывается с помощью указателя или ссылки на базовый класс. 	
};

// Книга:
class Book: public Base
{
	friend void run(Book& b);  // дружественная функция, решающая поставленную задачу.
	
public:
	
	// Конструктор:
	Book(string name, string author, string genre, ushort year, ushort pages, ulong printing, ushort printedPages):
		name(name), author(author), genre(genre), year(year), pages(pages), printing(printing), printedPages(printedPages)
	{
	}
	
	void print(ostream& stream)
	{
		stream << "\tназвание: " << name << endl;
		stream << "\tавтор: " << author << endl;
		stream << "\tжанр: " << genre << endl;
		stream << "\tгод: " << year << endl;
		stream << "\tстраниц: " << pages << endl;
		stream << "\tтираж: " << printing << endl;
		stream << "\tотпечатано листов: " << printedPages << endl;
	}
	
protected:

	string name;          // название.
	string author;        // автор.
	string genre;         // жанр.
	ushort year;          // год.
	ushort pages;         // страниц.
	ulong printing;       // тираж.
	ushort printedPages;  // отпечатано листов.
};

// Техническая книга:
class TechnicalBook: virtual public Book
{
public:

	// Конструктор:
	TechnicalBook(string name, string author, ushort year, ushort pages, ulong printing, ushort printedPages):
		Book(name, author, "технический", year, pages, printing, printedPages)
	{
	}
	
	// Деструктор:
	~TechnicalBook() {
	}
	
	void print(ostream& stream)
	{
		stream << "Техническая книга" << endl;
		Book::print(stream);
	}
};

// Энциклопедия:
class Encyclopedia: virtual public Book
{
public:

	// Конструктор:
	Encyclopedia(string name, string author, ushort year, ushort pages, ulong printing, ushort printedPages):
		Book(name, author, "энциклопедический", year, pages, printing, printedPages)
	{
	}

	// Деструктор:
	~Encyclopedia() {
	}
		
	void print(ostream& stream)
	{
		stream << "Энциклопедия" << endl;
		Book::print(stream);
	}
};

// Техническая энциклопедия:
class TechnicalEncyclopedia: public TechnicalBook, public Encyclopedia  // множественное наследование.
{
public:

	// Конструктор:
	TechnicalEncyclopedia(string name, string author, ushort year, ushort pages, ulong printing, ushort printedPages):
		TechnicalBook(name, author, year, pages, printing, printedPages),
		Encyclopedia(name, author, year, pages, printing, printedPages),
		Book(name, author, "технический, энциклопедический", year, pages, printing, printedPages)
	{
	}

	// Деструктор:
	~TechnicalEncyclopedia() {
	}
	
	void print(ostream& stream)
	{
		stream << "Техническая энциклопедия" << endl;
		Book::print(stream);
	}
};

void run(Book& b)
{
	ofstream fout;
	try
	{
		// Вывод информации об объектах в файл, используя стандартные файловые потоки:
		fout.open("books.txt", ios::out | ios::app);
		b.print(fout);
		fout << endl;
		fout.close();
	}
	catch (const std::ios_base::failure &err)
	{
	    if (fout.fail())
	    {
	        cerr << "\n\nСлучилось исключение при записи в файл:\n" << err.what() << std::endl;
	    }
	}
}

int main(int argc, char** argv)
{
	cyrillic();  // вкл. кириллицу.
	
	cout << "Добавить книгу из жанра:" << endl;
	cout << "1) Техническая книга" << endl;
	cout << "2) Энциклопедия" << endl;
	cout << "3) Техническая энциклопедия" << endl;
	cout << "4) Свой вариант" << endl;
	cout << "5) Выход" << endl;
	
	Book *b;
	
	int choice;
	bool flag = true;
	while (flag) {
		cout << "Введите Ваш выбор -> ";
		cin >> choice;
		
		if (choice == 5) break;
		
		cout << "Введите информацию о книге:" << endl;
		
		cout << "Название -> ";
		string name;
		cin.ignore();
		getline(cin, name);
		
		cout << "Автор -> ";
		string author;
		getline(cin, author);
		
		cout << "Год -> ";
		ushort year;
		cin >> year;
		
		cout << "Страниц -> ";
		ushort pages;
		cin >> pages;
		
		cout << "Тираж -> ";
		ulong printing;
		cin >> printing;
		
		cout << "Отпечатано листов -> ";
		ushort printedPages;
		cin >> printedPages;
		
		string genre;
		switch (choice) {
			case 1:
				b = new TechnicalBook(name, author, year, pages, printing, printedPages);
				break;
			case 2:
				b = new Encyclopedia(name, author, year, pages, printing, printedPages);
				break;
			case 3:
				b = new TechnicalEncyclopedia(name, author, year, pages, printing, printedPages);
				break;
			case 4:
				cout << "Жанр -> ";
				cin.ignore();
				getline(cin, genre);
				b = new Book(name, author, genre, year, pages, printing, printedPages);
				break;
			case 5:
			default:
				flag = false;
				break;
		}
		
		if (!flag) break;
		
		cout << endl << "Вы ввели следующую информацию:" << endl;
		b->print(cout);
		
		run(*b);
		
		delete b;
	}
	
	system("pause");
	return 0;
}

