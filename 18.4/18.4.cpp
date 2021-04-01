#include <iostream> 
#include "Person.h" 
#include "employee.h"
using namespace std;
void f1(employee &c)
{
c.Set_name("Alex");
cout << c;
}
employee f2()
{
	employee l("Valera", 25, "singer", 80000);
	return l;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	Person a;
	cin >> a; 
	cout << a;
	Person b("Vasya", 40);
	cout << b;
	cout << "Копировани b в а" << endl;
	a = b; 
	cout << a;
	employee c;
	cin >> c; 
	cout << c;
	double y;
	cout << "Введите процент премии от оклада: ";
	cin >> y;
	c.calcul_salary(y);
	cout << "Премия + оклад" << endl;
	cout << c;
	cout << "Изменение поля имени" << endl;
	f1(c);
	c = f2(); 
	cout << "Изменение всех полей" << endl;
    cout<<c;
}
