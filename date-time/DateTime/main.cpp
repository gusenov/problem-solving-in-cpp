#include <iostream>

using namespace std;

enum _Day { UndefinedDay = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 7 };
typedef enum _Day Day;

enum _Month { UndefinedMonth = 0, January = 1, February = 2, March = 3, April = 4, May = 5, June = 6, July = 7, August = 8, September = 9, October = 10, November = 11, December = 12 };
typedef enum _Month Month;

class Date1
{
public:
    // Конструктор без параметров, инициализирующий свойства нулевыми значениями и деструктор:
    Date1()
    {
        cout << "Date1()" << endl;  // тест сигнализирующий о запуске конструктора.

        this->date = 0;
        this->year = 0;
        this->day = UndefinedDay;
        this->month = UndefinedMonth;
    }

    // Деструктор:
    ~Date1()
    {
        cout << "~Date1()" << endl;  // тест сигнализирующий о запуске деструктора.
    }

    // Открытые методы обеспечивающие изменение и вывод на монитор значений свойств:

    short int getDate() { return this->date; }

    void printDate()
    {
        cout << "date = " << this->date << endl;
    }

    void setDate(short int date)
    {
        // Проверка на область допустимых значений перед изменением закрытого целого свойства:
        switch (this->getMonth())
        {
        case January:   if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case February:  if (date <= 0 || date > 29) { cout << "ERROR!" << endl; return; }
        case March:     if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case April:     if (date <= 0 || date > 30) { cout << "ERROR!" << endl; return; }
        case May:       if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case June:      if (date <= 0 || date > 30) { cout << "ERROR!" << endl; return; }
        case July:      if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case August:    if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case September: if (date <= 0 || date > 30) { cout << "ERROR!" << endl; return; }
        case October:   if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case November:  if (date <= 0 || date > 30) { cout << "ERROR!" << endl; return; }
        case December:  if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        case UndefinedMonth:
        default:        if (date <= 0 || date > 31) { cout << "ERROR!" << endl; return; }
        }

        this->date = date;
    }

    short int getYear() { return this->year; }
    void printYear() { cout << "year = " << this->year << endl; }

    void setYear(short int year)
    {
        // Проверка на область допустимых значений перед изменением закрытого целого свойства:
        if (year <= 0) { cout << "ERROR!" << endl; return; }

        this->year = year;
    }

    Day getDay() { return this->day; }

    void printDay()
    {
        cout << "day = ";
        switch (this->getDay())
        {
        case Monday:    cout << "Monday";    break;
        case Tuesday:   cout << "Tuesday";   break;
        case Wednesday: cout << "Wednesday"; break;
        case Thursday:  cout << "Thursday";  break;
        case Friday:    cout << "Friday";    break;
        case Saturday:  cout << "Saturday";  break;
        case Sunday:    cout << "Sunday";    break;
        case UndefinedDay:
        default:        cout << "Undefined"; break;
        }
        cout << endl;
    }

    void setDay(Day day) { this->day = day; }

    Month getMonth() { return this->month; }

    void printMonth()
    {
        cout << "month = ";
        switch (this->getMonth())
        {
        case January:   cout << "January";   break;
        case February:  cout << "February";  break;
        case March:     cout << "March";     break;
        case April:     cout << "April";     break;
        case May:       cout << "May";       break;
        case June:      cout << "June";      break;
        case July:      cout << "July";      break;
        case August:    cout << "August";    break;
        case September: cout << "September"; break;
        case October:   cout << "October";   break;
        case November:  cout << "November";  break;
        case December:  cout << "December";  break;
        case UndefinedMonth:
        default:        cout << "Undefined"; break;
        }
        cout << endl;
    }

    void setMonth(Month month) { this->month = month; }

private:
    // Закрытые целочисленные свойства:
    short int date;  // дата.
    short int year;  // год.

    // Свойства перечислимого типа:
    Day day;  // день.
    Month month;  // месяц.
};

class Time1
{
public:
    Time1()
    {
        cout << "Time1()" << endl;

        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    }

    ~Time1()
    {
        cout << "~Time1()" << endl;
    }

    void init(int hours, int minutes, int seconds)
    {
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    void print()
    {
        cout << "time = " << this->hours << ":" << this->minutes << ":" << this->seconds << endl;
    }

private:
    short int hours;
    short int minutes;
    short int seconds;
};

int main()
{
    struct _DateTime1
    {
        Date1 date;
        Time1 time;
    };
    typedef struct _DateTime1 DateTime1;

    DateTime1 now;

    now.date.setYear(2018);
    now.date.setMonth(May);
    now.date.setDate(28);
    now.date.setDay(Monday);

    now.date.printYear();
    now.date.printMonth();
    now.date.printDate();
    now.date.printDay();

    now.time.init(22, 6, 30);
    now.time.print();

    return 0;
}
