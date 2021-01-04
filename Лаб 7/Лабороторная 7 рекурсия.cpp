
#include <iostream>
using namespace std;
int s, num,k;
char a[200];
void ex(int v)
{
    if (v == -1)
    {
        return;
    }
    cout << a[v];
    v--;
    ex(v);
}
void sist(int n, int i)
{
    if (n != 0)
    {
        int c = n % s;
        if (c >= 10 && c <= 35)
        {
            char ost(c + 55);
            a[i] = ost;
            i++;
            k++;
            n /= s;
            sist(n, i);
        }
        else
        {
            char ost(c + 48);
            a[i] = ost;
            i++;
            k++;
            n /= s;
            sist(n, i);
        }
    }
}
int main()
{
    setlocale(LC_ALL, "");
    cout << "Введите число" << endl;
    cin >> num;
    cout << "Введите систему" << endl;
    cin >> s;
    int d = 0;
    sist(num, d);
    k--;
    ex(k);
}