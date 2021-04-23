#include <iostream> 
#include "Pair.h"
#include <deque> 
#include <stack> 
#include <cstdlib>
using namespace std;
typedef stack<Pair>St;
typedef deque<Pair>qe;
St make_stack(int n)
{
	St s;
	Pair t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.push(t);
	}
	return s;
}

qe copy_to_qe(St s)
{
	qe v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v; 
}

St copy_to_st(qe v)
{
	St s;
	for (int i = v.size()-1; i >= 0; i--)
	{
		s.push(v[i]);
	}
	return s; 
}

Pair Srednee(St s)
{

	qe v = copy_to_qe(s);
	int n=1;
	Pair sum = s.top();
	s.pop();
	while(!s.empty())
	{
		sum += s.top();
		s.pop();
		n++;
	}
	return sum/n; 
}

void Max(St& s)
{
	Pair m = s.top();
	qe v = copy_to_qe(s);
	while(!s.empty())
	{
		if (m < s.top())
			m = s.top();
		s.pop();
	}
	s = copy_to_st(v);
	s.push(m);
}

void Delete(St& s)
{
	Pair key;
	cout << "key?" << endl;
	cin >> key;
	qe v = copy_to_qe(s);
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
void plus1(St& s)
{
	Pair sr = Srednee(s);
	qe v = copy_to_qe(s);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += sr;
	}
	s = copy_to_st(v);
}

void print_stack(St s)
{
	qe v = copy_to_qe(s);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Pair t; 
	St s; 
	int n;
	cout << "n? "; 
	cin >> n;
	s = make_stack(n);
	cout << endl << "Стэк: "<<endl;
	print_stack(s);
	Max(s);
	cout << endl << "После добавления: "<< endl;
	print_stack(s);
	cout << endl << "После удаления: "<< endl;
	Delete(s);
	cout << endl;
	print_stack(s);
	plus1(s);
	cout << endl << " После добавления ср. арифметического: "<<endl;
	print_stack(s);
}