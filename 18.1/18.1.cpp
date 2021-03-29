#include "mult.h"
#include <iostream>

using namespace std;

mult make_mult(int f, double s) {
	mult p;
	p.init(f, s);
	return p;
}

int main() {
	setlocale(LC_ALL, "Rus");
	mult A;
	mult B;
	A.init(5, 2.3);
	B.read();
	A.show();
	B.show();
	double k;
	cout << "Введите вещественное число для умножения: ";
	cin >> k;
	cout << "A.coast(" << A.first << ", " << A.second << ") = " << A.multiply(k) << endl;
	cout << "Введите вещественное число для умножения: ";
	cin >> k;
	cout << "B.coast(" << B.first << ", " << B.second << ") = " << B.multiply(k) << endl;
	cout << "Введите вещественное число для умножения: ";
	cin >> k;
	mult* X = new mult;
	X->init(2, 0.5);
	X->show();
	X->multiply(k);
	cout << "X.coast(" << X->first << ", " << X->second << ") = " << X->multiply(k) << endl;
	mult mas[3];
	for (int i = 0; i < 3; i++) {
		mas[i].read();
	}
	for (int i = 0; i < 3; i++) {
		mas[i].show();
	}
		cout << "Введите вещественное число для умножения: ";
		cin >> k;
	for (int i = 0; i < 3; i++) {
		mas[i].multiply(k);
		cout << "mas[" << i << "].coast(" << mas[i].first << ", " << mas[i].second << ") = " << mas[i].multiply(k) << endl;
	}
	mult* p_mas = new mult[3];
	for (int i = 0; i < 3; i++) {
		p_mas[i].read();
	}
	for (int i = 0; i < 3; i++) {
		p_mas[i].show();
	}
		cout << "Введите вещественное число для умножения: ";
		cin >> k;
	for (int i = 0; i < 3; i++) {
		mas[i].multiply(k);
		cout << "p_mas[" << i << "].coast(" << p_mas[i].first << ", " << p_mas[i].second << ") = " << p_mas[i].multiply(k) << endl;
	}
	int y; double z;
	cout << "first? "; cin >> y;
	cout << "second? "; cin >> z;
	mult f = make_mult(y, z);
	f.show();
	cout << "Введите вещественное число для умножения: ";
	cin >> k;
	f.multiply(k);
}