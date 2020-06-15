#include <iostream>
#include <fstream>
using namespace std;
double gaus(double** a, double b[], int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	int i, j, n, m, k;
	ifstream F1;
	F1.open("var2.txt", ios::in);
	F1 >> n;
	double** a;
	a = new double* [n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n];
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			F1 >> a[i][j];
		}
	}
	double* b = new double[n];
	for (i = 0; i < n; i++)
	{
		F1 >> b[i];
	}
	F1.close();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%8f ", a[i][j]);
		}
		cout << endl;
	}
	gaus(a, b, n);
	delete[] a;

	return 0;
}



double gaus(double** a, double b[], int n)
{
	double* x, max;
	int k, index;
	double t;
	const double eps = 0.0000001;  // точность
	x = new double[n];
	k = 0;
	while (k < n)
	{
		// Поиск строки с максимальным элементом
		max = abs(a[k][k]);
		index = k;
		for (int i = k + 1; i < n; i++)
		{
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				index = i;
			}
		}
		if (max < eps)
		{
			// нет ненулевых диагональных элементов
			cout << "Решение получить невозможно из-за нулевого столбца ";
			cout << index << " матрицы A" << endl;
			return 0;
		}
		// Перестановка строк
		for (int j = 0; j < n; j++)
		{
			t = a[k][j];
			a[k][j] = a[index][j];
			a[index][j] = t;
		}
		t = b[k];
		b[k] = b[index];
		b[index] = t;
		// Основное решение
		for (int i = k; i < n; i++)
		{
			t = a[i][k];
			if (abs(t) < eps) continue; // Если ноль, то пропустить
			for (int j = 0; j < n; j++) a[i][j] = a[i][j] / t;
			b[i] = b[i] / t;
			if (i == k)  continue; // чтобы не произошло ошибки в вычитании
			for (int j = 0; j < n; j++) a[i][j] = a[i][j] - a[k][j];
			b[i] = b[i] - b[k];
		}
		k++;
	}
	// обратная подстановка
	for (k = n - 1; k >= 0; k--)
	{
		x[k] = b[k];
		for (int i = 0; i < k; i++)
			b[i] = b[i] - a[i][k] * x[k];
	}
	for (int i = 0; i < n; i++) cout << x[i] << " ";
	cout << endl;
}
