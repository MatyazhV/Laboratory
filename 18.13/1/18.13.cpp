#include "deque"
#include "Pair.h"
#include <iostream>
#include <algorithm>
using namespace std;
typedef deque<Pair> TVector;
Pair s;

struct plus1 
{
	Pair operator()( Pair& х) 
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

Pair srednee(TVector v)
{
	Pair s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s/n;
}

TVector make_vector(int n)
{
	
	TVector v;
	for (int i = 0; i < n; i++)
	{
		Pair a;
		v.push_back(a);
	}
	return v;
}
void print_vector(TVector v)
{
	for (int i = 0; i < v.size(); i++)

		cout << v[i] << endl; 
	cout<< endl;
} 

int main()
{
	int n;
	cout << "N?";
	cin >> n;
	TVector v;
	v = make_vector(n);
	print_vector(v);
	TVector::iterator i;
	i = max_element(v.begin(), v.end());
	cout << "max=" << *(i) << endl;
	Pair m = *(i);
	v.push_back(m);
	print_vector(v);
	cout << "key?" << endl;
	cin >> s;
	remove(v.begin(), v.end(), s);
	print_vector(v);
	s = srednee(v);
	for_each(v.begin(), v.end(), plus1());
	print_vector(v);
}
