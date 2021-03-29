#pragma once
#include <iostream> 
using namespace std;
class Pair
{
int first;
double second;
public:
	Pair() {
		first = 0; 
		second = 0.0; 
	};
	Pair(int m, int s) {
		first = m; 
		second = s; 
	} 
	Pair(const Pair& t)
	{ 
		first = t.first; 
		second = t.second; 
	}
	~Pair() {};
	int get_f() { 
		return first;
	} 
	int get_sec() { 
		return second; 
	} 
	void set_f(int m) 
	{ 
		first = m; 
	} 
	void set_sec(int s) { 
		second = s;
	}
	Pair&operator=(const Pair&);
	bool operator<(const Pair&);
	bool operator>(const Pair&);
	Pair operator--(int); 
	Pair& operator--();
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
};
