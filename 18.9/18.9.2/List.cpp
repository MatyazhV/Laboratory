#include "List.h"
#include "error.h"
List::List(int s)
{
	if (s > MAX_SIZE) throw error("–азмер массива больше допущенного");
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
		beg[i] = 0;
}
List::List(const List& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
}
List::~List()
{
	if (beg != 0)
		delete[]beg;
}
List::List(int s, int* mas)
{
	if (s > MAX_SIZE)
		throw error("–азмер массива больше допущенного");
	size = s;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
const List& List::operator =(const List& v)
{
	if (this == &v)
		return *this;
	if (beg != 0)
		delete[]beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
		beg[i] = v.beg[i];
	return*this;
}

ostream& operator<<(ostream& out, const List& v)
{
	if (v.size == 0)
		out << "Empty\n";
	else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream& in, List& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
int List::operator [](int i)
{
	if (i < 0)
		throw error("ƒоступ по индексу не доступен, число меньше 0");
	if (i >= size)
		throw error("ƒоступ по индексу не доступен, число больше размера списка ");
	return beg[i];
}
List List::operator +(int a)
{
	if (size + 1 == MAX_SIZE)
		throw error("ƒобавление не возможно, превышен допустимый размер");
	List temp(size, beg);
	delete[]beg;
	size++;
	beg = new int[size];
	beg[0] = a;
	for (int i = 1; i < size; i++)
		beg[i] = temp.beg[i - 1];
	return*this;
}
List& operator+(List& x, List& y) {
	if (x.size != y.size)
		throw error("¬ыполнит ьсложение не возможно, размеры списков не равны");
	for (int i = 0; i < x.size; i++)
		y.beg[i] = x.beg[i] + y.beg[i];
	return y;
}

