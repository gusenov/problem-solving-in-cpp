// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <iostream>  // ввод/вывод.
#include <cmath>

using namespace std;

class Expression {
	double x, y, z, gamma;
public:	
	void set(double x, double y, double z);  // метод установки начальных значений.
	void print(void);  // метод печати.
	void run();  // метод, решающий поставленную задачу.
};

// Функция инициализации:
void Expression::set(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

// Функция вывода результатов:
void Expression::print(void) {
	cout << this->gamma << endl;
}

void Expression::run(void) {
	this->gamma = 5.0 * atan(x) - (1.0/4.0) * acos(x) * ( (x + 3 * fabs(x - y) + pow(x, 2.0)) / (fabs(x - y) * z + pow(x, 2.0)) );
}

int main() {
	// Статический способ создания объектов:
	Expression stat;

	stat.set(0.1722, 6.33, 3.25e-4);  // прямой вызов.
	stat.run();  // прямой вызов.
	stat.print();  // прямой вызов.

	// Операция косвенной адресации является унарной, обозначается знаком * 
	// и ее операндом может быть только адресное выражение, 
	// т.е. выражение, значением которого является адрес памяти. 
	// Операция косвенной адресации записывается в виде: 
	// *<адресное_выражение>

	Expression *ptr = &stat;

	(*ptr).set(0.1722, 6.33, 3.25e-4);  // косвенный вызов.
	(*ptr).run();  // косвенный вызов.
	(*ptr).print();  // косвенный вызов.
	
	// Динамический способ создания объектов:
	Expression *dyn = new Expression();
	
	(*dyn).set(0.1722, 6.33, 3.25e-4);  // косвенный вызов.
	(*dyn).run();  // косвенный вызов.
	(*dyn).print();  // косвенный вызов.
	
	Expression &ref = *dyn;
	
	ref.set(0.1722, 6.33, 3.25e-4);  // прямой вызов.
	ref.run();  // прямой вызов.
	ref.print();  // прямой вызов.
	
	delete dyn;
}

