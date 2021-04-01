#include "Person.h"
#include "Object.h"
Person::Person(void)
{
	name = "";
	age = 0;
}
Person::~Person(void)
{
}
Person::Person(string M, int C)
{
	name = M;
	age = C;
}
Person::Person(const Person& car)
{
	name = car.name;
	age = car.age;
}
void Person::Set_age(int C)
{
	age = C;
}
void Person::Set_name(string M)
{
	name = M;

}
void Person::Show()
{
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
}
Person& Person::operator=(const Person& c)
{
	if (&c == this)
		return *this;
	name = c.name;
	age = c.age;
	return *this;
}
istream& operator>>(istream& in, Person& c)
{
	cout << "\nname:";
	in >> c.name;
	cout << "age:";
	in >> c.age;
	return in;
}
ostream& operator<<(ostream& out, const Person& c)
{
	out << "name : " << c.name << endl;
	out << "age : " << c.age << endl;
	out << endl;
	return out;
}
