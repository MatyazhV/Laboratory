#include <iostream> 
#include "Pair.h"
#include "List.h"
#include <deque> 
#include <cstdlib> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	try
	{
		List<Pair>qe(3);
		qe.print();
		qe.max();
		qe.print();
		qe.del();
		qe.print();
		Pair sr;
		sr = qe.Srednee();
		qe.plus(sr);
		qe.print();
	}
	catch (int)
	{
		cout << "error!";
	}
}