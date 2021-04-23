#include <iostream> 
#include "Pair.h"
#include "List.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	List<Pair>l(3);
	cout <<" Стэк: "<< endl;
	l.print();
	l.max();
	cout <<endl<< "После добавления: " <<endl;
	l.print();
	cout << endl;
	l.del();
	cout <<"После удалеиня: " << endl;
	l.print();
	l.plus();
	cout << endl <<"После прибавдения: "<< endl;
	l.print();
}

