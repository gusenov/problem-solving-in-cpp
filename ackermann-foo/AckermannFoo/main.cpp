#include <iostream>

using namespace std;

unsigned int call_count;

// Рекурсивное вычисление функции Аккермана:
int A(int m, int n)
{
    // cout << "m=" << m << " n=" << n << endl;  // DEBUG.

    call_count++;
    //cout << "counter = " << call_count << endl;  // DEBUG.

    if (m == 0) return n + 1;
    else if (n == 0) return A(m - 1, 1);
    else return A(m - 1, A(m, n - 1));
}

// Главная функция:
int main()
{
    int m, n;

    // Ввод из стандартного потока значения аргументов,
    // для которых надо вычислить фукнцию Аккермана:

    cout << "m -> ";
    cin >> m;

    cout << "n -> ";
    cin >> n;

    call_count = 0;

    // Вывод на монитор результата вычисления функции Аккермана:
    cout << "A(" << m << ", " << n << ") = " << A(m, n) << endl;

    // Вывод итогового значения счётчика числа вызовов рекурсивной функции:
    cout << "counter = " << call_count << endl;

    return 0;
}
