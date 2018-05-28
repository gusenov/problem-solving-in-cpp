#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Определение главной функции принимающей аргументы:
int main(int argc, char *argv[])  // 1-й способ.
// int main(int argc, char **argv)  // 2-й способ.
{
    // cout << "argc = " << argc << endl;  // DEBUG.

    // Вывод на монитор массива строк argv[];
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }

    if (argc != 4)  // если массив строк argv[] не содержит 4 элемента:
    {
        cerr << "ERROR!";  // сообщение об ошибке.
        return 4;  // завершить программу кодом 4.
    }

    const char HELLO[] = "Hello";  // строковая константа.

    if (strcmp(HELLO, argv[1]) != 0)  // если argv[1] не совпадает с константой:
    {
        return 7;  // завершить программу кодом 7.
    }

    // Копирование файла заданного строкой argv[2] в файл заданный строкой argv[3].
    ifstream src(argv[2], ios::binary | ios::in);
    if (src.fail())
    {
        return 2;
    }
    else
    {
        ofstream dst(argv[3], ios::binary | ios::out);
        if (dst.fail())
        {
            return 3;
        }
        else
        {
            dst << src.rdbuf();
        }
    }

    return 0;
}
