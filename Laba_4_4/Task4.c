#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	puts("Введите натуральное число n:");

	int n, product = 1;

	while (scanf("%d", &n) != 1 || n < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не то, введите натуральное число заново:");
	}

	while (n != 0)
	{
		product *= n % 10;
		n /= 10;
	}

	printf("Произведение цифр вашего натурального числа равно %d\n", product);

	system("pause");
}