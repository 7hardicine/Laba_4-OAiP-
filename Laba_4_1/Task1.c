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
	
	int i = 0;
	double x, xn, xk, dx, a, b, y;

	printf("������� x ���������:");

	while (scanf("%lf", &xn) < 1)
	{
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
		while (getchar() != '\n');
	}

	puts("������� x ��������");

	while (scanf("%lf", &xk) < 1)
	{
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
		while (getchar() != '\n');
	}

	puts("������� ��� x");

	while ((scanf("%lf", &dx) < 1) && ((xn > xk && dx > 0) || (xn < xk && dx < 0)))
	{
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
		while (getchar() != '\n');
	}

	x = xn;

	while (abs((xk - xn) / dx) >= i)
	{
		if ((x == 2) || (x == -1) || (x == 0))
		{
			puts("��� ��������� ������ �� ��������� ������ �� x ���������");
			system("pause");
		}
	}
	

	printf("x ���. = %.1lf; x ���. = %.1lf; ��� x = %.1lf; a = %.1lf; b = %.1lf\n", xn, xk, dx, a, b);

	x = xn;

	while (abs((xk - xn) / dx) >= i)
	{		
		y = exp(-x) * (a + b * x) / (log(abs(x + 1)) * log(abs(x + 1)));
		printf("%d      x = %.1lf      y = %.5lf\n", i+1, x, y);
		i++;
		x += dx;
	}

	system("pause");
}