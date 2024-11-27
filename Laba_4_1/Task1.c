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

	puts("Введите a:");

	while (scanf("%lf", &a) < 1) // Проверка a на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	puts("Введите b:");

	while (scanf("%lf", &b) < 1) // Проверка b на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	puts("Введите x начальное:");

	while (scanf("%lf", &xn) < 1) // Проверка x начального на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	while ((xn == 2) || (xn == -1) || (xn == 0)) // Проверка x начального на недопустимые значения
	{
		while (getchar() != '\n');
		puts("x начальное не может равняться 0 / -1 / 2\nВведите другое x начальное:");
	}

	puts("Введите x конечное:");

	while (scanf("%lf", &xk) < 1) // Проверка x конечного на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	while ((xk == xn) || (xk == 2) || (xk == -1) || (xk == 0)) // Проверка x  конечного на соответствие с x начальным и недопустимые значения
	{
		while (getchar() != '\n');
		puts("По всей видимости x конечное равно x начальному или x конечное не соответсвует области определения\nВведите другое x конечное");
	}

	puts("Введите шаг x:");

	int ok = 1;

	while (ok) // Проврерка шага x
	{
		if ((scanf("%lf", &dx) == 1)) 
		{
			while ((xn > xk && dx > 0) || (xn < xk && dx < 0))
			{
				while (getchar() != '\n');
				puts("У вас не крутой шаг, введите другой:");
				while ((scanf("%lf", &dx) != 1))
				{
					while (getchar() != '\n');
					puts("Вы ввели что-то не так, введите значение заново:");
				}
			}
			ok = 0;
		}
		else 
		{
			while (getchar() != '\n');
			puts("Вы ввели что-то не так, введите значение заново:");
		}
	}

	x = xn;

	while (abs((xk - xn) / dx) >= i) // Проверка всего промежутка
	{
		if ((x == 2) || (x == -1) || (x == 0))
		{
			puts("При введенных данных на промежутке присутствуют недопустимые значения\nВведите шаг заново или закройте программу и запустите её заново для повторного ввода переменных");
			dx = 0;
			while ((scanf("%lf", &dx) < 1) || (xn > xk && dx > 0) || (xn < xk && dx < 0))
			{
				puts("Вы ввели что-то не так, введите значение заново");
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

	printf("x нач. = %.1lf; x кон. = %.1lf; шаг x = %.1lf; a = %.1lf; b = %.1lf\n", xn, xk, dx, a, b);

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