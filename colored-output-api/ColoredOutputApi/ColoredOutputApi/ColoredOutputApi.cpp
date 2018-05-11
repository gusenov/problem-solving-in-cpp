// ColoredOutputApi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <locale.h>
#include <conio.h>


// ����������� �������:
#define DIM 2000

// �������� ��������� ��������� �����:
#define RNDMIN 20
#define RNDMAX 2000


// �������� ������� ��������� ��������� �������:
int compare(const void *, const void *);


int _tmain(int argc, _TCHAR* argv[])
{
	int mas[DIM];
	int i;

	setlocale(LC_ALL, "rus");
	SetConsoleTitle(L"������� 13");
	
	srand(GetTickCount());  // ��������� ������ ��������� �����.

	// ���� ����������� N <= 2000:
	int N;
	do
	{
		printf("������� ����������� N <= 2000 -> ");
		scanf("%d", &N);
	} while (N <= 0 || N > 2000);
	printf("N = %d", N);
	printf("\n---------------------------------------------------------------------\n");

	printf("\n%d ��������� ����� ����� �� ������� [%d, %d]:\n", N, RNDMIN, RNDMAX);

	// ��������� ������ N ���������� ������� �� RNDMIN = 20 �� RNDMAX = 2000 (�� 20 �� 2000):
	for (i = 0; i < N; i++)
	{
		// rand() % x ��� �������� � ��������� �� 0 �� x - 1.
		
		// rand() % RNDMAX + RNDMIN ��� �������� � ��������� �� 0 �� RNDMAX - 1, � � ����� �������� ������������ RNDMIN.
		// ���� RNDMAX ����� 2000, � RNDMIN ����� 20, �� ���������� �������� � ��������� �� 20 �� 2019.

		// rand() % (RNDMAX - RNDMIN) + RNDMIN ��� �������� � ��������� �� 0 �� RNDMAX - RNDMIN - 1, � � ����� �������� ������������ RNDMIN.
		// ���� RNDMAX ����� 2000, � RNDMIN ����� 20, �� ���������� �������� � ��������� �� 20 �� 1999.

		mas[i] = rand() % (RNDMAX - RNDMIN + 1) + RNDMIN;
		printf("%d ", mas[i]);
	}
	printf("\n---------------------------------------------------------------------\n");

	// ��������� �� �������������:
	qsort((void *)mas, N, sizeof(int), compare);

	// ������� �� �������:
	printf("\n������������� �� ������������� ������:\n");
	for (i = 0; i < N; i++)
	{
		printf("%d ", mas[i]);
	}
	printf("\n---------------------------------------------------------------------\n");

	// �������� ������������� �������:
	HANDLE hStdout;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	// �������� ��������� ������ ������:
	CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(hStdout, &ConsoleScreenBufferInfo);

	printf("\n�������� ������, �������� �������:\n");
	char str[11];
	for (i = 0; i < N; i++)
	{
		sprintf(str, "%d", mas[i]);
		
		// �����, ���������� ������ ����� 2, 4, 6 � 7:
		unsigned j;
		for (j = 0; j < strlen(str); j++)
		{
			// ���� ��������� ����� � ����� �� ����� 2, 4, 6 ��� 7, �� �������� ������� �� �����:
			if ( !(str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7') )
			{
				break;
			}
		}
		// � �������������� ����� ��������� ����� ���������� ������ �����, �����
		// ����� ���� ���� �����, ������� �� ����� 2, 4, 6 ��� 7.

		if (j == strlen(str))  // ���� �� ���� ���������� ������ �� ����������� �����, ��:
		{
			SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			printf("%d ", mas[i]);
			continue;
		}

		// �����, �� ���������� ���� 2, 4, 6 � 7:
		for (j = 0; j < strlen(str); j++)
		{
			// ���� ��������� ����� � ����� ����� 2, 4, 6 ��� 7, �� �������� ������� �� �����:
			if (str[j] == '2' || str[j] == '4' || str[j] == '6' || str[j] == '7')
			{
				break;
			}
		}
		// � �������������� ����� ��������� ����� ���������� ������ �����, �����
		// ����� ���� ���� �����, ������� ����� 2, 4, 6 ��� 7.

		if (j == strlen(str))  // ���� �� ���� ���������� ������ �� ����������� �����, ��:
		{
			SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			printf("%d ", mas[i]);
			continue;
		}
		
		// ���������:
		SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("%d ", mas[i]);
	}
	printf("\n");

	// ��������������� �������� ��������� �������:
	SetConsoleTextAttribute(hStdout, ConsoleScreenBufferInfo.wAttributes);

	printf("\n�������� ������������ ������:\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	printf("- �����, ���������� ������ ����� 2, 4, 6 � 7;\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	printf("- �����, �� ���������� ���� 2, 4, 6 � 7;\n");

	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("- ��������� �����.");

	// ��������������� �������� ��������� �������:
	SetConsoleTextAttribute(hStdout, ConsoleScreenBufferInfo.wAttributes);
	
	printf("\n---------------------------------------------------------------------\n");

	printf("\n������� ����� ������� ��� �����������\n");
	if (_getch() == 0)
	{
		_getch();
	}

	return 0;
}

// ������� ��������� ��������� �������:
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
