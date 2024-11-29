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

	puts("Введите x начальное, x конечное и шаг x:");
	while (scanf("%lf %lf %lf", &xn, &xk, &dx) < 3 || (xn > xk && dx > 0) || (xn < xk && dx < 0)) // Вводим данные и проверяем на выполнимость программы
	{
		system("cls");
		while (getchar() != '\n');
		puts("Вы ввели что-то не так\nСкорее всего вы вышли за область определения или с x начального нельзя дойти до x конечного");
		puts("Введите значение x нач., x кон. и шаг x заново:");
	}

	x = xn;

	puts("|---|-------|-------|---------------|\n| # |   x   |   y   |   # Формулы   |\n|---|-------|-------|---------------|");

	for (int i = 0; i <= abs(((xk - xn) / dx)); i++) // Вычисляем y
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