#include <locale>
#include <iostream>
#include <ctime>
using namespace std;
const int n = 4;
int i, j, m, k;
double aa, bb;
double a[n][n + 1] = 
{{  31,   1, -91, 1, -141},   //матрица коэффициентов, где последний столбец - правая часть системы
 {-11, -11,  31, -11, 41},
 {-21, -11,  71, 1, 141},
 {  1,  1, -1, -1, -51} };
void main()
{
 
    setlocale(LC_ALL, "Russian");
    double* x;
    x = (double*)malloc(n * sizeof(double));
    for (k = 0; k < n; k++) //Поиск максимального элемента в первом столбце
    {
        aa = abs(a[k][k]);
        i = k;
        for (m = k + 1; m < n; m++)
            if (abs(a[m][k]) > aa)
            {
                i = m;
                aa = abs(a[m][k]);
            }
        if (aa == 0)   //проверка на нулевой элемент
        {
            cout << "Система не имеет решений" << endl;
        }

        if (i != k)  //  перестановка i-ой строки, содержащей главный элемент k-ой строки
        {
            for (j = k; j < n + 1; j++)
            {
                bb = a[k][j];
                a[k][j] = a[i][j];
                a[i][j] = bb;
            }
        }
        aa = a[k][k];//преобразование k-ой строки (Вычисление масштабирующих множителей)
        a[k][k] = 1;
        for (j = k + 1; j < n + 1; j++)
            a[k][j] = a[k][j] / aa;
        for (i = k + 1; i < n; i++)//преобразование строк с помощью k-ой строки
        {
            bb = a[i][k];
            a[i][k] = 0;
            if (bb != 0)
                for (j = k + 1; j < n + 1; j++)
                    a[i][j] = a[i][j] - bb * a[k][j];
        }
    }
    for (i = n - 1; i >= 0; i--)   //Нахождение решений СЛАУ
    {
        x[i] = 0;
        aa = a[i][n];
        for (j = n; j > i; j--)
            aa = aa - a[i][j] * x[j];
        x[i] = aa;
    }
    cout << "Решение системы:" << endl;  //вывод решений
    int t = clock();
    cout << ((float)t) / CLOCKS_PER_SEC << " секунд.n" << endl;
   
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "]=" << x[i];
        
        cout << endl;
     
       
    }
    system("PAUSE");
}