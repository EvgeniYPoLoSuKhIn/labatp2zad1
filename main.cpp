#include <iostream>
#include "SIGN.cpp"
#define N 8
#include<locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SIGN *obj=new SIGN[N];
    system("cls");
    int choise;
    for(int i=0; i<N; i++)
        cin>>*(obj+i);
    system("cls");
    SIGN *buf=new SIGN;
    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<N-i-1; j++)
        {
            if(Sort(obj+j, obj+j+1))
            {
                *buf = *(obj+j);
                *(obj+j) = *(obj+j+1);
                *(obj+j+1) = *buf;
            }
        }
    }
    while(1)
    {
        cout<<"1)Вывести все записи\n2)Вывести данные о человеке по фамилии\n0)Выход\n>";
        cin>>choise;
        switch(choise)
        {
        case 1:
            for(int n=0; n<N; n++)
                cout<<*(obj+n);
            break;
        case 2:
            {
            cout<<"Введите знак зодиака: ";
            char zodiak[15];
            bool flag=0;
            cin>>zodiak;
            for(int i=0; i<N; i++)
            {
                if(obj[i].show(zodiak))
                {
                    cout<<*(obj+i);
                    flag=1;
                }
            }
            if(!flag)
                cout<<"\nЛюдей, с данным знаком зодиака, нет\n\n";
            break;
            }
        }
        if(choise==0)
            break;
        system("pause");
        system("cls");
    }
    delete [] obj;
    return 0;
}
