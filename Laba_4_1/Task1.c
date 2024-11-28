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

	puts("Введите a:");

	while (scanf("%lf", &a) != 1) // Проверка a на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	puts("Введите b:");

	while (scanf("%lf", &b) != 1) // Проверка b на ввод
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, введите значение заново");
	}

	puts("Введите x начальное:");

	while (scanf("%lf", &xn) != 1 || (xn == 2) || (xn == -1) || (xn == 0)) // Проверка x начального на ввод и область определения
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, возможно ваше значение не удовлетворяет области определения \nВведите значение заново");
	}

	puts("Введите x конечное:");

	while (scanf("%lf", &xk) != 1 || (xk == 2) || (xk == -1) || (xk == 0) || (xk == xn)) // Проверка x конечного на ввод и область определения
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, возможно ваше значение не удовлетворяет области определения или оно равно начальному\nВведите значение заново");
	}

	puts("Введите шаг x:");

	while ((scanf("%lf", &dx) != 1) || (xn > xk && dx > 0) || (xn < xk && dx < 0)) // Проверка шага x на ввод и выполнение программы
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, возможно с введённым шагом не удастся дойти до конечного значения x\nВведите другой шаг:");
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
		printf("%2d | x = %5.1lf | y = %5.5lf\n", i + 1, x, y);
	}
	else
	{
		while (abs((xk - xn) / dx) >= i)
		{
			y = exp(-x) * (a + b * x) / (log(abs(x + 1)) * log(abs(x + 1)));
			printf("%3d | x = %5.1lf | y = %5.15lf\n", i + 1, x, y);
			i++;
			x += dx;
		}
	}

	system("pause");
}