#pragma once 
#include "Person.h"
class employee : public Person
{
public:
employee();
public:
~employee();
employee(string,int,string,double);
employee( const employee&);
string Get_post() {
	return post;
} 
double Get_salaray() { 
	return salary;
}
void Set_post(string);
void Set_salary(double);
void calcul_salary(double p) { salary += salary * p / 100; };
employee& operator=(const employee&);
friend istream& operator>>(istream& in, employee& l);
friend ostream& operator<<(ostream& out, const employee& l); 
protected:
string post;
double salary;
};
