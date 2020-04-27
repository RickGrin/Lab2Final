#include <iostream>
#include "Windows.h"
#include <time.h>
using namespace std;
void show(int** x, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}
void clear(int** x, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = 0;
}
void fillRandom(int** x, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = rand() % 2;
}
int pos[2][8] = { {1, 1, 1, 0, 0, -1, -1, -1}, {1, 0, -1, 1, -1, 1, 0, -1} };

void live(int** x, int n)
{
    int tmpi = 0;
    int tmpj = 0;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                tmpi = i + pos[0][k];
                tmpj = j + pos[1][k];
                if (tmpi < 0) tmpi = n - 1;
                else if (tmpi >= n) tmpi = 0;
                if (tmpj < 0) tmpj = n - 1;
                else if (tmpj >= n) tmpj = 0;
                g += x[tmpi][tmpj];
                //cout << pos[0][k] << " " << tmpi <<endl;
                //cout << pos[1][k] << " " << tmpj <<endl;
                //cout << endl;
            }
            if (x[i][j] == 1)
            {
                if ((g > 3) || (g < 2))
                {
                    x[i][j] = 0;
                }
            }
            else
            {
                if (g == 3)
                {
                    x[i][j] = 1;
                }
            }
            g = 0;
        }
    }
}
int main()
{
    int** arr = new int* [10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = new int[10];
    }
    clear(arr, 10);
    fillRandom(arr, 10);
    for (int i = 0; i < 1000; i++)
    {
        system("cls");
        live(arr, 10);
        show(arr, 10);
        Sleep(1000);
    }

    for (int i = 0; i < 10; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    system("pause");
    return 0;
}