#pragma once 
#include <iostream>
using namespace std;
const int MAX_SIZE = 30;
class List
{
	int size;
	int* beg;
public:
	List() { size = 0; beg = 0; }
	List(int s);
	List(int s, int* mas);
	List(const List& v);
	~List();
	const List& operator=(const List& v);
	int operator[](int i);
	List operator+(int a);
	friend List& operator+(List& x, List& y);
	friend ostream& operator<<(ostream& out, const List& v);
	friend istream& operator>>(istream& in, List& v);
};
