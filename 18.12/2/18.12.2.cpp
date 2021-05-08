#include <iostream> 
#include <set>
#include "Pair.h" 
using namespace std;
typedef set<Pair>TMap;//определяем тип для работы со словарем 
typedef TMap::iterator it;//итератор

//функция для формирования словаря 
TMap make_map(int n)
{
	TMap m;//пустой словарь 
	Pair a;
	for (int i = 0; i != n; i++)
	{
		cin >> a;
		//создаем пару и добавляем ее в словарь 
		m.insert(a);
	}
	return m;//возвращаем словарь как результат работы функции
}
//функция для печати словаря 
void print_map(TMap m)
{
	for (it i = m.begin(); i != m.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

Pair srednee(TMap v)
{
	Pair s;
	//перебор словаря
	for (it i = v.begin(); i != v.end(); ++i)
		s + *i;
	int n = v.size();//количество элементов в словаре 
	return s/n;
}

void plus1(TMap& v)
{
	TMap f;
	Pair el = srednee(v);
	for (it i = v.begin(); i != v.end(); i++)
	{
		Pair k = el + *i;
		f.insert(k);
	}
	v = f;
}

int main()
{
	int n;
	cout << "N?"; 
	cin >> n; 
	TMap m = make_map(n); 
	print_map(m); 
	cout << "Max: " << *(m.rbegin()) << endl;
	Pair key;
	cin >> key;
	m.erase(key);
	print_map(m);
	plus1(m);
	print_map(m);
}