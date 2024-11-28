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

	int n, k = 0, kf;
	double a, b, h, x, Y, S = 0, fact = 1;

	puts("������� a (��������� ��������), b (�������� ��������), h (���), � n (������� ������� ������������):");
	while (scanf("%lf %lf %lf %d", &a, &b, &h, &n) != 4 || (a > b && h > 0) || (a < b && h < 0) || n < 1)
	{
		system("cls");
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���\n������ ����� �� �������� a ������ ����� �� �������� b ��� n < 1\n������� �������� a, b, h � n ������:");
	}

	x = a;

	for (int i = 0; i <= abs((b - a) / h); i++) // ��������
	{
		Y = (exp(x) + exp(-x)) / 2; // ��������� Y
		for (k; k <= n; k++) // ������� S
		{
			kf = 2*k;
			for (kf; kf > 1; kf--) // ������� ���������
			{
				fact *= kf;
			}
			S += pow(x, 2 * k) / fact; // ���������� �����
			fact = 1; // �������� ��������� � �������
		}
		printf("%3d | x = %5.2lf | Y = %-20.10lf | S = %.10lf\n", i + 1, x, Y, S); // ������� ��������
		x += h; // ����������� x �� ���
		k = 0; // �������� ������� ��� �����
		S = 0; // �������� �����
	}

	system("pause");
}