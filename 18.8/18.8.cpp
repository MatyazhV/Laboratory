#include"Person.h"
#include"ABITURIENT.h"
#include"Object.h"
#include"v.h"
#include"dialog.h"
#include<iostream>
using namespace std;

void main()
{
	Person* a = new Person;
	a->Input();
	ABITURIENT* b = new ABITURIENT;
	b->Input();

	List v(4);
	Object* p = a;
	v.Add();
	p = b;
	v.Add();
	v.Show();
	v.Del();
	cout << "\nVector size=" << v();

	Dialog D;
	D.Execute();

}