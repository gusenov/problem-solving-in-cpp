#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "nodelib.hpp"
#include "nodelib.cpp"  // нужно чтобы имплементировать шаблонный класс в .cpp файле.

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

// Функция изменяющая порядок размещения узлов в связном списке на обратный (от конца к началу):
template <class T>
void reverse(Node<T> * &head) {
	if (!head) {  // если список пуст:
		cout << "Список пуст!" << endl;
		return;
	}

	if (!head->NextNode()) {  // если в списке один элемент,
		return;  // то изменять порядок не имеет смысла.
	}

	Node<T> *reverseHead = 0;  // голова списка, который будет в обратном порядке.
	Node<T> *newLast = 0;  // указатель на последний узел в списке с обратным порядком.
	while (head->NextNode()) {  // обрабатываем список с исходным порядком:
	
		// Добираемся до последних двух узлов списка:
		Node<T> *penult = 0;
		Node<T> *last = head;
		while (last->NextNode()) {
			penult = last;
			last = last->NextNode();
		}  // по завершении цикла, penult - будет предпоследний узел, а last будет последний узел в списке.

		penult->DeleteAfter();  // удаляем последний узел, т.к. он будет участвовать в построении списка в обратном порядке.
		
		if (!reverseHead) {  // если голова списка в обратном порядке еще не назначена, то назначаем:
			reverseHead = newLast = last;
		} else {  // если голова уже есть, то добавляем удаленный ранее узел, после последнего узла в списке с обратным порядком:
			newLast->InsertAfter(last);
			newLast = last;
		}
	}
	newLast->InsertAfter(head);  // добавляем в список с обрытным порядком последний узел, который раньше был головой исходного списка.
	head = reverseHead;  // меняем голову списка.
}

void test1(void) {
	int M[] = { 1, 2, 3, 4, 5 };
	Node<int> *head = BuildNodeList(M, 5);	
	
	cyrillic();
	
	cout << "Исходный порядок: " << endl;
	PrintNodeList(head);
	
	reverse(head);
	
	cout << endl << endl << "Обратный порядок: " << endl;
	PrintNodeList(head);
	cout << endl;	
}

void test2(void) {
	int i, N;
	int *M;
	
	cout << "Введите с клавиатуры размер массива: ";
	cin >> N;
	M = new int[N];
	srand(time(NULL));  // автоматическая рандомизация генератора случайных чисел (чтобы всегда получать разные случайные числа).
	for (i = 0; i < N; i++ ) {
		M[i] = rand() % 10;  // генерация случайного целого числа в диапазоне [0; 10).
	}
	
	Node<int> *head = BuildNodeList(M, N);	
	
	cout << "Исходный порядок: " << endl;
	PrintNodeList(head);
	
	reverse(head);
	
	cout << endl << endl << "Обратный порядок: " << endl;
	PrintNodeList(head);
	cout << endl;	
	
	delete [] M;
}

int main(int argc, char** argv) {
	cyrillic();
	
	cout << "Тест № 1 (фиксированный)" << endl;
	test1();
	
	cout << endl << endl << "Тест № 2 (случайный)" << endl;
	test2();
	
	system("pause");
	return 0;
}

