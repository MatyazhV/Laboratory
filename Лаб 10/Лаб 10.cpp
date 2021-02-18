#include <string>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите кол-во строк: ";
	cin >> n;
	string* a = new string[n];
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << " строку" << endl;
		getline(cin, a[i]);
	}
	int j = 0;
	while (j < n)
	{
		if (a[j][0] == 'a'|| a[j][0] == 'A')
		{
			for(int i = j;i<n - 1;i++)
			{
				a[i] = a[i + 1];
			}
			n--;
		}
		else
		{
			j++;
		}
	}
	cout << "Массив после удаления: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	delete[]a;
}
