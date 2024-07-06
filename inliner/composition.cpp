//
// Created by htech2 on 2024/06/27.
#include <iostream>

using namespace std;

class Birthday{
public:
    Birthday(int m,int d, int y):month(m),day(d),year(y){}
    void printDate(){
        cout<< month<<" /"<<day<<" /"<<year<<endl;
    }
private:
    int month;
    int day;
    int year;
};

class person{
public:
    person(string n, Birthday bd):name(n), bd(bd){}
    void printInfo(){
        cout<<"The name"<<name;
        bd.printDate();
    }
private:
    string name;
    Birthday bd;
};

int main()
{
   Birthday bd(06,06,2005);
   person h(": htech_  ",bd);
   h.printInfo();
}