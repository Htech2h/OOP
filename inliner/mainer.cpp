//
// Created by htech2 on 2024/06/27.
#include <iostream>
using namespace std;

class MyClass{
public:
    MyClass();
    void print();
public:
};

MyClass::MyClass() {
    cout<<"hello, world"<<endl;
}
void MyClass::print() {
    cout<<"This class prints something"<<endl;
}

int main()
{
    MyClass m;
    //pointer to object
    MyClass* ptr = &m;
    ptr->print();
    m.print();
}
