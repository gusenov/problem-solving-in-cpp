// Подключение заголовочных файлов
// из стандартной библиотеки:
#include <iostream>  // ввод/вывод.
#include <cmath>

using namespace std;

class X {
	friend void print(X *ptr);  // дружественная функция печати.
	friend void run(X *ptr);  // дружественная функция, решающая поставленную задачу.
	
	double *x, *y, *z, *gamma;  // компоненты-данные.

public:	
	X(double x, double y, double z);  // объявление конструктора с параметрами.
	~X();  // объявление деструктора.
};

// Конструктор для создания (операция new) и установки начальных значений:
X::X(double x, double y, double z) {
	this->x = new double;
	*(this->x) = x;
	
	this->y = new double;
	*(this->y) = y;
	
	this->z = new double;
	*(this->z) = z;
	
	this->gamma = new double;
}

// Описание деструктора:
X::~X() {
	delete this->x;
	delete this->y;
	delete this->z;
	delete this->gamma;
}

// Функция вывода результатов:
void print(X *ptr) {
	cout << *(ptr->gamma) << endl;
}

// Функция, решающая поставленную задачу:
void run(X *ptr) {
	*(ptr->gamma) = 5.0 * atan(*(ptr->x)) - (1.0/4.0) * acos(*(ptr->x)) * ( (*(ptr->x) + 3 * fabs(*(ptr->x) - *(ptr->y)) + pow(*(ptr->x), 2.0)) / (fabs(*(ptr->x) - *(ptr->y)) * *(ptr->z) + pow(*(ptr->x), 2.0)) );
}

int main() {
	double x = 0.1722, y = 6.33, z = 3.25e-4;
	if (-1 <= x && x <= 1 && z * fabs(x - y) + pow(x, 2) != 0) {  // ОДЗ.
		X *ptr = new X(x, y, z);
		run(ptr);
		print(ptr);
		delete ptr;
	} else {
		cout << "Выражение не определено!" << endl;
	}
}
