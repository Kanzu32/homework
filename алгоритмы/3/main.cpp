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