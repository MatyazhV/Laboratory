#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(void)
{
	name = "";
	age = 0;
}

Person::~Person(void)
{
}

Person::Person(string T, int A)
{
	name = T;
	age = A;
}

Person::Person(const Person& print)
{
	name = print.name;
	age = print.age;
}

void Person::Set_name(string T)
{
	name = T;
}
void Person::Set_age(int A)
{
	age = A;
}

Person& Person::operator=(const Person& c)
{
	if (&c == this)return *this;
	name = c.name;
	age = c.age;
	return *this;
}

void Person::Show()
{
	cout << "\nname : " << name;
	cout << "\nage : " << age;
	cout << "\n";
}

void Person::Input()
{
	cout << "\nname:";
	cin >> name;
	cout << "\nage:";
	cin >> age;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "title=" << Get_name() << endl; break;
		}
	}
}