#ifndef NEXTMINUTE_H
#define NEXTMINUTE_H

#include <iostream>

using namespace std;

// Структура «время»:
typedef struct time {
	int hours;  // часы.
	int minutes;  // минуты.
	int seconds;  // секунды.
} time;

// Перегруженные функции, возвращающие следующую минуту:

time nextMinute(time t);

// Три целочисленных параметра: часы, минуты, секунды:
time nextMinute(int hours, int minutes, int seconds);

// Два целочисленных параметра: часы, минуты:
time nextMinute(int hours, int minutes);


// Шаблоны функций:

// Три параметра: часы, минуты, секунды:
template <class any_type>
time nextMinute(any_type hours, any_type minutes, any_type seconds) {
	cout << "\tВызвана функция:\n";
	cout << "\ttemplate <class any_type>\n";
	cout << "\ttime nextMinute(any_type hours, any_type minutes, any_type seconds)\n";
	
	time result = nextMinute(hours, minutes);
	result.seconds = seconds;
	return result;
}

// Два параметра: часы, минуты:
template <class any_type>
time nextMinute(any_type hours, any_type minutes) {
	cout << "\tВызвана функция:\n";
	cout << "\ttemplate <class any_type>\n";
	cout << "\ttime nextMinute(any_type hours, any_type minutes)\n";
	
	time result;
	result.hours = minutes == 59 ? (hours + 1 >= 24 ? 0 : hours + 1) : hours;
	result.minutes = minutes + 1 >= 60 ? 0 : minutes + 1;
	result.seconds = 0;
	return result;
}


// Перегруженные функции печати времени:

void printTime(time t);

// Три целочисленных параметра: часы, минуты, секунды:
void printTime(int hours, int minutes, int seconds);

// Два целочисленных параметра: часы, минуты:
void printTime(int hours, int minutes);

#endif

