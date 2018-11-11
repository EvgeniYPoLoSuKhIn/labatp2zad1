#include <iostream>
#include <cstdio>
#include <windows.h>
#include <iomanip>
#include "SIGN.h"
using namespace std;

SIGN::SIGN()
{
    cout<<"Вызов конструктора без параметров\n";
    name = new char [15];
    surname = new char [15];
    zodiac_sign = new char [15];

}
SIGN::SIGN(char *a, char *b, char  *c, int d, int e, int f)
{
    cout<<"Вызов конструктора с параметрами\n";
    name = new char [15];
    surname = new char [15];
    zodiac_sign = new char [15];
    strcpy(name, a);
    strcpy(surname, b);
    strcpy(zodiac_sign, c);
    birthday[0]=d;
    birthday[1]=e;
    birthday[2]=f;
}
SIGN::SIGN(const SIGN & arg)
{
    cout<<"Вызов конструктора копирования\n";
    name = new char [15];
    surname = new char [15];
    zodiac_sign = new char [15];
    for(int q=0; q<15; q++)
        name[q]=arg.name[q];
    for(int q=0; q<15; q++)
        surname[q]=arg.surname[q];
    for(int q=0; q<15; q++)
        zodiac_sign[q]=arg.zodiac_sign[q];
    for(int q=0; q<3; q++)
        birthday[q]=arg.birthday[q];
}
bool SIGN::show(char *vv)
{
    return !strcmp(surname, vv);
}

bool Sort(SIGN *frst, SIGN *scnd)
{
    unsigned int a, b;
    a=frst->birthday[0]+frst->birthday[1]*30+frst->birthday[2]*365;
    b=scnd->birthday[0]+scnd->birthday[1]*30+scnd->birthday[2]*365;
    return a>b?true:false;
}

ostream& operator << (ostream& os, SIGN& sn)
{

    os<<setw(12)<<sn.surname<<' ';
    os<<setw(10)<<sn.name;

    os<<setw(10)<<sn.zodiac_sign<<setw(6);

    os<<sn.birthday[0]<<'.';
    os<<sn.birthday[1]<<'.';
    os<<sn.birthday[2]<<"г."<<"\n\n";

    return os;
}

istream& operator >> (istream& is, SIGN& sn)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    cout<<"Введите фамилию: ";
    is>>sn.surname;
    cout<<"Введите имя: ";
    is>>sn.name;
    cout<<"Введите знак зодиака: ";
    is>>sn.zodiac_sign;
    while(1)
    {
        cout<<"Введите дату: ";
        try
        {
            is>>sn.birthday[0];
            if(sn.birthday[0]>31)
            {
                throw 404;
            }
            break;
        }
        catch(int i)
        {
            cout<<"error "<<i<< " - в месяце не бывает больше 31 дня"<<endl;
        }
    }
    while(1)
    {
        cout<<"Введите месяц: ";
        try
        {
            is>>sn.birthday[1];
            if(sn.birthday[1]>12)
            {
                throw 404;
            }
            break;
        }
        catch(int i)
        {
            cout<<"error "<<i<< " - в году только 12 месяцев"<<endl;
        }
    }
    while(1)
    {
        cout<<"Введите год: ";
        try
        {
            is>>sn.birthday[2];
            if(sn.birthday[2]>st.wYear)
            {
                throw 404;
            }
            break;
        }
        catch(int i)
        {
            cout<<"error "<<i<< " - введённый год больше текущего"<<endl;
        }
    }
    cout<<"\n\n";
    return is;
}

SIGN::~SIGN()
{
    cout<<"Вызов деструктора\n";
    delete [] name;
    delete [] surname;
    delete [] zodiac_sign;
}
