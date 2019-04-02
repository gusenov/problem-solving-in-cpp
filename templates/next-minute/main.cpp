#include <iostream>
#include <cstdlib>
#include "nextminute.h"
#include <windows.h>

using namespace std;

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

int main(int argc, char** argv) {
	cyrillic();
	
	time t;
	int ihours, iminutes, iseconds;
	double dhours, dminutes, dseconds;
	int choice;
	
	cout << "����:\n"
		 << "\t1) ������ ��������� ������� (����, ������, �������).\n"
		 << "\t2) ������ 3 ������������� ���������: ����, ������, �������.\n"
		 << "\t3) ������ 2 ������������� ���������: ����, ������.\n"
		 << "\t4) ������ 3 ��������� � ��������� ������: ����, ������, �������.\n"
		 << "\t5) ������ 2 ��������� � ��������� ������: ����, ������.\n"
		 << "\t6) �����.\n";
	
	do {
		
		cout << "������� ����� ����>";
		cin >> choice;
		
		if (choice == 6)
			break;

		switch (choice) {
			case 1:
				cout << "������� ����� ������ ����, ������, �������>";
				cin >> t.hours >> t.minutes >> t.seconds;
				cout << "��������� ������:\n";
				t = nextMinute(t);
				printTime(t);
				break;
			
			case 2:
				cout << "������� ����� ������ ����, ������, �������>";
				cin >> ihours >> iminutes >> iseconds;
				cout << "��������� ������:\n";
				t = nextMinute(ihours, iminutes, iseconds);
				printTime(t.hours, t.minutes, t.seconds);
				break;
			case 3:
				cout << "������� ����� ������ ����, ������>";
				cin >> ihours >> iminutes;
				cout << "��������� ������:\n";
				t = nextMinute(ihours, iminutes);
				printTime(t.hours, t.minutes);
				break;
				
			case 4:
				cout << "������� ����� ������ ����, ������, �������>";
				cin >> dhours >> dminutes >> dseconds;
				cout << "��������� ������:\n";
				t = nextMinute(dhours, dminutes, dseconds);
				printTime(t.hours, t.minutes, t.seconds);
				break;
			case 5:
				cout << "������� ����� ������ ����, ������>";
				cin >> dhours >> dminutes;
				cout << "��������� ������:\n";
				t = nextMinute(dhours, dminutes);
				printTime(t.hours, t.minutes);
				break;
		}
		
		cout << endl;
	
	} while (1);
	
	system("pause");
	return EXIT_SUCCESS;
}

