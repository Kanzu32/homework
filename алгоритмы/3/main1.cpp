#include <iostream>

class A{
    public:
    virtual void f() {
        std::cout << "A";
    };
};
class B: public A {
    public:
    void f() {
        std::cout << "B";
    };
};

class A1{
    public:
    void f() {
        std::cout << "A1";
    };
};

class A2{
    public:
    void f() {
        std::cout << "A2";
    };
};

class BB: public A1, public A2 {

};

int main(){
    A* pointer = new B();
    pointer->f();
}
