#include "nextminute.h"

// ������������� �������, ������������ ��������� ������:

time nextMinute(time t) {
	cout << "\t������� �������:\n";
	cout << "\ttime nextMinute(time t)\n";
	
	return nextMinute(t.hours, t.minutes, t.seconds);
}

// ��� ������������� ���������: ����, ������, �������:
time nextMinute(int hours, int minutes, int seconds) {
	cout << "\t������� �������:\n";
	cout << "\ttime nextMinute(int hours, int minutes, int seconds)\n";
	
	time result = nextMinute(hours, minutes);
	result.seconds = seconds;
	return result;
}

// ��� ������������� ���������: ����, ������:
time nextMinute(int hours, int minutes) {
	cout << "\t������� �������:\n";
	cout << "\ttime nextMinute(int hours, int minutes)\n";
	
	time result;
	result.hours = minutes == 59 ? (hours + 1) % 24 : hours;
	result.minutes = (minutes + 1) % 60;
	result.seconds = 0;
	return result;
}


// ������������� ������� ������ �������:

void printTime(time t) {
	printTime(t.hours, t.minutes, t.seconds);
}

// ��� ������������� ���������: ����, ������, �������:
void printTime(int hours, int minutes, int seconds) {
	printTime(hours, minutes);
	cout << ":";
	if (seconds < 10)
		cout << "0";
	cout << seconds;
}

// ��� ������������� ���������: ����, ������:
void printTime(int hours, int minutes) {
	if (hours < 10)
		cout << "0";
	cout << hours << ":";
	if (minutes < 10)
		cout << "0";
	cout << minutes;
}

