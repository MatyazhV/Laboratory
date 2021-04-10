#include "List.h" 
#include <iostream> 
using namespace std; 
int main()
{
	setlocale(LC_ALL, "Rus");
	try
	{
		List a(3);
		List b;
		cin >> a;
		cout<<a;
		cout<<"Nomer?";
		int i; 
		cin >> i;
		cout<<a[i]<<endl;
		b=a;
		b + a;
		cout << a;
		a + 50;
		cout << a;
		a + 1;
		cout << a;
		cout << "Пример вывода ошибки, вызваной из за разных размеров векторов" << endl;
		b + a;
	}
	catch(int)
	{
		cout << "ERROR!!!" << endl;
	}
	return 0;
}


