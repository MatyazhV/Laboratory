
#include <iostream>
using namespace std;
int n, n1,i;
void nok(int a, int b, ...)
{
    a -= 1;
    int* ptr = &b;
    i = *ptr;
    while (a > 0)
    {
        n1 = i;
        ptr++;
        n = *ptr;
        while (i % n1 != 0 || i % n != 0)
        {
            i++;
        }
        a--;
    }
    cout << i << endl;
}
int main()
{
    cout << "For 3 numbers" << endl;
    nok(3, 280, 30, 15);
    cout << "For 5 numbers" << endl;
    nok(5, 6, 360, 48, 288, 24);
    cout << "For 6 numbers" << endl;
    nok(6, 44, 32, 60, 64, 128, 256);
}

