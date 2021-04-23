#pragma once
#include <iostream> 
#include <deque> 
#include <stack> 
#include <cstdlib>
using namespace std;
template <class T>
class List
{
public:
	List(int n);
	T Srednee();
	List(const List<T>& a);
	~List() {};
	void print();
	void del();
	void max();
	void plus();
private:
	int size;
	stack <T> s;
};

template <class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++) 
	{
		cin >> a;
		s.push(a);
	}
	size = s.size();
}

template <class T>
List<T>::List(const List& a)
{
	size = s.size;
	deque<T> v=copy_to_qe(a.s); 
	s=copy_to_st(v);
}
template <class T>
void List<T>::print()
{
	deque<T> v = copy_to_qe(s);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	s=copy_to_st(v);
}
template<class T>
T List<T>::Srednee()
{
	deque<T> v = copy_to_qe(s);
	int n = 1;
	T sum = s.top();
	s.pop();
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
		n++;
	}
	s = copy_to_st(v);
	return sum / n;
}
template<class T>
void List<T>::del()
{
	T key;
	cout << "key?" << endl;
	cin >> key;
	deque<T> v = copy_to_qe(s);
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
	s = copy_to_st(v);
}
template <class T>
void List<T>::max()
{
	T m = s.top();
	deque<T> v = copy_to_qe(s);
	while (!s.empty())
	{
		if (m < s.top())
			m = s.top();
		s.pop();
	}
	s = copy_to_st(v);
	s.push(m);
}
template <class T>
void List<T>::plus()
{
	T sr = Srednee();
	deque<T> v = copy_to_qe(s);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += sr;
	}
	s = copy_to_st(v);
}
template <class T>
deque<T> copy_to_qe(stack<T> s)
{
	deque<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
template <class T>
stack<T> copy_to_st(deque<T> v)
{
	stack<T> s;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		s.push(v[i]);
	}
	return s;
}