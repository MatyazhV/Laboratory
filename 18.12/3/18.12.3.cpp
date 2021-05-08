#include <iostream>
#include "List.h"
#include "Pair.h"
typedef List<Pair> lst;
using namespace std;
int main()
{
    int n;
    cin >> n;
    lst l(n);
    l.print();
    l.max();
    l.print();
    l.del();
    l.print();
    Pair k = l.Srednee();
    l.plus(k);
    l.print();
}

