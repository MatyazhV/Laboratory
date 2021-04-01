#include "employee.h" 
employee::employee() : Person()
{
	post = "";
	salary = 0;
} 
employee::~employee()
{
}
employee::employee(string M, int C, string P, double G) : Person(M, C)
{
	post = P;
	salary = G;
} 
employee::employee( const employee &L)
{
	name = L.name;
	age = L.age;
	post = L.post;
	salary = L.salary;
}
void employee::Set_post(string G)
{
	post = G;
}
void employee::Set_salary(double G)
{
	salary = G;
}
employee& employee::operator=(const employee& L)
{
	if (&L == this)
		return *this; 
	name = L.name;
	age = L.age;
	post = L.post;
	salary = L.salary;
	return *this;
}
istream& operator>>(istream& in, employee& l)
{
	cout << "\nName:"; 
	in >> l.name; 
	cout << "age:";
	in >> l.age;
	cout << "Post:"; 
	in >> l.post; 
	cout << "salary:"; 
	in >> l.salary;
	return in;
}
ostream& operator<<(ostream& out, const employee& l)
{
	out << "name : " << l.name<< endl; 
	out << "age : " << l.age<< endl;
	out << "post : " << l.post << endl;
	out << "salary : " << l.salary << endl;
	return out;
}
