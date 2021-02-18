#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
int n;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите кол-во строк: ";
	cin >> n;
	cin.ignore();
	ofstream f1("F1.txt");
	if (!f1.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		f1 << str << "\n";
	}
	f1.close();
	ifstream file("F1.txt");
	if (!file.is_open())
	{
		cout << "Файл не открыт" << endl;
		return 0;
	}
	cout << "Содержание файла F1" << endl;
	for (int i = 0; i < n; i++)
	{
		getline(file, str);
		cout << str << endl;
	}
	file.close();
	ifstream f("F1.txt");
	ofstream f2("F2.txt");
	if (!f.is_open() && !f2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		getline(f, str);
		string s;
		string arr[50];
		stringstream str_word(str);
		int j = 0;
		while (str_word >> s)
		{
			arr[j] = s;
			j++;
		}
		bool flag = false;
		for (int q = 0; q < j; q++)
		{
			for(int k = q + 1; k < j;k++)
			{
				if (arr[q] == arr[k])
				{
					flag = true;
					g++;
				}
			}
		}
		if (flag == false)
		{
			f2 << str << "\n";
		}
	}
	f.close();
	f2.close();
	ifstream F2("F2.txt");
	if (!F2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	n -= g;
	cout << "Содержание файла F2" << endl;
	for (int i = 0; i < n; i++)
	{
		getline(F2, str);
		cout << str << endl;
	}
	F2.close();
	ifstream file2("F2.txt");
	if (!file2.is_open())
	{
		cout << "Файлы не открыт	" << endl;
		return 0;
	}
	getline(file2, str);
	 g = 0;
	for (auto c : str)
	{
		switch (c)
		{
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'y': case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y': g++;
		}
	}
	cout << "Кол-во гласных в первой строке: " << g << endl;
	file2.close();
	return 0;
}