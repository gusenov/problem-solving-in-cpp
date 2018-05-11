// ColoredOutputApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>
#include <conio.h>


// Размерность массива:
#define DIM 2000

// Диапазон генерации случайных чисел:
#define RNDMIN 20
#define RNDMAX 2000


// Прототип функции сравнения элементов массива:
int compare(const void *, const void *);


int _tmain(int argc, _TCHAR* argv[])
{
	int mas[DIM];
	int i;

	setlocale(LC_ALL, "rus");
	SetConsoleTitle(L"Вариант 13");
	
	srand(GetTickCount());  // запускаем датчик случайных чисел.

	// Дано натуральное N <= 2000:
	int N;
	do
	{
		printf("Введите натуральное N <= 2000 -> ");
		scanf("%d", &N);
	} while (N <= 0 || N > 2000);
	printf("N = %d", N);
	printf("\n---------------------------------------------------------------------\n");

	printf("\n%d случайных целых чисел из отрезка [%d, %d]:\n", N, RNDMIN, RNDMAX);

	// Заполняем массив N случайными числами от RNDMIN = 20 до RNDMAX = 2000 (от 20 до 2000):
	for (i = 0; i < N; i++)
	{
		// rand() % x даёт значение в диапазоне от 0 до x - 1.
		
		// rand() % RNDMAX + RNDMIN даёт значение в диапазоне от 0 до RNDMAX - 1, и к этому значению прибавляется RNDMIN.
		// Если RNDMAX равно 2000, а RNDMIN равно 20, то получается значение в диапазоне от 20 до 2019.

		// rand() % (RNDMAX - RNDMIN) + RNDMIN даёт значение в диапазоне от 0 до RNDMAX - RNDMIN - 1, и к этому значению прибавляется RNDMIN.
		// Если RNDMAX равно 2000, а RNDMIN равно 20, то получается значение в диапазоне от 20 до 1999.

		mas[i] = rand() % (RNDMAX - RNDMIN + 1) + RNDMIN;
		printf("%d ", mas[i]);
	}
	printf("\n---------------------------------------------------------------------\n");

	// Сортируем по невозрастанию:
	qsort((void *)mas, N, sizeof(int), compare);

	// Выводим на монитор:
	printf("\nСортированный по невозрастанию массив:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", mas[i]);
	}
	printf("\n---------------------------------------------------------------------\n");

	// Получаем идентификатор консоли:
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// Получаем параметры буфера косоли:
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(hStdout, &ConsoleScreenBufferInfo);

	printf("\nПечатаем массив, соблюдая условия:\n");
	char str[11];
	for (i = 0; i < N; i++)
	{
		sprintf(str, "%d", mas[i]);
		
		// Числа, содержащие только цифры 2, 4, 6 и 7:
		unsigned j;
		for (j = 0; j < strlen(str); j++)
		{
			// Если очередная цифра в числе не равна 2, 4, 6 или 7, то досрочно выходим из цикла:
			if ( !(str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7') )
			{
				break;
			}
		}
		// В вышеприведённом цикле досрочный выход происходит только тогда, когда
		// среди цифр есть такая, которая не равна 2, 4, 6 или 7.

		if (j == strlen(str))  // если не было досрочного выхода из предыдущего цикла, то:
		{
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("%d ", mas[i]);
			continue;
		}

		// Числа, не содержащие цифр 2, 4, 6 и 7:
		for (j = 0; j < strlen(str); j++)
		{
			// Если очередная цифра в числе равна 2, 4, 6 или 7, то досрочно выходим из цикла:
			if (str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7')
			{
				break;
			}
		}
		// В вышеприведённом цикле досрочный выход происходит только тогда, когда
		// среди цифр есть такая, которая равна 2, 4, 6 или 7.

		if (j == strlen(str))  // если не было досрочного выхода из предыдущего цикла, то:
		{
			SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			printf("%d ", mas[i]);
			continue;
		}
		
		// Остальные:
		SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("%d ", mas[i]);
	}
	printf("\n");

	// Восстанавливаем цветовые параметры консоли:
	SetConsoleTextAttribute(hStdout, ConsoleScreenBufferInfo.wAttributes);

	printf("\nЗначение употреблённых цветов:\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("- числа, содержащие только цифры 2, 4, 6 и 7;\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("- числа, не содержащие цифр 2, 4, 6 и 7;\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("- остальные числа.");

	// Восстанавливаем цветовые параметры консоли:
	SetConsoleTextAttribute(hStdout, ConsoleScreenBufferInfo.wAttributes);
	
	printf("\n---------------------------------------------------------------------\n");

	printf("\nНажмите любую клавишу для продолжения\n");
	if (_getch() == 0)
	{
		_getch();
	}

	return 0;
}

// Функция сравнения элементов массива:
int compare(const void *arg1, const void *arg2)
{
	int *num1 = (int *)arg1;
	int *num2 = (int *)arg2;
	
	if (*num1 < *num2)
	{
		return 1;
	}

	return -1;
}
