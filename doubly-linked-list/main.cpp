#include <iostream>
#include <cstdlib>
#include <windows.h>

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


// Предварительное объявление классов:

template <class T>
class Element;  // элемент двусвязного списка.

template <class T>
class List2;  // двусвязный список.


// Интерфейс, который имплементируется в классах Element и List2:
template <typename T>
class Base {
public:
    virtual Element<T>* insertElementBeforeIndex(const T& elementValue, int i) = 0;  // добавление элемента по значению.
    virtual Element<T>* deleteElementByValue(const T& elementValue) = 0;  // удаление элемента по значению.
    virtual Element<T>* searchElementByValue(const T& elementValue) = 0;  // поиск элемента.
    virtual void print() = 0;  // вывод на экран.
};

// Элемент двусвязного списка:
template <class T>
class Element : public Base<T> {
	friend class List2<T>;  // класс List2 будет дружественным, т.к. ему нужен доступ к указателям на элементы.

private:
	Element<T>* previous;  // предыдущий элемент.
	Element<T>* next;  // следующий элемент.

public:
	T value;  // значение элемента.
	
	// Конструктор:
	Element(const T& value, Element<T>* previous = 0, Element<T>* next = 0):
		value(value), previous(previous), next(next) {};
		
	// Деструктор.
	~Element(void) {}
	
	// Добавление: в качестве аргумента передается число i, элемент добавляется до i-ого элемента в списке.
	Element<T>* insertElementBeforeIndex(const T& elementValue, int i) {
		Element<T>* newElement = 0;  // указатель на новый элемент списка.
		
		// Поиск i-го элемента, перед которым нужно вставить новый элемент:
		int elementIndex = 0;
		Element<T>* element = this;
		while (elementIndex != i && element->next) {
			element = element->next;
			elementIndex++;
		}
		
		if (i > elementIndex) {  // если i больше, чем количество элементов в списке, то добавить в конец:
			newElement = new Element<T>(elementValue, element);  // инстанцирование нового элемента списка.
			element->next = newElement;
		
		} else {
			newElement = new Element<T>(elementValue, element->previous, element);  // инстанцирование нового элемента списка.
			if (element->previous)
				element->previous->next = newElement;
			element->previous = newElement;
		}
		
		return newElement;  // возврат указателя на новый элемент списка.
	}
	
	// Удаление: передается значение элемента.
	Element<T>* deleteElementByValue(const T& elementValue) {
		// Удаляется первый элемент с таким значением.
		
		Element<T>* firstElement = this->searchElementByValue(elementValue);  // найти элемент с заданным значением.
		
		if (firstElement) {  // если элемент найден, то исправляем указатели:
			if (firstElement->previous)
				firstElement->previous->next = firstElement->next;
			
			if (firstElement->next)
				firstElement->next->previous = firstElement->previous;
		}
		
		return firstElement;
	}
	
	// Поиск элемента по значению:
	Element<T>* searchElementByValue(const T& elementValue) {
		Element<T>* element = this;
		do {
			if (element->value == elementValue)  // если значения совпадают, то:
				return element;  // элемент найден.
		} while (element = element->next);
		return 0;  // элемент не найден.
	}
	
	// Печать элементов списка:
	void print() {
		Element<int>* head = this;
		while (head) {
			std::cout << head->value << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
};

// Двусвязный список с функциями Добавления, Удаления и Поиска.
template <class T>
class List2 : public Base<T> {
	
private:
	Element<T>* head;  // голова списка.

public:
	// Конструктор.
	List2(Element<T>* head = 0): head(head) {};
	
	// Деструктор.
	~List2(void) {
		std::cout << "Деструкция двусвязного списка..." << std::endl;
		Element<int>* element = this->head;
		Element<int>* nextElement = 0;
		do {
			nextElement = element->next;
			std::cout << "Деструкция элемента со значением " << element->value << std::endl;
			delete element;
			element = nextElement;
		} while (element);
	}
	
	// Добавление элемента в список перед i-м элементом:
    Element<T>* insertElementBeforeIndex(const T& elementValue, int i) {
    	Element<T>* newElement;
		if (this->head) {
	    	newElement = this->head->insertElementBeforeIndex(elementValue, i);
	    	while (this->head->previous) {  // поиск нового головного элемента:
	    		this->head = this->head->previous;
			}
		} else {  // если список пуст, то:
			this->head = newElement = new Element<T>(elementValue);  // создаем головной элемент списка.
		}
		return newElement;  // возврат нового элемента списка.
	}
    
    // Удаление из списка первого элемента с заданным значением:
	Element<T>* deleteElementByValue(const T& elementValue) {
		if (this->head) {
			Element<T>* deletedElement = this->head->deleteElementByValue(elementValue);
			if (deletedElement == this->head) {  // назначение нового головного элемента:
				this->head = deletedElement->next;
			}
			return deletedElement;  // возвращаем удаленный элемент списка.
		} else {
			return 0;
		}
	}
    
    // Поиск элемента по значению:
	Element<T>* searchElementByValue(const T& elementValue) {
		return this->head->searchElementByValue(elementValue);
	}
    
    // Печать всего списка элементов начиная с головы списка:
	void print() {
		if (!this->head) {
			std::cout << "Список пуст!" << std::endl;
			return;
		} else {
			std::cout << "Элементы списка: ";
			this->head->print();
		}
	}
};

int main(int argc, char** argv) {
	cyrillic();
	std::cout << "Двусвязный список с функциями Добавления, Удаления и Поиска" << std::endl;
	
	List2<int>* myList2 = new List2<int>();
	
	std::cout << "Меню:" << std::endl;
	std::cout << "\t1) Добавить элемент со значением перед i-м элементом в списке" << std::endl;
	std::cout << "\t2) Удалить первый элемент со значением" << std::endl;
	std::cout << "\t3) Поиск элемента по значению" << std::endl;
	std::cout << "\t4) Печать списка" << std::endl;
	std::cout << "\t5) Выход" << std::endl;
		
	int choice, elementValue, i;
	while (1) {
		std::cout << "Введите номер пункта меню -> "; std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "Введите значение нового элемента и позицию i -> ";
				std::cin >> elementValue >> i;
				myList2->insertElementBeforeIndex(elementValue, i);
				myList2->print();
				break;
			case 2:
				std::cout << "Введите значение удаляемого элемента -> ";
				std::cin >> elementValue;
				myList2->deleteElementByValue(elementValue);
				myList2->print();
				break;
			case 3:
				std::cout << "Введите значение искомого элемента -> ";
				std::cin >> elementValue;
				if (myList2->searchElementByValue(elementValue)) {
					std::cout << "В списке есть элемент с таким значением." << std::endl;
				} else {
					std::cout << "Элемент с таким значением не найден!" << std::endl;
				}
				break;
			case 4:
				myList2->print();
				break;
			case 5:
				delete myList2;
				return EXIT_SUCCESS;
			default:
				continue;
		}
	}
	
	delete myList2;
	return EXIT_SUCCESS;
}
