#include "Vector.h"
#include "Pair.h"
#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	List<int>a(5,0);
	cin >> a; 
	cout << "Инициализация а" << endl;
	cout << a << endl; 
	List <int>b(10,0);
	b=a;
	cout << "b присвоили а" << endl;
	cout << b << endl;
	a += b;
	cout << "списку а прибавили список b: "<< a << endl;
	cout << "Доступ по номеру "<< a[2]<<endl;
	b=a+10;
	cout << "Прибавили списку а константу и присвоили списку b" << endl;
	cout << b << endl;
	Pair c;
	cin >> c;
	List<Pair> A(5, c);
	cin >> A;
	cout << "Инициализация списка А" << endl;
	cout << A << endl;
	List <Pair>B(10, c);
	cout << "b присвоили а" << endl;
	B = A;
	cout << B << endl; 
	cout << "Доступ по номеру " << A[2] << endl;
	B += A;
	cout << B << endl;
	B = A + c;
	cout << "Прибавили списку а константу и присвоили списку b" << endl;
	cout << B << endl;
}
