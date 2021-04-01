#pragma once 
#include "Person.h"
class employee : public Person
{
public:
	employee(void);
	~employee(void);
	employee(string, int, string, double);
	employee(const employee&);
	string Get_post() {
		return post;
	}
	double Get_salaray() {
		return salary;
	}
	void Set_post(string);
	void Show();
	void Set_salary(double);
	employee& operator=(const employee&);
	friend istream& operator>>(istream& in, employee& l);
	friend ostream& operator<<(ostream& out, const employee& l);
protected:
	string post;
	double salary;
};
