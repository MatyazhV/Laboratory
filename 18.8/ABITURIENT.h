#pragma once
#include "Person.h"
class ABITURIENT :
    public Person
{
public:
    ABITURIENT(void);
public:
    ~ABITURIENT(void);
    void Show();
    void Input();
    ABITURIENT(string, int, int,string);
    ABITURIENT(const ABITURIENT&);
    int Get_p() { return p; }
    string Get_s() { return s; }
    void Set_p(int);
    void Set_s(string);
    ABITURIENT& operator=(const ABITURIENT&);
protected:
    int p;
    string s;
};