#include "enrolle.h" 
#include <iostream> 
#include <string>
#include <windows.h>
using namespace std;
enrolle make()
{
string s;
string i;
int d;
cout << "Введите фио: ";
cin.ignore();
getline(cin,s);
cout << "Введите специальность: ";
getline(cin, i);
cout << "Введите кол-во баллов ЕГЭ: ";
cin >> d;
enrolle t(s, i, d); 
return t;
}
void print(enrolle t)
{
	t.show();
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	enrolle t1;
	t1.show();
	enrolle t2("Сидоров В.З", "Строитель",160);
	t2.show();
	enrolle t3=t2;
	t3.set_fio("Петров Ф.В.");
	t3.set_specialty("информатика");
	t3.set_scores(220);
	print(t3);
	t1=make();
	t1.show();
	return 0;
}