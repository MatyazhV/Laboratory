#include <iostream>
#include <string>
using namespace std;
int n;
string s;
int a[200];
void  max1(int* g)
{
	int m = g[0];
	for (int i = 0; i < n; i++)
	{
		if (g[i] > m)
		{
			m = g[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << g[i] << " ";
	}
	cout << endl;
	cout << m;
}
void max1(string g)
{
	int long1 = 0;
	int d = 0;
	for (auto c : g)
	{
		if (c != ' ') 
		{
			d++;
		}
		if (d > long1)
		{
			long1 = d;
		}
		if (c == ' ') 
		{
			d = 0;
		}
	}
	cout << "Длина самого длиного слова: "<< long1 << endl;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите строку" << endl;
	getline(cin, s);
	max1(s);
	cout << "Введите длинну массива n" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 - 50;
	}
	max1(a);
}