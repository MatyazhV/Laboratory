#include "Pair.h" 
Pair::Pair()
{
	first = 0;
	second = 0.0;
}
Pair::Pair(int a, double b)
{
	first = a;
	second = b;
}
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}
Pair& Pair ::operator=(const Pair& t)
{
	first = t.first;
	second = t.second;
	return *this;
}
Pair Pair ::operator+(const Pair& t)
{
	first += t.first;
	second += t.second;
	return *this;
}
bool Pair:: operator<(const Pair& t)
{
	return first < t.first;
}
Pair Pair :: operator /(const int& t)
{
	first /= t;
	second /= t;
	return *this;
}
Pair Pair :: operator +=(const Pair& t)
{
	first += t.first;
	second += t.second;
	return *this;
}
bool Pair :: operator == (const Pair& t)
{
	return first == t.first && second == t.second;
}
ostream& operator << (ostream& out, const Pair& t)
{
	out << t.first << " : " << t.second;
	return out;
}
istream& operator >> (istream& in, Pair& t)
{
	cout << "First?" << endl;
	in >> t.first;
	cout << "Second?" << endl;
	in >> t.second;
	return in;
}