#include <iostream>

using namespace std;

class A{
    public:
        static int a;
        static void add();
        A& operator +() {
            ++a;
            return *this;
        };
};

class Parent {
    int a;
    
    public:
    Parent* ret() {
        return this;
    };
    void pr() {cout << "u gay";};
};

class Child: public Parent{
    void a() {
        Parent* p = Parent::ret();
        p->pr();
    }
};

void A::add() {
    a +=1;
}

int fc()

int A::a = 0;


int main(){
    A::add();
    A a;
    +a;
    cout << A::a;
}