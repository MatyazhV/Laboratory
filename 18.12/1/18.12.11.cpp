#include <iostream> 
#include <set>
using namespace std;
typedef set<double>TMap;
typedef TMap::iterator it;
TMap make_map(int n)
{
	TMap m;
	double a;
	for (int i = 0; i != n; i++)
	{
		cin >> a;
		m.insert(a);
	}
	return m;
}
void print_map(TMap m)
{
	for (it i = m.begin(); i != m.end(); ++i)
		cout << *i << " ";
	cout << endl;
}

double srednee(TMap v)
{
	double s = 0;
	for (it i = v.begin(); i != v.end(); ++i)
		s + *i;
	int n = v.size(); 
	return s / n;
}

void plus1(TMap& v)
{
	TMap f;
	double el = srednee(v);
	for (it i = v.begin(); i != v.end(); i++)
	{
		double k = el + *i;
		f.insert(k);
	}
	v = f;
}

int main()
{
	int n;
	cout << "N?";
	cin >> n;
	TMap m = make_map(n);
	print_map(m);
	cout << "Max: " << *(m.rbegin()) << endl;
	double key;
	cin >> key;
	m.erase(key);
	print_map(m);
	plus1(m);
	print_map(m);
}