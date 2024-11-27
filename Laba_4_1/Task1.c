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
	double x, xn, xk, dx, a = 1, b = 3, y;

	puts("������� a:");

	while (scanf("%lf", &a) < 1) // �������� a �� ����
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
	}

	puts("������� b:");

	while (scanf("%lf", &b) < 1) // �������� b �� ����
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
	}

	puts("������� x ���������:");

	while (scanf("%lf", &xn) < 1) // �������� x ���������� �� ����
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
	}

	while ((xn == 2) || (xn == -1) || (xn == 0)) // �������� x ���������� �� ������������ ��������
	{
		while (getchar() != '\n');
		puts("x ��������� �� ����� ��������� 0 / -1 / 2\n������� ������ x ���������:");
	}

	puts("������� x ��������:");

	while (scanf("%lf", &xk) < 1) // �������� x ��������� �� ����
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ������� �������� ������");
	}

	while ((xk == xn) || (xk == 2) || (xk == -1) || (xk == 0)) // �������� x  ��������� �� ������������ � x ��������� � ������������ ��������
	{
		while (getchar() != '\n');
		puts("�� ���� ��������� x �������� ����� x ���������� ��� x �������� �� ������������ ������� �����������\n������� ������ x ��������");
	}

	puts("������� ��� x:");

	int ok = 1;

	while (ok) // ��������� ���� x
	{
		if ((scanf("%lf", &dx) == 1)) 
		{
			while ((xn > xk && dx > 0) || (xn < xk && dx < 0))
			{
				while (getchar() != '\n');
				puts("� ��� �� ������ ���, ������� ������:");
				while ((scanf("%lf", &dx) != 1))
				{
					while (getchar() != '\n');
					puts("�� ����� ���-�� �� ���, ������� �������� ������:");
				}
			}
			ok = 0;
		}
		else 
		{
			while (getchar() != '\n');
			puts("�� ����� ���-�� �� ���, ������� �������� ������:");
		}
	}

	x = xn;

	while (abs((xk - xn) / dx) >= i) // �������� ����� ����������
	{
		if ((x == 2) || (x == -1) || (x == 0))
		{
			puts("��� ��������� ������ �� ���������� ������������ ������������ ��������\n������� ��� ������ ��� �������� ��������� � ��������� � ������ ��� ���������� ����� ����������");
			dx = 0;
			while ((scanf("%lf", &dx) < 1) || (xn > xk && dx > 0) || (xn < xk && dx < 0))
			{
				puts("�� ����� ���-�� �� ���, ������� �������� ������");
				while (getchar() != '\n');
			}
			x = xn;
		}
		else
		{
			x += dx;
			i++;
		}
	}

	printf("x ���. = %.1lf; x ���. = %.1lf; ��� x = %.1lf; a = %.1lf; b = %.1lf\n", xn, xk, dx, a, b);

	i = 0;
	x = xn;

	if (dx == 0)
	{
		y = exp(-x) * (a + b * x) / (log(abs(x + 1)) * log(abs(x + 1)));
		printf("%d      x = %.1lf      y = %.5lf\n", i + 1, x, y);
	}
	else
	{
		while (abs((xk - xn) / dx) >= i)
		{
			y = exp(-x) * (a + b * x) / (log(abs(x + 1)) * log(abs(x + 1)));
			printf("%d      x = %.1lf      y = %.5lf\n", i + 1, x, y);
			i++;
			x += dx;
		}
	}

	system("pause");
}