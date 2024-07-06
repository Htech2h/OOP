//
// Created by htech2 on 2024/06/27.
#include <iostream>
#include <string>
using namespace std;

class My_class{
public:
    explicit My_class(int a);
    static string print() ;
private:
    const int Reg_var;
};

My_class::My_class(int a): Reg_var(a) {
    cout<<Reg_var<<endl;
}

string My_class::print() {
    return "const class";
}

int main()
{
    const My_class m(4);
    cout<< m.print();
}
