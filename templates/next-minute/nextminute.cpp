#include "nextminute.h"

// Перегруженные функции, возвращающие следующую минуту:

time nextMinute(time t) {
	cout << "\tВызвана функция:\n";
	cout << "\ttime nextMinute(time t)\n";
	
	return nextMinute(t.hours, t.minutes, t.seconds);
}

// Три целочисленных параметра: часы, минуты, секунды:
time nextMinute(int hours, int minutes, int seconds) {
	cout << "\tВызвана функция:\n";
	cout << "\ttime nextMinute(int hours, int minutes, int seconds)\n";
	
	time result = nextMinute(hours, minutes);
	result.seconds = seconds;
	return result;
}

// Два целочисленных параметра: часы, минуты:
time nextMinute(int hours, int minutes) {
	cout << "\tВызвана функция:\n";
	cout << "\ttime nextMinute(int hours, int minutes)\n";
	
	time result;
	result.hours = minutes == 59 ? (hours + 1) % 24 : hours;
	result.minutes = (minutes + 1) % 60;
	result.seconds = 0;
	return result;
}


// Перегруженные функции печати времени:

void printTime(time t) {
	printTime(t.hours, t.minutes, t.seconds);
}

// Три целочисленных параметра: часы, минуты, секунды:
void printTime(int hours, int minutes, int seconds) {
	printTime(hours, minutes);
	cout << ":";
	if (seconds < 10)
		cout << "0";
	cout << seconds;
}

// Два целочисленных параметра: часы, минуты:
void printTime(int hours, int minutes) {
	if (hours < 10)
		cout << "0";
	cout << hours << ":";
	if (minutes < 10)
		cout << "0";
	cout << minutes;
}

