#include <iostream>
using namespace std;
int n, imax,jmax;
int a[200][200];
int b[200];
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введиите размер массива " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 100 - 50;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n ; i++)
    {
        imax = i;
        jmax = 0;
        for (int k = i; k < n; k++)
        {
            for (int j = 0; j < n - i; j++)
            {
                if (a[k][j] > a[imax][jmax])
                {
                    imax = k;
                    jmax = j;
                }
            }
        }
        if (imax > i)
        {
            for (int j = 0; j < n; j++)
            {
                b[j] = a[imax][j];
            }
            for (int k = imax; k > i; k--)
            {
                for (int j = 0; j < n; j++)
                {
                    a[k][j] = a[k - 1][j];
                }
            }
            for (int j = 0; j < n; j++)
            {
                a[i][j] = b[j];
            }
        }
        if (jmax < n - i - 1)
        {
            for (int k = 0; k < n; k++)
            {
                b[k] = a[k][jmax];
            }
            for (int j = jmax; j < n - i - 1; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    a[k][j] = a[k][j + 1];
                }
            }
            for (int k = 0; k < n; k++)
            {
                a[k][n - i - 1] = b[k];
            }
        }
    }
    cout << "Массив после пересьановки" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    bool flag = false;
    int m = 1;
    while (m < n && flag == false)
    {
        if ( a[m][n - m - 1] >= a[m - 1][n - m])
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
    return 0;
}