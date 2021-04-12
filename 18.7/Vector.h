#pragma once
#include <iostream> 
using namespace std;
template <class T> 
class List
{
public:
	List(int s, T k);
	
	List(const List<T>&a);
	~List();
	List&operator=(const List<T>&a);
	T&operator[](int index);
	List operator+(const T k);
	List<T> operator+=(List<T>& x);
	friend ostream& operator<<<T>(ostream& out, const List<T>& a);
	friend istream& operator>><T>(istream& in, List<T>& a);
private:
	int size;
	T* data;
};

template <class T> 
List<T>::List(int s,T k)
{
	size = s;
	data = new T[size]; 
	for (int i = 0; i < size; i++)
		data[i] = k;
}

template <class T> 
List<T>::List(const List&a)
{
	size = a.size; 
	data = new T[size];
	for (int i = 0; i < size; i++) 
		data[i] = a.data[i];
}
template <class T> 
List<T>::~List()
{
	delete[]data; 
	data = 0;
}

template <class T>
List<T>& List<T>::operator=(const List<T>& a)
{
	if (this == &a)
		return *this; 
	size = a.size;
	if (data != 0)
		delete[]data; 
	data = new T[size];
	for (int i = 0; i < size; i++) 
		data[i] = a.data[i];
	return *this;
}

template <class T> 
T& List<T>::operator[](int index)
{
	if (index < size) 
		return data[index]; 
	else cout << "\nError! Index>size";
}

template <class T>
List<T> List<T>::operator+(const T k)
{

	List<T> temp(size, k);
	for (int i=0;i<size;i++)
	temp.data[i] = data[i] + k; 
	return temp;
}

template<class T>
List<T> List<T>::operator+=(List<T>& x) {
	for (int i = 0; i < x.size; i++)
		this->data[i] += x.data[i];
	return *this;
}
template <class T>
ostream& operator<< (ostream& out, const List<T>& a)
{
	for (int i = 0; i < a.size; ++i) 
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, List<T>& a)
{
	for (int i = 0; i < a.size; ++i) 
		in >> a.data[i];
	return in;
}

