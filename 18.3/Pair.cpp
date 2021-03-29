#include "Pair.h" 
#include <iostream> 
using namespace std;
Pair& Pair::operator=(const Pair&t)
{
if(&t==this) 
return *this; 
first=t.first;
second = t.second; 
return *this;
}
bool Pair::operator<(const Pair& p)
{
	return first < p.first;
}
bool Pair::operator>(const Pair& p)
{
	return first > p.first;
}
Pair&Pair::operator--()
{
	first--;
	return *this;
}
Pair Pair::operator--(int)
{
	second--;
	return *this;
}
istream& operator>>(istream&in, Pair&t)
{
	cout << "first?"; 
	cin >> t.first;
	cout << "second?"; 
	cin >> t.second; 
	return in;
}
ostream& operator<<(ostream&out, const Pair&t)
{

	return (out << t.first << " : " << t.second);
}
