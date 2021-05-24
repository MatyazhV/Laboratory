#include "set"
#include "vector"
#include "Pair.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef set<Pair> T;
typedef T::iterator it;
Pair s;

struct plus1
{
	Pair operator()(Pair х)
	{
		return х + s;
	}
};

struct Equal_s
{
	bool operator()(Pair t)
	{
		return t == s;
	}
};

Pair srednee(T v)
{
	Pair s;
	//перебор словаря
	for (it i = v.begin(); i != v.end(); ++i)
		s + *i;
	int n = v.size();//количество элементов в словаре 
	return s / n;
}

T make_map(int n)
{
	T m;//пустой словарь 
	for (int i = 0; i != n; i++)
	{
		Pair a;
		//создаем пару и добавляем ее в словарь 
		m.insert(a);
	}
	return m;//возвращаем словарь как результат работы функции
}
void print_map(T m)
{
	for (it i = m.begin(); i != m.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

void main()
{
	int n;
	cout << "N?";
	cin >> n;
	T v;
	v = make_map(n);
	print_map(v);
	it i;
	i = max_element(v.begin(), v.end());
	cout << "Max: "<< *i << endl;
	print_map(v);
	cout << "key?" << endl;
	cin >> s;
	remove(v.begin(), v.end(), s);
	s = srednee(v);
	for_each(v.begin(), v.end(), plus1());
	print_map(v);
}
