#include <iostream>
#include <fstream>

#define DEFAULT_STRING_SIZE 255  // длина строки по умолчанию.
#define NEW_LINE '\n'

using namespace std;

// Пользовательский класс String:
class String {
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
	
	static long unsigned int string_length(const char *s);
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

String::String(long unsigned int sz): _str(new char[sz]) {
	this->_str[0] = '\0';
}

String::String(const char *str): _str(new char[String::string_length(str) + 1]) {
	String::string_copy(this->_str, str);
}

String::~String() {
	delete[] this->_str;
}

void String::Set() {
	
	char *ptr = this->_str;
	int c;
	while ( ((c = getchar()) != NEW_LINE) && (c != EOF)) {
		*ptr++ = c;
	}
	*ptr = '\0';
}

void String::print() {
	cout << this->_str << endl;
}

String& String::operator=(const String& s) {
	char *ptr = this->_str;
	String tmp(s._str);
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

ostream& operator<<(ostream& stream, String& ob) {
	stream << ob._str;
	return stream;
}

istream& operator>>(istream& stream, String& ob){
	stream >> ob._str;
	return stream;
}

int main(int argc, char** argv) {
	fstream fout("output.txt", ios::out);
	
	String S1;
	S1.Set();
	S1.print();
	fout << S1 << endl;  // вывод в файл исходной строки.
	
	S1.Run();
	String S2;
	S2 = S1;
	S2.print();
	fout << S2 << endl;  // вывод в файл преобразованной строки.

	fout.close();
	return 0;
}

