
#include <iostream>
using namespace std;
int n,k,kol = 0;
int a[200];
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Введите размер массива" << endl;
    cin >> n;
    cout << "Введите K элемент массива" << endl;
    bool flag = false;
    while (flag == false)
    {
        cin >> k;
        if (k < n && k >= 0)
        {
            flag = true;
        }
        else
        {
            cout << " k больше размера массива, введите другое значение k " << endl;
        }
    }
    int j = k;
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100 - 100;
            cout << a[i] << " ";
        }
        cout << endl;
        cout << "Массив от К до К-1" << endl;
        flag = false;
        while (flag == false)
        {
            cout << a[j] << " ";
            j++;
            if (j == n)
            {
                j = 0;
            }
            if (j == k)
            {
                flag = true;
            }
        }
        cout << endl;
        for (int i = n; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = rand() % 100 - 50;
        a[n + 1] = rand() % 100 - 50;
        cout << "Массив от К до К-1 после добавления" << endl;
        j = k;
        flag = false;
        while (flag == false)
        {
            cout << a[j] << " ";
            j++;
            if (j == n + 2)
            {
                j = 0;
            }
            if (j == k)
            {
                flag = true;
            }
        }
        cout << endl;
        int b[200];
        int newsize = 0;
        for (int i = 0; i < n + 2; i++)
        {
            if (a[i] % 2 != 0)
            {
                b[newsize] = a[i];
                newsize++;
            }
        }
        flag = false;
        if (k >= newsize)
        {
            while (flag == false)
            {
                cout << "Введите новое значение k" << endl;
                cin >> k;
                if (k >= 0 && k < newsize )
                {
                    flag = true;
                }
            }
        }
        cout << "Массив после удаления от k до k-1 " << endl;
        j = k;
        flag = false;
        while (flag == false)
        {
            cout << b[j] << " ";
            j++;
            if (j == newsize)
            {
                j = 0;
            }
            if (j == k)
            {
                flag = true;
            }
        }
}
