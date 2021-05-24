#include "stack"
#include "vector"
#include "Pair.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef stack<Pair> T;
typedef deque<Pair> dq;
Pair s;

struct plus1
{
	Pair operator()(Pair& х)
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

Pair srednee(dq v)
{
	Pair s;
	int n = v.size();
	while(!v.empty())
	{
		s += v.front();
		v.pop_front();
	}
	return s / n;
}

T make_vector(int n)
{

	T v;
	for (int i = 0; i < n; i++)
	{
		Pair a;
		v.push(a);
	}
	return v;
}
void print_vector(T v)
{
	while(!v.empty())
	{
		cout << v.top() << endl;
		v.pop();
	}
	cout << endl;
}
T copy_to_stack(dq k)
{
	T s;
	for(int i = 0;i<k.size();i++)
	{
		s.push(k[i]);
	}
	return s;
}

dq copy_to_dq(T k)
{
	dq s;
	while (!k.empty())
	{
		s.push_back(k.top());
		k.pop();
	}
	return s;
}
void main()
{
	int n;
	cout << "N?";
	cin >> n;
	T v;
	v = make_vector(n);
	print_vector(v);
	dq q = copy_to_dq(v);
	dq::iterator i;
	i = max_element(q.begin(), q.end());
	Pair m = *(i);
	q.push_back(m);
	v = copy_to_stack(q);
	print_vector(v);
	cout << "key?" << endl;
	cin >> s;
	remove(q.begin(), q.end(), s);
	v = copy_to_stack(q);
	print_vector(v);
	s = srednee(q);
	for_each(q.begin(), q.end(), plus1());
	v = copy_to_stack(q);
	print_vector(v);
}
