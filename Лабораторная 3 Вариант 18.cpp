
#include <iostream>
using namespace std;
int n, sr, sum, kol, k, s;
int main()
{
    setlocale(LC_ALL, "Rus");
    sum = 0;
    sr = 0;
    cout << "Введите размер массива: ";
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100 - 50;
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << endl;
    sr = sum / n;
    cout << "Среднее арифметическое: " << sr << endl;
    kol = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > sr)
        {

            kol += 1;
        }
    }
    cout << "Количество чисел больших среднего арифметического: " << kol << endl;
    for (int i = 0; i < n; i++)
    {
        while (a[i] > sr)
        {
            for (int j = i; j < n; j++)
                a[j] = a[j + 1];
        }
    }
    cout << "Массив после удаления: " << endl;
    for (int i = 0; i < (n - kol); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Сколько чисел добавить? " << endl;
    cin >> k;
    for (int i = n - kol; i < (k + n); i++)
    {
        a[i] = rand() % 100 - 50;
    }
    cout << "Массив после добавления: " << endl;
    for (int i = 0; i < (k + n - kol); i++)
    {
        cout << a[i] << " ";
    }
    s = 0;
    if ((k + n - kol) % 2 == 0)
    {
        for (int i = 0; i < (k + n - kol); i++)
        {
            if (i % 2 == 0)
            {
                s = a[i];
                a[i] = a[i + 1];
            }
            else
                a[i] = s;
        }
    }
    else
    {
        for (int i = 0; i < (k + n - kol - 1); i++)
        {
            if (i % 2 == 0)
            {
                s = a[i];
                a[i] = a[i + 1];
            }
            else
                a[i] = s;
        }
    }
    cout << endl;
    cout << "Массив после перестановки: " << endl;
    for (int i = 0; i < (k + n - kol); i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Первое отрицательное число: ";
    bool flag = false;
    int i = 0;
    while (flag == false)
    {
        if (a[i] < 0)
        {
            cout << a[i] << " ";
            flag = true;
        }
        i++;
    }
    cout << "Кол-во сравнений: " << i++ << endl;
    int  j, x;
    for (i = 1; i < (k + n - kol); i++)
    {
        x = a[i];
        j = i - 1;
        while (x < a[j] && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
    }
    cout << "Массив после сортировки: " << endl;
    for (int i = 0; i < (k + n - kol); i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Первый отрицательный элемент в отсортированом массиве: ";
    x = 0;
    flag = false;
    while (flag == false)
    {
        if (a[x] < 0)
        {
            cout << a[x] << " ";
            flag = true;
        }
        x++;
    }
    cout << "Кол-во сравнений: " << x++ << endl;
    return 0;
}