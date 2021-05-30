#include "ABITURIENT.h"
#include<iostream>
ABITURIENT::ABITURIENT(void) :Person()
{
	p = 0;
	s = "";
}
ABITURIENT::~ABITURIENT(void)
{
}
ABITURIENT::ABITURIENT(string T, int A, int L,string q) :Person(T, A)
{
	p = L;
	s = q;
}
ABITURIENT::ABITURIENT(const ABITURIENT& M)
{
	name = M.name;
	age = M.age;
	p = M.p;
}
void ABITURIENT::Set_p(int L)
{
	p = L;
}
void ABITURIENT::Set_s(string L)
{
	s = L;
}
ABITURIENT& ABITURIENT::operator=(const ABITURIENT& l)
{
	if (&l == this)return *this;
	name = l.name;
	age = l.age;
	return *this;
}
void ABITURIENT::Show()
{
	cout << "\ntitle : " << name;
	cout << "\nauthor : " << age;
	cout << "\npoints : " << p;
	cout << "\nspec : " << s;
	cout << "\n";
}
void ABITURIENT::Input()
{
	cout << "\nname:";
	cin >> name;
	cout << "\nage:";
	cin >> age;
	cout << "\npoint";
	cin >> p;
	cout << "\nspec";
	cin >> s;
}