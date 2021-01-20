#include <iostream>
using namespace std;
int n;
void m(int** g, int* b, int u)
{
    for (int i = 0; i < u; i++)
    {
        int imax = i;
        int jmax = 0;
        for (int k = i; k < u; k++)
        {
            for (int j = 0; j < u - i; j++)
            {
                if (g[k][j] > g[imax][jmax])
                {
                    imax = k;
                    jmax = j;
                }
            }
        }
        if (imax > i)
        {
            for (int j = 0; j < u; j++)
            {
                b[j] = g[imax][j];
            }
            for (int k = imax; k > i; k--)
            {
                for (int j = 0; j < u; j++)
                {
                    g[k][j] = g[k - 1][j];
                }
            }
            for (int j = 0; j < u; j++)
            {
                g[i][j] = b[j];
            }
        }
        if (jmax < u - i - 1)
        {
            for (int k = 0; k < u; k++)
            {
                b[k] = g[k][jmax];
            }
            for (int j = jmax; j < u - i - 1; j++)
            {
                for (int k = 0; k < u; k++)
                {
                    g[k][j] = g[k][j + 1];
                }
            }
            for (int k = 0; k < u; k++)
            {
                g[k][u - i - 1] = b[k];
            }
        }
    }
    cout << "Массив после пересьановки" << endl;
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    bool flag = false;
    int m = 1;
    while (m < u && flag == false)
    {
        if (g[m][u - m - 1] >= g[m - 1][u - m])
        {
            flag = true;
        }
        else
        {
            m++;
        }
    }
    if (flag == true)
    {
        cout << " На побочной диагонали не убывающая последовательность " << endl;
    }
    else
    {
        cout << "На побочной диагонали убывающая последовательность " << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введиите размер массива " << endl;
    cin >> n;
    int** a = new int* [n];
    int* b = new int [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    m(a, b, n);
    return 0;
}
