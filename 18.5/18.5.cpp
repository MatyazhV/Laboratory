#include "Object.h"
#include "Person.h"
#include <iostream>
#include "Employee.h"
#include "Vector.h"
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    Vector v(5);
    Person a;
    cin >> a;
    employee b;
    cin >> b;
    Object* p = &a;
    cout << "Просмотр объектов класса Person через указатель " << endl;
    p->Show();
    v.Add(p);
    p = &b;
    cout << "Просмотр объектов класса employee через указатель " << endl;
    p->Show();
    v.Add(p);
    cout << "Содержание вектора " << endl;
    cout << v;
    return 0;
}