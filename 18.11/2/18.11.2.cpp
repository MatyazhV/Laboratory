#include <iostream> 
#include "Pair.h"
#include <deque> 
#include <cstdlib> 
using namespace std;
typedef deque<Pair>que;
void make_deque(que& v,int n)
{
	if (n <= 0)
		throw 1;
	for (int i = 0; i < n; i++)
	{
		Pair a;
		cin >> a;
		v.push_back(a);
	}
}
void print_deque(que v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
Pair srednee(que v)
{
	Pair s;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	return s / n;
}

void maxadd(que& v)
{
	Pair m = v[0];
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
		}
	v.push_back(m);
}
void del_deque(que& v)
{
	Pair key;
	cout << " key?" << endl;
	cin >> key;
	bool k = 0;
	int n = v.size();
	int i = 0;
	while (i < n)
	{
		if (key == v[i])
		{
			v.erase(v.begin() + i);
			n--;
			k = 1;
		}
		else
			i++;
	}
	if (!k)
	{
		cout << "This item wasn't found" << endl;
	}
}

void plus1(que& v)
{
	Pair el = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] += el;
}

int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		deque<Pair> q;
		deque<Pair>::iterator vi = q.begin();
		int n;
		cout << "N?";
		cin >> n;
		make_deque(q,n);
		cout << "Очередь: " << endl;
		print_deque(q);
		maxadd(q);
		cout << "Очередь после добавления: " << endl;
		print_deque(q);
		del_deque(q);
		cout << "Очередь после удаления: " << endl;
		print_deque(q);
		plus1(q);
		cout << "Очередь после добавления элементам среднего арифметического: " << endl;
		print_deque(q);
	}
	catch (int)
	{
		cout << "error!";
	}
}