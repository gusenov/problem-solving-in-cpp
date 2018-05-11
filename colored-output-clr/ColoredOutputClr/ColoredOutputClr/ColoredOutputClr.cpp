// ColoredOutputClr.cpp : main project file.

#include "stdafx.h"

using namespace System;

// Функция сравнения элементов массива:
int Compare(int a, int b)
{
	if (a < b)
	{
		return 1;
	}

	return -1;
}

int main(array<System::String ^> ^args)
{
	const int rndmin = 20, rndmax = 2000;  // диапазон генерации случайных чисел.

	int i;

	Console::Title = L"Вариант 13";

	System::Random randObj;  // запускаем датчик случайных чисел.

	// Дано натуральное N <= 2000:
	int N;  // размерность массива.
	do
	{
		Console::Write(L"Введите натуральное N <= 2000 -> ");
		N = int::Parse(Console::ReadLine());
	} while (N <= 0 || N > 2000);
	Console::Write(L"N = " + N);
	Console::Write(L"\n---------------------------------------------------------------------\n");

	array<int>^mas = gcnew array<int>(N);

	Console::Write(L"\n" + N + L" случайных целых чисел из отрезка [" + rndmin + L", " + rndmax + L"]:\n");

	// Заполняем массив N случайными числами от RNDMIN = 20 до RNDMAX = 2000 (от 20 до 2000):
	for (i = 0; i < N; i++)
	{
		mas[i] = randObj.Next(rndmin, rndmax);
		Console::Write(mas[i] + L" ");
	}
	Console::Write(L"\n---------------------------------------------------------------------\n");

	// Сортируем по невозрастанию:
	Array::Sort(mas, gcnew Comparison<int>(Compare));

	// Выводим на монитор:
	Console::Write(L"\nСортированный по невозрастанию массив:\n");
	for (i = 0; i < N; i++)
	{
		Console::Write(mas[i] + L" ");
	}
	Console::Write(L"\n---------------------------------------------------------------------\n");

	ConsoleColor color = Console::ForegroundColor::get();

	Console::Write("\nПечатаем массив, соблюдая условия:\n");
	String ^str = "";
	for (i = 0; i < N; i++)
	{
		str = Convert::ToString(mas[i]);

		// Числа, содержащие только цифры 2, 4, 6 и 7:
		unsigned j;
		for (j = 0; j < str->Length; j++)
		{
			// Если очередная цифра в числе не равна 2, 4, 6 или 7, то досрочно выходим из цикла:
			if (!(str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7'))
			{
				break;
			}
		}
		// В вышеприведённом цикле досрочный выход происходит только тогда, когда
		// среди цифр есть такая, которая не равна 2, 4, 6 или 7.

		if (j == str->Length)  // если не было досрочного выхода из предыдущего цикла, то:
		{
			Console::ForegroundColor = ConsoleColor::Red;
			Console::Write(mas[i] + L" ");
			continue;
		}

		// Числа, не содержащие цифр 2, 4, 6 и 7:
		for (j = 0; j < str->Length; j++)
		{
			// Если очередная цифра в числе равна 2, 4, 6 или 7, то досрочно выходим из цикла:
			if (str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7')
			{
				break;
			}
		}
		// В вышеприведённом цикле досрочный выход происходит только тогда, когда
		// среди цифр есть такая, которая равна 2, 4, 6 или 7.

		if (j == str->Length)  // если не было досрочного выхода из предыдущего цикла, то:
		{
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::Write(mas[i] + L" ");
			continue;
		}

		// Остальные:
		Console::ForegroundColor = ConsoleColor::Green;
		Console::Write(mas[i] + L" ");
	}
	Console::WriteLine();

	// Восстанавливаем цветовые параметры консоли:
	Console::ForegroundColor = color;

	Console::Write("\nЗначение употреблённых цветов:\n");

	Console::ForegroundColor = ConsoleColor::Red;
	Console::Write("- числа, содержащие только цифры 2, 4, 6 и 7;\n");

	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::Write("- числа, не содержащие цифр 2, 4, 6 и 7;\n");

	Console::ForegroundColor = ConsoleColor::Green;
	Console::Write("- остальные числа.");

	// Восстанавливаем цветовые параметры консоли:
	Console::ForegroundColor = color;

	Console::Write("\n---------------------------------------------------------------------\n");

	Console::Write("\nНажмите любую клавишу для продолжения\n");
	Console::ReadKey();

	return 0;
}
