#include <iostream> 
#include <deque> 
#include <cstdlib> 
using namespace std;
typedef deque<double>que;
que make_deque(int n)
{ 
	if (n <= 0)
		throw 1;
que v;
for(int i=0;i<n;i++)
{
	double a = rand()*0.001;
	v.push_back(a);
}
return v;
}
void print_deque(que v)
{
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << " ";
	cout << endl;
}
int srednee(que v)
{
	double s = 0;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	double n = v.size();
	return s/n;
}

void maxadd(que& v)
{
	double m = v[0];
		for (int i = 0; i < v.size(); i++)
		if(m<v[i])
		{
			m = v[i];
		}
		v.push_back(m);
}
void del_deque(que &v)
{
	double key;
	cout <<" key?" << endl;
	cin >> key;
	bool k = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == key)
		{
			v.erase(v.begin() + i);
			k = 1;
		}
	}
	if (!k)
	{
		cout << "This item wasn't found" << endl;
	}
}

void plus1(que& v)
{
	double el = srednee(v);
	for (int i = 0; i < v.size(); i++)
		v[i] += el;
}

 int main()
{
	 setlocale(LC_ALL, "rus");
	try
	{
		deque<double> q;
		deque<double>::iterator
			vi = q.begin();
		int n;
		cout << "N?"; 
		cin >> n; 
		q = make_deque(n);
		cout << "Очередь: ";
		print_deque(q);
		maxadd(q);
		cout << "Очередь после добавления: ";
		print_deque(q);
		del_deque(q);
		cout << "Очередь после удаления: ";
		print_deque(q);
		plus1(q);
		cout << "Очередь после добавления элементам среднего арифметического: ";
		print_deque(q);
	}
	catch (int)
	{
		cout << "error!";
	}
}