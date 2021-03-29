#pragma once
#include <iostream> 
#include <string> 
using namespace std; 
class enrolle
{
string fio; 
string specialty;
int scores;
public:
	enrolle();
	enrolle(string, string, int);
	enrolle(const enrolle&);
	~enrolle();
	string get_fio();
	void set_fio(string);
	string get_specialty();
	void set_specialty(string); 
	int get_scores();
	void set_scores(int); 
	void show();
};
