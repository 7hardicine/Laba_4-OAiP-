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

	int num;
	double xn, xk, dx, y, x;

	puts("������� x ���������, x �������� � ��� x:");
	while (scanf("%lf %lf %lf", &xn, &xk, &dx) < 3 || (xn > xk && dx > 0) || (xn < xk && dx < 0)) // ������ ������ � ��������� �� ������������ ���������
	{
		system("cls");
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���\n������ ����� �� ����� �� ������� ����������� ��� � x ���������� ������ ����� �� x ���������");
		puts("������� �������� x ���., x ���. � ��� x ������:");
	}

	x = xn;

	puts("|---|-------|-------|---------------|\n| # |   x   |   y   |   # �������   |\n|---|-------|-------|---------------|");

	for (int i = 0; i <= abs(((xk - xn) / dx)); i++) // ��������� y
	{
		if (x >= 4)
		{
			y = sqrt(x);
			num = 1;
		}
		else if (x <= 1)
		{
			y = 2 * x + 3;
			num = 2;
		}
		else
		{
			y = abs(x * x * x - 4);
			num = 3;
		}
		printf("|%2d | %5.1lf | %5.1lf |       %d       |\n|---|-------|-------|---------------|\n", i+1, x, y, num);
		x += dx;
	}

	system("pause");
}