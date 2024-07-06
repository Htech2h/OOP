//
// Created by htech2 on 2024/07/02.
#include <iostream>
using namespace std;

class MyClass{
public:
    MyClass(){
        regVar = 0;
    }
private:
    int regVar;
    friend void func(MyClass &obj);
};

void func(MyClass &obj)
{
    obj.regVar = 42;
    cout<< obj.regVar<<endl;
}

int main()
{
    MyClass obj;
    func(obj);
}
