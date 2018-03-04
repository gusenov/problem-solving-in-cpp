#include <iostream>
#include <cstdlib>
#include <windows.h>

// ������� �� ���������:
void cyrillic() {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ � ��� ��������� �Lucida Console�. 
}


// ��������������� ���������� �������:

template <class T>
class Element;  // ������� ����������� ������.

template <class T>
class List2;  // ���������� ������.


// ���������, ������� ���������������� � ������� Element � List2:
template <typename T>
class Base {
public:
    virtual Element<T>* insertElementBeforeIndex(const T& elementValue, int i) = 0;  // ���������� �������� �� ��������.
    virtual Element<T>* deleteElementByValue(const T& elementValue) = 0;  // �������� �������� �� ��������.
    virtual Element<T>* searchElementByValue(const T& elementValue) = 0;  // ����� ��������.
    virtual void print() = 0;  // ����� �� �����.
};

// ������� ����������� ������:
template <class T>
class Element : public Base<T> {
	friend class List2<T>;  // ����� List2 ����� �������������, �.�. ��� ����� ������ � ���������� �� ��������.

private:
	Element<T>* previous;  // ���������� �������.
	Element<T>* next;  // ��������� �������.

public:
	T value;  // �������� ��������.
	
	// �����������:
	Element(const T& value, Element<T>* previous = 0, Element<T>* next = 0):
		value(value), previous(previous), next(next) {};
		
	// ����������.
	~Element(void) {}
	
	// ����������: � �������� ��������� ���������� ����� i, ������� ����������� �� i-��� �������� � ������.
	Element<T>* insertElementBeforeIndex(const T& elementValue, int i) {
		Element<T>* newElement = 0;  // ��������� �� ����� ������� ������.
		
		// ����� i-�� ��������, ����� ������� ����� �������� ����� �������:
		int elementIndex = 0;
		Element<T>* element = this;
		while (elementIndex != i && element->next) {
			element = element->next;
			elementIndex++;
		}
		
		if (i > elementIndex) {  // ���� i ������, ��� ���������� ��������� � ������, �� �������� � �����:
			newElement = new Element<T>(elementValue, element);  // ��������������� ������ �������� ������.
			element->next = newElement;
		
		} else {
			newElement = new Element<T>(elementValue, element->previous, element);  // ��������������� ������ �������� ������.
			if (element->previous)
				element->previous->next = newElement;
			element->previous = newElement;
		}
		
		return newElement;  // ������� ��������� �� ����� ������� ������.
	}
	
	// ��������: ���������� �������� ��������.
	Element<T>* deleteElementByValue(const T& elementValue) {
		// ��������� ������ ������� � ����� ���������.
		
		Element<T>* firstElement = this->searchElementByValue(elementValue);  // ����� ������� � �������� ���������.
		
		if (firstElement) {  // ���� ������� ������, �� ���������� ���������:
			if (firstElement->previous)
				firstElement->previous->next = firstElement->next;
			
			if (firstElement->next)
				firstElement->next->previous = firstElement->previous;
		}
		
		return firstElement;
	}
	
	// ����� �������� �� ��������:
	Element<T>* searchElementByValue(const T& elementValue) {
		Element<T>* element = this;
		do {
			if (element->value == elementValue)  // ���� �������� ���������, ��:
				return element;  // ������� ������.
		} while (element = element->next);
		return 0;  // ������� �� ������.
	}
	
	// ������ ��������� ������:
	void print() {
		Element<int>* head = this;
		while (head) {
			std::cout << head->value << " ";
			head = head->next;
		}
		std::cout << std::endl;
	}
};

// ���������� ������ � ��������� ����������, �������� � ������.
template <class T>
class List2 : public Base<T> {
	
private:
	Element<T>* head;  // ������ ������.

public:
	// �����������.
	List2(Element<T>* head = 0): head(head) {};
	
	// ����������.
	~List2(void) {
		std::cout << "���������� ����������� ������..." << std::endl;
		Element<int>* element = this->head;
		Element<int>* nextElement = 0;
		do {
			nextElement = element->next;
			std::cout << "���������� �������� �� ��������� " << element->value << std::endl;
			delete element;
			element = nextElement;
		} while (element);
	}
	
	// ���������� �������� � ������ ����� i-� ���������:
    Element<T>* insertElementBeforeIndex(const T& elementValue, int i) {
    	Element<T>* newElement;
		if (this->head) {
	    	newElement = this->head->insertElementBeforeIndex(elementValue, i);
	    	while (this->head->previous) {  // ����� ������ ��������� ��������:
	    		this->head = this->head->previous;
			}
		} else {  // ���� ������ ����, ��:
			this->head = newElement = new Element<T>(elementValue);  // ������� �������� ������� ������.
		}
		return newElement;  // ������� ������ �������� ������.
	}
    
    // �������� �� ������ ������� �������� � �������� ���������:
	Element<T>* deleteElementByValue(const T& elementValue) {
		if (this->head) {
			Element<T>* deletedElement = this->head->deleteElementByValue(elementValue);
			if (deletedElement == this->head) {  // ���������� ������ ��������� ��������:
				this->head = deletedElement->next;
			}
			return deletedElement;  // ���������� ��������� ������� ������.
		} else {
			return 0;
		}
	}
    
    // ����� �������� �� ��������:
	Element<T>* searchElementByValue(const T& elementValue) {
		return this->head->searchElementByValue(elementValue);
	}
    
    // ������ ����� ������ ��������� ������� � ������ ������:
	void print() {
		if (!this->head) {
			std::cout << "������ ����!" << std::endl;
			return;
		} else {
			std::cout << "�������� ������: ";
			this->head->print();
		}
	}
};

int main(int argc, char** argv) {
	cyrillic();
	std::cout << "���������� ������ � ��������� ����������, �������� � ������" << std::endl;
	
	List2<int>* myList2 = new List2<int>();
	
	std::cout << "����:" << std::endl;
	std::cout << "\t1) �������� ������� �� ��������� ����� i-� ��������� � ������" << std::endl;
	std::cout << "\t2) ������� ������ ������� �� ���������" << std::endl;
	std::cout << "\t3) ����� �������� �� ��������" << std::endl;
	std::cout << "\t4) ������ ������" << std::endl;
	std::cout << "\t5) �����" << std::endl;
		
	int choice, elementValue, i;
	while (1) {
		std::cout << "������� ����� ������ ���� -> "; std::cin >> choice;
		switch (choice) {
			case 1:
				std::cout << "������� �������� ������ �������� � ������� i -> ";
				std::cin >> elementValue >> i;
				myList2->insertElementBeforeIndex(elementValue, i);
				myList2->print();
				break;
			case 2:
				std::cout << "������� �������� ���������� �������� -> ";
				std::cin >> elementValue;
				myList2->deleteElementByValue(elementValue);
				myList2->print();
				break;
			case 3:
				std::cout << "������� �������� �������� �������� -> ";
				std::cin >> elementValue;
				if (myList2->searchElementByValue(elementValue)) {
					std::cout << "� ������ ���� ������� � ����� ���������." << std::endl;
				} else {
					std::cout << "������� � ����� ��������� �� ������!" << std::endl;
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
