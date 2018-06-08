#include <iostream>  // подключаем стандартную библиотеку ввода/вывода.
#include <fstream>   // библиотека для работы с файлами.

// Определение констант:
#define DEFAULT_STRING_SIZE 255  // длина строки по умолчанию.
#define NEW_LINE '\n'

// Используем стандартное пространство имён.
// Чтобы например, писать просто cout вместо std::cout.
using namespace std;

// Объявление пользовательского класса String:
class String {
	// Дружественные функции:
	friend ostream& operator<<(ostream&, String&);  // перегрузка оператора вывода.
	friend istream& operator>>(istream&, String&);  // перегрузка оператора ввода.
	
public:
	String(long unsigned int sz = DEFAULT_STRING_SIZE);  // конструктор по-умолчанию.
	String(const char *str);  // конструктор для создания строк.
	
	~String();  // деструктор.
	
	void Set();  // метод ввода исходной строки.
	void print();  // метод печати.
	
	String& operator=(const String& s);  // перегруженная операция "=".
	
	char* Run();  // метод, выполняющий поставленную задачу.
	
private:
	char *_str;
	
	// Статический метод для определения длины строки:
	static long unsigned int string_length(const char *s);
	
	// Статический метод для копирования строки:
	static char* string_copy(char *dest, const char *src);
};

// Определение длины строки:
long unsigned int String::string_length(const char *s) {
    const char *p = s;  // указатель на начало строки.
    
    // Движемся до конца строки.
    // Концом строки считается первый встретившийся специальный нуль-символ.
    while (*p != '\0') p++;
    
    return (long unsigned int)(p - s);
}

// Копирование строки:
char* String::string_copy(char *dest, const char *src) {
	char *ptr = dest;
	while (*ptr++ = *src++);
	return dest;
}

// Конструктор с параметром задающим длину строки:
String::String(long unsigned int sz): _str(new char[sz]) {
	this->_str[0] = '\0';
}

// Конструктор с параметром через который передается строка для инициализации:
String::String(const char *str): _str(new char[String::string_length(str) + 1]) {
	String::string_copy(this->_str, str);
}

// Деструктор:
String::~String() {
	delete[] this->_str;
}

// Метод ввода строки с клавиатуры:
void String::Set() {
	
	char *ptr = this->_str;
	int c;
	while ( ((c = getchar()) != NEW_LINE) && (c != EOF)) {
		*ptr++ = c;
	}
	*ptr = '\0';
}

// Метод вывода строки:
void String::print() {
	cout << this->_str << endl;
}

// Переопределение оператора присваивания = (равно):
String& String::operator=(const String& s) {
	String tmp(s._str);  // создание временной строки.
	
	// Обмен значений:
	char *ptr = this->_str;
	this->_str = tmp._str;
	tmp._str = ptr;
	
	return *this;
}

char* String::Run() {
	long unsigned int len = String::string_length(this->_str);
	
	// Если длина L нечетная, то удаляется символ, стоящий посередине строки:
	if (len % 2 != 0) {
		for (int i = len / 2; i < len - 1; i++) {
			this->_str[i] = this->_str[i + 1];
		}
		this->_str[len - 1] = '\0';
	}
}

// Переопределение оператора перенаправления <<:
// (нужно чтобы можно было использовать объект строки например с cout)
ostream& operator<<(ostream& stream, String& ob) {
	stream << ob._str;
	return stream;
}

// Переопределение оператора перенаправления >>:
// (нужно чтобы можно было использовать объект строки например с cin)
istream& operator>>(istream& stream, String& ob){
	stream >> ob._str;
	return stream;
}

int main(int argc, char** argv) {
	fstream fout("output.txt", ios::out);  // открыть файл для записи.
	
	String S1;  // создание экземпляра строки.
	S1.Set();  // ввод строки.
	S1.print();  // вывод строки.
	fout << S1 << endl;  // вывод в файл исходной строки.
	
	S1.Run();  // удалить символ, стоящий посередине строки, если длина строки нечетная.
	String S2;  // создание экземпляра строки.
	S2 = S1;  // присваивание строки S1 строке S2.
	S2.print();  // вывод строки.
	fout << S2 << endl;  // вывод в файл преобразованной строки.

	fout.close();  // закрыть файл.
	return 0;
}

