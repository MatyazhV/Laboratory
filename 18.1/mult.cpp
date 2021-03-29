#include <iostream>
#include "mult.h"

using namespace std;

void mult::init(int f, double s) {
	first = f;
	second = s;
}

void mult::read() {
	cout << "first? "; cin >> first;
	cout << "second? "; cin >> second;
}

void mult::show() {
	cout << "first = " << first << endl;
	cout << "second = " << second << endl;
}

double mult::multiply(double k) {
	return (first * k + second * k);
}