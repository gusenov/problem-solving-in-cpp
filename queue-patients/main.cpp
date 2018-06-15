#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

const int STRING_BUFFER_SIZE = 128;
const int MAX_QUEUE_SIZE = 1024;

// Структура содержащая информацию о пациенте:
struct Patient {
	char surname[STRING_BUFFER_SIZE];     // фамилия.
	char name[STRING_BUFFER_SIZE];        // имя.
	char secondName[STRING_BUFFER_SIZE];  // отчество.
	int age;                              // возраст.
	char diagnosis[STRING_BUFFER_SIZE];   // диагноз.
};

// Структура содержащая информацию об очереди пациентов:
struct PatientQueue {
	struct Patient *list;  // массив очереди.
	int front;             // индекс первого элемента.
	int rear;              // индекс места вставки.
	int count;             // общее количество элементов.
	int max;               // максимальный размер очереди.
};

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

// Печать пациента:
void printPatient(const Patient& x) {
	printf("%-16s %-16s %-16s %-8i %-16s\n", x.surname, x.name, x.secondName, x.age, x.diagnosis);
}

// Создание новой очереди:
PatientQueue* newPatientQueue() {
	PatientQueue* resultQueue = new PatientQueue;
	resultQueue->max = MAX_QUEUE_SIZE;
	resultQueue->list = new struct Patient[resultQueue->max];
	resultQueue->count = resultQueue->front = resultQueue->rear = 0;
	return resultQueue;
}

// Очистка очереди:
PatientQueue* clearQueue(PatientQueue* patientQueue) {
	// Освобождение памяти, выделенной для элементов очереди:
	if (patientQueue) {
		delete [] patientQueue->list;
		patientQueue->front = patientQueue->rear = patientQueue->count = 0;
		delete patientQueue;
	}
	return 0;
}

// Чтение данных из файла:
PatientQueue* inputFromFile() {
	PatientQueue* resultQueue = newPatientQueue();
	
	cout << "Введите имя файла, содержащего информацию о пациентах -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	// Считывание данных из файла и добавление их в очередь:
	FILE* f1 = fopen(fname, "r");
	if (f1 == NULL) {
		printf("Невозможно открыть файл '%s'!\n", fname);
		return clearQueue(resultQueue);
	}
	
	int z;
	fscanf(f1, "%i", &resultQueue->count);
	
	if (resultQueue->count > resultQueue->max) {
		printf("В файле содержится больше элементов, чем может вместить очередь!\n");
		return clearQueue(resultQueue);
	}
	
	struct Patient* x = resultQueue->list;
	for (int i = 0; i < resultQueue->count; i++) {
		z = fscanf(f1, "%s%s%s%i%s\n", &x[i].surname, &x[i].name, &x[i].secondName, &x[i].age, &x[i].diagnosis);
		resultQueue->rear = (resultQueue->rear + 1) % resultQueue->max;
	}
	
	fclose(f1);
	
	if (z == EOF) {
		printf("Не хватает данных в файле!\n");
		return clearQueue(resultQueue);
	}
	
	return resultQueue;
}

// Вывод данных в файл:
void outputToFile(PatientQueue* patientQueue) {
	cout << "Введите имя файла, в который выводится информация обо всех пациентах в порядке очереди -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	FILE* f1 = fopen(fname, "w");
	if (f1 == NULL) {
		printf("Невозможно открыть файл '%s'!\n", fname);
		return;
	}
	
	fprintf(f1, "%d\n", patientQueue->count);
	
	// (сами пациенты при этом из очереди не извлекаются)
	int i = patientQueue->front, c= 0;
	do {
		struct Patient* x = &patientQueue->list[i];
		fprintf(f1, "%s %s %s %i %s ", x->surname, x->name, x->secondName, x->age, x->diagnosis);
		i = (i + 1) % patientQueue->max;
	} while (i != patientQueue->rear && ++c < patientQueue->count);

	fclose(f1);
}

// Добавление в конец очереди:
void addToEndOfQueue(PatientQueue* x) {
	if (x->count == x->max) {
		cout << "Очередь заполнена до предела!" << endl;
		return;
	}
	
	cout << "Введите данные о пациенте в формате:\nфамилия имя отчество возраст диагноз" << endl;
	int i = x->rear;
	scanf("%s%s%s%i%s", &x->list[i].surname, &x->list[i].name, &x->list[i].secondName, &x->list[i].age, &x->list[i].diagnosis);
	
	++x->count;
	x->rear = (x->rear + 1) % x->max;
}

// Извлечение пациента из начала из очереди:
void extractFromBeginningOfQueue(PatientQueue* patientQueue) {
	if (!patientQueue->count) {
		cout << "Очередь пуста!" << endl;
		return;
	}

	cout << "Информация о пациенте:" << endl;
	printPatient(patientQueue->list[patientQueue->front]);
	
	--patientQueue->count;
	patientQueue->front = (patientQueue->front + 1) % patientQueue->max;
}

// Просмотр очереди:
void showQueue(PatientQueue* patientQueue) {
	if (!patientQueue->count) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	cout << "Информация обо всех пациентах в порядке очереди:" << endl;
	// (сами пациенты при этом из очереди не извлекаются)
	int i = patientQueue->front, c= 0;
	do {
		printPatient(patientQueue->list[i]);
		i = (i + 1) % patientQueue->max;
	} while (i != patientQueue->rear && ++c < patientQueue->count);
}

// Поиск по месту в очереди:
void searchByPlaceInQueue(PatientQueue* x) {
	if (!x->count) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	cout << "Введите номер в очереди -> ";
	int no;
	cin >> no;
	--no;
	
	cout << "Информация о пациенте на данном месте:" << endl;
	
	int found = 0, p = x->front, c = 0;
	do {
		if (c == no) {
			printPatient(x->list[p]);
			found = 1;
			break;
		}
		p = (p + 1) % x->max;
	} while (p != x->rear && ++c < x->count);
	
	if (found == 0) {
		printf("Ничего не найдено!\n");
	}
}

// Поиск по диагнозу:
void searchByDiagnosis(PatientQueue* x) {
	if (!x->count) {
		cout << "Очередь пуста!" << endl;
		return;
	}
	
	char b[STRING_BUFFER_SIZE];
	printf("Введите диагноз -> ");
	
	gets(b);
    b[strcspn(b, "\n")] = '\0';
    
    cout << "Информация обо всех пациентах с этим диагнозом с указанием места в очереди:" << endl;
    
	int found = 0, p = x->front, c = 0;
	do {
		if (strcmp(x->list[p].diagnosis, b) == 0) {
			printPatient(x->list[p]);
			found = 1;
		}
		p = (p + 1) % x->max;
	} while (p != x->rear && ++c < x->count);
	
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
	
	PatientQueue* myPatientQueue = newPatientQueue();
	
	showMenu();  // показать меню.
	int userChoice;
	while ((userChoice = selectMenuItem()) != 9) {
		switch(userChoice) {
		case 1:
			myPatientQueue = clearQueue(myPatientQueue);  // очистка очереди, если нужно.
			myPatientQueue = inputFromFile();  // чтение данных из файла.
			break;
		case 2:
			outputToFile(myPatientQueue);  // вывод данных в файл.
			break;
		case 3:
			addToEndOfQueue(myPatientQueue);  // добавление в конец очереди.
			break;
		case 4:
			extractFromBeginningOfQueue(myPatientQueue);  // извлечение из очереди.
			break;
		case 5:
			showQueue(myPatientQueue);  // просмотр очереди.
			break;
		case 6:
			searchByPlaceInQueue(myPatientQueue);  // поиск по месту в очереди.
			break;
		case 7:
			searchByDiagnosis(myPatientQueue);  // поиск по диагнозу.
			break;
		case 8:
			myPatientQueue = clearQueue(myPatientQueue);  // очистка очереди.
			myPatientQueue = newPatientQueue();
			break;
		default:
			break;
		}
	}
	
	// Завершение работы:
	clearQueue(myPatientQueue);  // очистка очереди.
	
	system("pause");  // пауза перед выходом.
	return 0;
}

