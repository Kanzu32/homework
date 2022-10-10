#include <iostream>
#include <cstdio>
struct C{
    int a;
    C()=default;
    C(int a):a(a){}
    C operator +(const C o){
        return C(a+o.a);
    }
};

int main(){
    C c1 = 2;
    C c2 = 3;
    int a = (c1+c2 = 7).a;
    std::printf("%d", a)
;}
