#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "queuelib.hpp"

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

// Отладочный вывод:
void Queue::debugPrint(void) {
	for (int i = 0, j = front; i < count; i++) {
		cout << j << qlist[j++] << " ";
		if (j == MaxQSize) {
			j = 0;
		}
	}
	cout << endl;
}

// Метод, вставляющий элемент в начало очереди:
void Queue::QInsertFront(const QDataType &item) {
	if (count == MaxQSize) {  // если заполнена:
		cerr << "Queue full!" << endl;
		exit(1);  // завершить выполнение программы.
	
	} else if (this->QEmpty()) {  // если очередь пуста,
		this->QInsert(item);  // то можно воспользоваться методом  вставки элемента в конец очереди.
	
	} else {
		count++;  // увеличить count.
		
		front--;
		if (front == -1)
			front = MaxQSize - 1;

		qlist[front] = item;  // скопировать item в Qlist.
	}
}

int main(int argc, char** argv) {
	Queue q;  // очередь.
	char cmd;  // команда.
	int el;  // элемент очереди.
	
	cyrillic();
	
	cout << "Размер очереди: " << MaxQSize << endl;
	
	cout << "Команды: " << endl;
	cout << "\tf - вставить случайное число в начало;" << endl;
	cout << "\tb - вставить случайное число в конец;" << endl;
	cout << "\td - удалить из начала." << endl;
	
	srand(time(NULL));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).
	
	while (1) {
		cout << "Введите команду: ";
		cin >> cmd;
		el = (rand() % 10);  // генерация случайного целого числа в диапазоне [0; 10).
		switch (cmd) {
			case 'f':
				q.QInsertFront(el);
				break;
			case 'b':
				q.QInsert(el);
				break;
			case 'd':
				q.QDelete();
				break;
		}
		q.debugPrint();
	}
	
	system("pause");
	return 0;
}

