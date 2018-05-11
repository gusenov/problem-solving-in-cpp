// ColoredOutputClr.cpp : main project file.

#include "stdafx.h"

using namespace System;

// ������� ��������� ��������� �������:
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
	const int rndmin = 20, rndmax = 2000;  // �������� ��������� ��������� �����.

	int i;

	Console::Title = L"������� 13";

	System::Random randObj;  // ��������� ������ ��������� �����.

	// ���� ����������� N <= 2000:
	int N;  // ����������� �������.
	do
	{
		Console::Write(L"������� ����������� N <= 2000 -> ");
		N = int::Parse(Console::ReadLine());
	} while (N <= 0 || N > 2000);
	Console::Write(L"N = " + N);
	Console::Write(L"\n---------------------------------------------------------------------\n");

	array<int>^mas = gcnew array<int>(N);

	Console::Write(L"\n" + N + L" ��������� ����� ����� �� ������� [" + rndmin + L", " + rndmax + L"]:\n");

	// ��������� ������ N ���������� ������� �� RNDMIN = 20 �� RNDMAX = 2000 (�� 20 �� 2000):
	for (i = 0; i < N; i++)
	{
		mas[i] = randObj.Next(rndmin, rndmax);
		Console::Write(mas[i] + L" ");
	}
	Console::Write(L"\n---------------------------------------------------------------------\n");

	// ��������� �� �������������:
	Array::Sort(mas, gcnew Comparison<int>(Compare));

	// ������� �� �������:
	Console::Write(L"\n������������� �� ������������� ������:\n");
	for (i = 0; i < N; i++)
	{
		Console::Write(mas[i] + L" ");
	}
	Console::Write(L"\n---------------------------------------------------------------------\n");

	ConsoleColor color = Console::ForegroundColor::get();

	Console::Write("\n�������� ������, �������� �������:\n");
	String ^str = "";
	for (i = 0; i < N; i++)
	{
		str = Convert::ToString(mas[i]);

		// �����, ���������� ������ ����� 2, 4, 6 � 7:
		unsigned j;
		for (j = 0; j < str->Length; j++)
		{
			// ���� ��������� ����� � ����� �� ����� 2, 4, 6 ��� 7, �� �������� ������� �� �����:
			if (!(str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7'))
			{
				break;
			}
		}
		// � �������������� ����� ��������� ����� ���������� ������ �����, �����
		// ����� ���� ���� �����, ������� �� ����� 2, 4, 6 ��� 7.

		if (j == str->Length)  // ���� �� ���� ���������� ������ �� ����������� �����, ��:
		{
			Console::ForegroundColor = ConsoleColor::Red;
			Console::Write(mas[i] + L" ");
			continue;
		}

		// �����, �� ���������� ���� 2, 4, 6 � 7:
		for (j = 0; j < str->Length; j++)
		{
			// ���� ��������� ����� � ����� ����� 2, 4, 6 ��� 7, �� �������� ������� �� �����:
			if (str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7')
			{
				break;
			}
		}
		// � �������������� ����� ��������� ����� ���������� ������ �����, �����
		// ����� ���� ���� �����, ������� ����� 2, 4, 6 ��� 7.

		if (j == str->Length)  // ���� �� ���� ���������� ������ �� ����������� �����, ��:
		{
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::Write(mas[i] + L" ");
			continue;
		}

		// ���������:
		Console::ForegroundColor = ConsoleColor::Green;
		Console::Write(mas[i] + L" ");
	}
	Console::WriteLine();

	// ��������������� �������� ��������� �������:
	Console::ForegroundColor = color;

	Console::Write("\n�������� ������������ ������:\n");

	Console::ForegroundColor = ConsoleColor::Red;
	Console::Write("- �����, ���������� ������ ����� 2, 4, 6 � 7;\n");

	Console::ForegroundColor = ConsoleColor::Cyan;
	Console::Write("- �����, �� ���������� ���� 2, 4, 6 � 7;\n");

	Console::ForegroundColor = ConsoleColor::Green;
	Console::Write("- ��������� �����.");

	// ��������������� �������� ��������� �������:
	Console::ForegroundColor = color;

	Console::Write("\n---------------------------------------------------------------------\n");

	Console::Write("\n������� ����� ������� ��� �����������\n");
	Console::ReadKey();

	return 0;
}
