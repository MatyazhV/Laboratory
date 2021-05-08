#pragma once
#include <iostream> 
#include <deque> 
using namespace std;
template <class T>
class List
{
public:
	List(int s);
	T Srednee();
	List(const List<T>& a);
	~List() {};
	void print();
	void del();
	void max();
	void plus(T k);
private:
	int size;
	deque <T> v;
};

template <class T>
List<T>::List(int s)
{
	T a;
	for (int i = 0; i < s; i++)
	{
		cin >> a;
		v.push_back(a);
	}
}

template <class T>
List<T>::List(const List& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
template <class T>
void List<T>::print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "	";
	cout << endl;
}
template<class T>
T List<T>::Srednee()
{
	T s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}
template<class T>
void List<T>::del()
{
	T key;
	cin >> key;
	int n = v.size();
	int i = 0;
	while (i < n)
	{
		if (key == v[i])
		{
			v.erase(v.begin() + i);
			n--;
		}
		else
			i++;
	}
}
template <class T>
void List<T>::max()
{
	T m = v[0];
	for (int i = 0; i < v.size(); i++)
		if (m < v[i])
		{
			m = v[i];
		}
	v.push_back(m);
}
template <class T>
void List<T>::plus(T k)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] + k;
	}
}