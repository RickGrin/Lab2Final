
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian"); bool prov = false;
    int* D; int* B; int** A; int** C;
    char buff[50]; float T;
    int n1, i = 0, j = 0, i1 = 0, j1 = 0, i2 = 0, j2 = 0, i3 = -1, i4 = -1, n, m, rez; ofstream fout; ifstream abc;
    abc.open("1.txt");
    while (!abc.eof())
    {
        abc.getline(buff, 50); i1++;
    }
    abc.close();
    abc.open("1.txt");
    while (!abc.eof())
    {
        abc >> n1;
        j1++;
    }
    j1 = j1 / i1;
    abc.close();
    abc.open("1.txt");
    A = new int* [i1];// dynamic array
    for (int i = 0; i < i1; i++)
    {
        A[i] = new int[j1];
        for (int j = 0; j < j1; j++)
        {
            abc >> n1;
            A[i][j] = n1;
        }
    }
    abc.close();

    for (int i = 0; i < i1; i++)
    {
        for (int j = 0; j < j1; j++)
        {
            printf("%5d", A[i][j]);
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    abc.open("2.txt");
    while (!abc.eof())
    {
        abc.getline(buff, 50); i2++;
    }

    abc.close();
    abc.open("2.txt");
    while (!abc.eof())
    {
        abc >> n1;
        j2++;
    }
    j2 = j2 / i2;
    abc.close();
    abc.open("4.txt");
    C = new int* [i2];// dynamic array
    for (int i = 0; i < i2; i++)
    {
        C[i] = new int[j2];
        for (int j = 0; j < j2; j++)
        {
            abc >> n1;
            C[i][j] = n1;
        }
    }
    abc.close();

    for (int i = 0; i < i2; i++)
    {

        for (int j = 0; j < j2; j++)
        {
            printf("%5d", C[i][j]);
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;

    abc.open("3.txt");//the number of even numbers
    while (!abc.eof())
    {
        abc >> n1;
        i3++;
    }

    abc.close();
    B = new int[i3];

    abc.open("3.txt");
    for (int i = 0; i < i3; i++)
    {
        abc >> n1;
        B[i] = n1;
    }
    abc.close();

    for (int i = 0; i < i3; i++)
    {
        printf("%5d", B[i]);
    }
    cout << endl << "----------------------------------------" << endl;

    abc.open("4.txt");//the number of even numbers
    while (!abc.eof())
    {
        abc >> n1;
        i4++;
    }

    abc.close();
    D = new int[i4];

    abc.open("2.txt");
    for (int i = 0; i < i4; i++)
    {
        abc >> n1;
        D[i] = n1;
    }
    abc.close();

    for (int i = 0; i < i4; i++)
    {
        printf("%5d", D[i]);
    }
    cout << endl << "----------------------------------------" << endl;
    cout << "i2=" << i2 - 1 << endl;
    cout << "i1=" << i1 - 1 << endl;
    cout << "T = "; cin >> T;
    while (prov == false)
    {

        cout << "enter n not exceeding i1 = "; cin >> n;
        cout << "enter m not over i2 = "; cin >> m;
        if (m < i2 && n < i1) { prov = true; }
        else { cout << "no number" << endl; }
    }
    rez = A[m][m] + 2 * B[m] * pow(D[n], T) * C[n][m];

    cout << "rez = " << rez << endl;
    return 0;
}
