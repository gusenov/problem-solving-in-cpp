#ifndef NEXTMINUTE_H
#define NEXTMINUTE_H

#include <iostream>

using namespace std;

// ��������� �������:
typedef struct time {
	int hours;  // ����.
	int minutes;  // ������.
	int seconds;  // �������.
} time;

// ������������� �������, ������������ ��������� ������:

time nextMinute(time t);

// ��� ������������� ���������: ����, ������, �������:
time nextMinute(int hours, int minutes, int seconds);

// ��� ������������� ���������: ����, ������:
time nextMinute(int hours, int minutes);


// ������� �������:

// ��� ���������: ����, ������, �������:
template <class any_type>
time nextMinute(any_type hours, any_type minutes, any_type seconds) {
	cout << "\t������� �������:\n";
	cout << "\ttemplate <class any_type>\n";
	cout << "\ttime nextMinute(any_type hours, any_type minutes, any_type seconds)\n";
	
	time result = nextMinute(hours, minutes);
	result.seconds = seconds;
	return result;
}

// ��� ���������: ����, ������:
template <class any_type>
time nextMinute(any_type hours, any_type minutes) {
	cout << "\t������� �������:\n";
	cout << "\ttemplate <class any_type>\n";
	cout << "\ttime nextMinute(any_type hours, any_type minutes)\n";
	
	time result;
	result.hours = minutes == 59 ? (hours + 1 >= 24 ? 0 : hours + 1) : hours;
	result.minutes = minutes + 1 >= 60 ? 0 : minutes + 1;
	result.seconds = 0;
	return result;
}


// ������������� ������� ������ �������:

void printTime(time t);

// ��� ������������� ���������: ����, ������, �������:
void printTime(int hours, int minutes, int seconds);

// ��� ������������� ���������: ����, ������:
void printTime(int hours, int minutes);

#endif

