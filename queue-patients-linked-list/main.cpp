#include <iostream>
#include <cstdio>
#include <windows.h>

using namespace std;

const int STRING_BUFFER_SIZE = 128;

// ��������� ���������� ���������� � ��������:
typedef struct Patient {
	char surname[STRING_BUFFER_SIZE];     // �������.
	char name[STRING_BUFFER_SIZE];        // ���.
	char secondName[STRING_BUFFER_SIZE];  // ��������.
	int age;                              // �������.
	char diagnosis[STRING_BUFFER_SIZE];   // �������.
} Data;

// ��������� ���������� ���������� �� �������:
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


// ������� �� ���������:
void cyrillic(void) {
	// ��� ������ ����� ��� ����������� ����������� ���������:
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	// ����� ���� �������� ����� � ������� �� Lucida Console.
	// ��� ������ ������ �������� ������ ������� 
	// �� ������� ���������� ������ ���� �������. 
	// � ����������� ���� ��������� ���������. 
	// � ����������� ���� ��������� ������� ������ 
	// � ��� ��������� �Lucida Console�. 
}

// ������ ��������:
void print_patient(const Data& patient) {
	printf("%-16s %-16s %-16s %-8i %-16s\n"
		, patient.surname
		, patient.name
		, patient.secondName
		, patient.age
		, patient.diagnosis);
}

// �������� ����� �������:
Queue* push(Queue* previous, const Data data) {
	Queue* n = new Queue;
	n->data = data;
	n->next = NULL;
	
	if (previous) {
		previous->next = n;
	}
	
	return n;
}

// ���������� �������� �� ������ �� �������:
Queue* pop(Queue** queue) {
	if (!queue) { cout << "������� �����!" << endl; }
	Queue* result = *queue;
	*queue = result->next;
	return result;
}

// ������� �������:
Queue* delete_queue(Queue* queue) {
	// ������������ ������, ���������� ��� ��������� �������:
	Queue* current = queue;
	Queue* del = NULL;
	while (current) {
		del = current;
		current = current->next;
		delete del;
	}
	return NULL;
}

// ������ ������ �� �����:
Queue* input_queue_from_file(void) {
	Queue* head = NULL;
	
	cout << "������� ��� �����, ����������� ���������� � ��������� -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	// ���������� ������ �� ����� � ���������� �� � �������:
	FILE* f1 = fopen(fname, "r");
	if (f1 == NULL) {
		printf("���������� ������� ���� '%s'!\n", fname);
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
		printf("�� ������� ������ � �����!\n");
		return delete_queue(head);
	}
	
	return head;
}

// ����� ������ � ����:
void output_queue_to_file(Queue* queue) {
	cout << "������� ��� �����, � ������� ��������� ���������� ��� ���� ��������� � ������� ������� -> ";
	
	char fname[STRING_BUFFER_SIZE];
	scanf("%s", fname);
	
	FILE* f1 = fopen(fname, "w");
	if (f1 == NULL) {
		printf("���������� ������� ���� '%s'!\n", fname);
		return;
	}
	
	int count = 0;
	Queue* next = queue;
	while (next) {
		count++;
		next = next->next;
	}
	
	fprintf(f1, "%d\n", count);
	
	// (���� �������� ��� ���� �� ������� �� �����������)
	if (count > 0) do {
		Data* x = &queue->data;
		fprintf(f1, "%s %s %s %i %s ", x->surname, x->name, x->secondName, x->age, x->diagnosis);
	} while (queue = queue->next);

	fclose(f1);
}

// ���������� � ����� �������:
Queue* input_patient_to_queue(Queue* queue) {	
	cout << "������� ������ � �������� � �������:\n������� ��� �������� ������� �������" << endl;
	
	Data x;
	scanf("%s%s%s%i%s", &x.surname, &x.name, &x.secondName, &x.age, &x.diagnosis);
	
	Queue* newNode = push(queue, x);
	
	return newNode;
}

// �������� �������:
void print_queue_to_screen(Queue* queue) {
	if (!queue) {
		cout << "������� �����!" << endl;
		return;
	}
	
	cout << "���������� ��� ���� ��������� � ������� �������:" << endl;
	// (���� �������� ��� ���� �� ������� �� �����������)
	do {
		print_patient(queue->data);
	} while (queue = queue->next);
}

// ����� �� ����� � �������:
void search_by_place_in_queue(Queue* patientQueue) {
	if (!patientQueue) {
		cout << "������� �����!" << endl;
		return;
	}
	
	cout << "������� ����� � ������� -> ";
	int no;
	cin >> no;
	
	cout << "���������� � �������� �� ������ �����:" << endl;
	
	int found = 0;
	do {
		if (--no == 0) {
			print_patient(patientQueue->data);
			found = 1;
		}
	} while (patientQueue = patientQueue->next);
	
	if (found == 0) {
		printf("������ �� �������!\n");
	}
}

// ����� �� ��������:
void search_by_diagnosis(Queue* patientQueue) {
	if (!patientQueue) {
		cout << "������� �����!" << endl;
		return;
	}
	
	char b[STRING_BUFFER_SIZE];
	printf("������� ������� -> ");
	
	gets(b);
    b[strcspn(b, "\n")] = '\0';
    
    cout << "���������� ��� ���� ��������� � ���� ��������� � ��������� ����� � �������:" << endl;

	int found = 0;
	do {
		if (strcmp(patientQueue->data.diagnosis, b) == 0) {
			print_patient(patientQueue->data);
			found = 1;
		}
	} while (patientQueue = patientQueue->next);
	
	if (found == 0) {
		printf("������ �� �������!\n");
	}
}

// �������� ���� ��� ������������� ������� � �������������:
void showMenu(void) {
	cout << "����:" << endl;
	cout << "1) ������ ������ �� �����;" << endl;
	cout << "2) ����� ������ � ����;" << endl;
	cout << "3) ���������� � ����� �������;" << endl;
	cout << "4) ���������� �� �������;" << endl;
	cout << "5) �������� �������;" << endl;
	cout << "6) ����� �� ����� � �������;" << endl;
	cout << "7) ����� �� ��������;" << endl;
	cout << "8) ������� �������;" << endl;
	cout << "9) ���������� ������." << endl;
}

// ���� ������ ���� �������������:
int selectMenuItem(void) {
	int userChoice;
	cout << "������� ����� ������ ���� -> ";
	cin >> userChoice;
	fgetc(stdin);
	return userChoice;
}

// ������� �������:
int main(int argc, char** argv) {
	cyrillic();  // ���. ���������.
	
	cout << "��������� ��� ����������� ������� ���������." << endl;
	
	Queue* myQueue = NULL;
	Queue* tmp = NULL;
	
	showMenu();  // �������� ����.
	int userChoice;
	while ((userChoice = selectMenuItem()) != 9) {
		switch(userChoice) {
		case 1:
			myQueue = delete_queue(myQueue);  // ������� �������, ���� �����.
			myQueue = input_queue_from_file();  // ������ ������ �� �����.
			break;
		case 2:
			output_queue_to_file(myQueue);  // ����� ������ � ����.
			break;
		case 3:
			tmp = input_patient_to_queue(myQueue);  // ���������� � ����� �������.
			if (!myQueue) myQueue = tmp;
			break;
		case 4:
			tmp = pop(&myQueue);
			cout << "���������� � ��������:" << endl;
			print_patient(tmp->data);
			delete tmp;			
			break;
		case 5:
			print_queue_to_screen(myQueue);  // �������� �������.
			break;
		case 6:
			search_by_place_in_queue(myQueue);  // ����� �� ����� � �������.
			break;
		case 7:
			search_by_diagnosis(myQueue);  // ����� �� ��������.
			break;
		case 8:
			myQueue = delete_queue(myQueue);  // ������� �������.
			break;
		default:
			break;
		}
	}
	
	// ���������� ������:
	delete_queue(myQueue);  // ������� �������.
	
	system("pause");  // ����� ����� �������.
	return 0;
}


