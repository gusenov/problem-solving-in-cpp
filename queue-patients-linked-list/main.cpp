#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

const int STRING_BUFFER_SIZE = 128;

// Структура содержащая информацию о пациенте:
typedef struct Patient {
	char surname[STRING_BUFFER_SIZE];     // фамилия.
	char name[STRING_BUFFER_SIZE];        // имя.
	char secondName[STRING_BUFFER_SIZE];  // отчество.
	int age;                              // возраст.
	char diagnosis[STRING_BUFFER_SIZE];   // диагноз.
} Data;

// Структура содержащая информацию об очереди:
struct Queue {
	Data data;
	struct Queue *next;
};


void cyrillic(void);

Queue* input_queue_from_file(void);
void output_queue_to_file(Queue*);

void print_queue_to_screen(Queue*);

Queue* push(Queue*, const Data);
Queue* pop(Queue**);

Queue* input_patient_to_queue(Queue* queue);
void print_patient(const Data&);

void search_by_place_in_queue(Queue*);
void search_by_diagnosis(Queue*);

Queue* delete_queue(Queue*);


// Переход на кириллицу:
void cyrillic(void) {
	// Эти строки нужны для правильного отображения кириллицы:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// Также надо изменить шрифт в консоли на Lucida Console.
	// Для замены шрифта кликаете правой кнопкой 
	// на надписи «Командная строка» окна консоли. 
	// В открывшемся меню выбираете «Свойства». 
	// В появившемся окне выбираете вкладку «Шрифт» 
	// и там выбираете «Lucida Console». 
}

// Печать пациента:
void print_patient(const Data& patient) {
	printf("%-16s %-16s %-16s %-8i %-16s\n"
		, patient.surname
		, patient.name
		, patient.secondName
		, patient.age
		, patient.diagnosis);
}

// Создание новой очереди:
Queue* push(Queue* previous, const Data data) {
	Queue* n = new Queue;
	n->data = data;
	n->next = NULL;
	
	if (previous) {
		previous->next = n;
	}
	
	return n;
}

// Извлечение пациента из начала из очереди:
Queue* pop(Queue** queue) {
	if (!queue) { cout << "Очередь пуста!" << endl; }
	Queue* result = *queue;
	*queue = result->next;
	return result;
}

// Очистка очереди:
Queue* delete_queue(Queue* queue) {
	// Освобождение памяти, выделенной для элементов очереди:
	Queue* current = queue;
	Queue* del = NULL;
	while (current) {
		del = current;
		current = current->next;
		delete del;
	}
	return NULL;
}

// Чтение данных из файла:
Queue* input_queue_from_file(void) {
	Queue* head = NULL;
	
	cout << "Введите имя файла, содержащего информацию о пациентах -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	// Считывание данных из файла и добавление их в очередь:
	FILE* f1 = fopen(fname, "r");
	if (f1 == NULL) {
		printf("Невозможно открыть файл '%s'!\n", fname);
		return NULL;
	}
	
	int z, cnt;
	fscanf(f1, "%i", &cnt);
	
	Queue* current = NULL;
	Data x;
	for (int i = 0; i < cnt; i++) {
		
		z = fscanf(f1, "%s%s%s%i%s\n"
			, &x.surname
			, &x.name
			, &x.secondName
			, &x.age
			, &x.diagnosis);
		
		current = push(current, x);
		if (i == 0) head = current;
	}
	
	fclose(f1);
	
	if (z == EOF) {
		printf("Не хватает данных в файле!\n");
		return delete_queue(head);
	}
	
	return head;
}

// Вывод данных в файл:
void output_queue_to_file(Queue* queue) {
	cout << "Введите имя файла, в который выводится информация обо всех пациентах в порядке очереди -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	FILE* f1 = fopen(fname, "w");
	if (f1 == NULL) {
		printf("Невозможно открыть файл '%s'!\n", fname);
		return;
	}
	
	int count = 0;
	Queue* next = queue;
	while (next) {
		count++;
		next = next->next;
	}
	
	fprintf(f1, "%d\n", count);
	
	// (сами пациенты при этом из очереди не извлекаются)
	if (count > 0) do {
		Data* x = &queue->data;
		fprintf(f1, "%s %s %s %i %s ", x->surname, x->name, x->secondName, x->age, x->diagnosis);
	} while (queue = queue->next);

	fclose(f1);
}

// Добавление в конец очереди:
Queue* input_patient_to_queue(Queue* queue) {	
	cout << "Введите данные о пациенте в формате:\nфамилия имя отчество возраст диагноз" << endl;
	
	Data x;
	scanf("%s%s%s%i%s", &x.surname, &x.name, &x.secondName, &x.age, &x.diagnosis);
	
	Queue* newNode = push(queue, x);
	
	return newNode;
}

// Просмотр очереди:
void print_queue_to_screen(Queue* queue) {
	if (!queue) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	cout << "Информация обо всех пациентах в порядке очереди:" << endl;
	// (сами пациенты при этом из очереди не извлекаются)
	do {
		print_patient(queue->data);
	} while (queue = queue->next);
}

// Поиск по месту в очереди:
void search_by_place_in_queue(Queue* patientQueue) {
	if (!patientQueue) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	cout << "Введите номер в очереди -> ";
	int no;
	cin >> no;
	
	cout << "Информация о пациенте на данном месте:" << endl;
	
	int found = 0;
	do {
		if (--no == 0) {
			print_patient(patientQueue->data);
			found = 1;
		}
	} while (patientQueue = patientQueue->next);
	
	if (found == 0) {
		printf("Ничего не найдено!\n");
	}
}

// Поиск по диагнозу:
void search_by_diagnosis(Queue* patientQueue) {
	if (!patientQueue) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	char b[STRING_BUFFER_SIZE];
	printf("Введите диагноз -> ");
	
	gets(b);
    b[strcspn(b, "\n")] = '\0';
    
    cout << "Информация обо всех пациентах с этим диагнозом с указанием места в очереди:" << endl;

	int found = 0;
	do {
		if (strcmp(patientQueue->data.diagnosis, b) == 0) {
			print_patient(patientQueue->data);
			found = 1;
		}
	} while (patientQueue = patientQueue->next);
	
	if (found == 0) {
		printf("Ничего не найдено!\n");
	}
}

// Показать меню для осуществления диалога с пользователем:
void showMenu(void) {
	cout << "Меню:" << endl;
	cout << "1) чтение данных из файла;" << endl;
	cout << "2) вывод данных в файл;" << endl;
	cout << "3) добавление в конец очереди;" << endl;
	cout << "4) извлечение из очереди;" << endl;
	cout << "5) просмотр очереди;" << endl;
	cout << "6) поиск по месту в очереди;" << endl;
	cout << "7) поиск по диагнозу;" << endl;
	cout << "8) очистка очереди;" << endl;
	cout << "9) завершение работы." << endl;
}

// Ввод пункта меню пользователем:
int selectMenuItem(void) {
	int userChoice;
	cout << "Введите номер пункта меню -> ";
	cin >> userChoice;
	fgetc(stdin);
	return userChoice;
}

// Главная функция:
int main(int argc, char** argv) {
	cyrillic();  // вкл. кириллицу.
	
	cout << "Программа для организации очереди пациентов." << endl;
	
	Queue* myQueue = NULL;
	Queue* tmp = NULL;
	
	showMenu();  // показать меню.
	int userChoice;
	while ((userChoice = selectMenuItem()) != 9) {
		switch(userChoice) {
		case 1:
			myQueue = delete_queue(myQueue);  // очистка очереди, если нужно.
			myQueue = input_queue_from_file();  // чтение данных из файла.
			break;
		case 2:
			output_queue_to_file(myQueue);  // вывод данных в файл.
			break;
		case 3:
			tmp = input_patient_to_queue(myQueue);  // добавление в конец очереди.
			if (!myQueue) myQueue = tmp;
			break;
		case 4:
			tmp = pop(&myQueue);
			cout << "Информация о пациенте:" << endl;
			print_patient(tmp->data);
			delete tmp;			
			break;
		case 5:
			print_queue_to_screen(myQueue);  // просмотр очереди.
			break;
		case 6:
			search_by_place_in_queue(myQueue);  // поиск по месту в очереди.
			break;
		case 7:
			search_by_diagnosis(myQueue);  // поиск по диагнозу.
			break;
		case 8:
			myQueue = delete_queue(myQueue);  // очистка очереди.
			break;
		default:
			break;
		}
	}
	
	// Завершение работы:
	delete_queue(myQueue);  // очистка очереди.
	
	system("pause");  // пауза перед выходом.
	return 0;
}


