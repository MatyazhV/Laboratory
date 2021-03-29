#include "enrolle.h" 
#include <iostream> 
#include <string> 
using namespace std;
enrolle::enrolle()
{
fio = "";
specialty = "";
scores = 0;
cout << "Конструктор без параметров для объекта" << this << endl;
}
enrolle::enrolle(string N, string K, int S)
{
	fio = N; 
	specialty = K;
	scores = S;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}
enrolle::enrolle(const enrolle& t)
{
	fio = t.fio; 
	specialty = t.specialty;
	scores = t.scores;
	cout << "Конструктор копирования для объекта " << this << endl;
}
enrolle::~enrolle()
{
	cout << "Деструктор для объекта " << this << endl;
}
string enrolle::get_fio()
{
	return fio;
}
string enrolle::get_specialty()
{
	return specialty;
}
int enrolle::get_scores()
{
	return scores;
}
void enrolle::set_fio(string N)
{
	fio = N;
}
void enrolle::set_specialty(string K)
{
	specialty = K;
}
void enrolle::set_scores(int S)
{
	scores = S;
}
void enrolle::show()
{
	cout << "фио: " << fio << endl; 
	cout << "специальность: " << specialty << endl; 
	cout << "кол-во баллов ЕГЭ: " << scores << endl;
}
