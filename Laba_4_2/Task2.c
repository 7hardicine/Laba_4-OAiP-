#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <math.h>

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int i;
	double xn, xk, dx, y;

	puts("������� x ���������, x �������� � ��� x:");
	while (scanf("%lf %lf %lf", &xn, &xk, &dx) < 3 || ((xk - xn) / dx) < 0)
	{
		puts("�� ����� ���-�� �� ���");
		system("cls");
		while (getchar() != '\n');
		puts("������� �������� x ���., x ���. � ��� x ������:");
	}


	system("pause");
}