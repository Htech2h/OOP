//
// Created by htech2 on 2024/07/02.
#include <iostream>
using namespace std;

class MyClass{
public:
    int var;
    MyClass(){}
    MyClass(int a):var(a){}

    MyClass operator+(MyClass &obj){
        MyClass res;
        res.var = (*this).var + obj.var;
        return res;
    }
};

int main()
{
    MyClass obj1(10), obj2(5);
    MyClass res = obj1+obj2;
    cout<<res.var;
}
