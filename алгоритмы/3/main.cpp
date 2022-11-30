#include <iostream>

using namespace std;

template <typename Type>
class A {
    Type a;
};

template <int num = 3>
class B {
public:
    int a;
    B () {
        a = num;
    }
};

template <int num, typename T>
class D {};

template<template<typename> class subClass>
class WierdClass {
    subClass<int> sub;
};

template <typename G = float>
class MethodClass {
    public:
    void innerMethod(G gg) {cout << "inner\n" << gg << endl;};
    void outerMethod();
};


template <typename G>
void MethodClass<G>::outerMethod() {cout << "outer\n";}

template <>
void MethodClass<int>::outerMethod() {cout << "INTus\n";};

template <>
class MethodClass<double> {
    public:
    double a;
    double b;
    void innerMethod() {a+=b;};
    void outerMethod();
};

void MethodClass<double>::outerMethod() {cout << a << " " << b << endl;};

template <typename H>
class ParentTempl {
    public:
    H h;
};

class Parent {
    int h;
};

template <typename H>
class Child1: ParentTempl<H> {};

template <typename H>
class Child2: Parent {};

template <typename Type1> class Friend;
template <typename Type1> class NoFriend;
template <typename Type2> class Friend1;
template <typename Type2> class Friend2;

template <typename Type1>
class Friend {
    friend class NoFriend<Type1>;
    Type1 s;
    Friend(Type1 n) {s = n;};
};

template <typename Type1>
class NoFriend {
    Type1 d;
    Friend<Type1> fri;
    void get() {cout << fri.s;};
    NoFriend () {
        fri = Friend<Type1>(3);
    }
};

template <typename Type2>
class Friend1 {
    friend class Friend2<Type2>;
};

template <typename Type2>
class Friend2 {
    friend class Friend1<Type2>;
};

int main(){
    //B<5> b = B<5>();
    //cout << b.a;
    MethodClass<string> clas = MethodClass<string>();
    clas.innerMethod("aboba");
    clas.outerMethod();
    MethodClass<int> clas1 = MethodClass<int>();
    clas1.innerMethod(2);
    clas1.outerMethod();
    MethodClass<double> clas2 = MethodClass<double>();
    clas2.a = 2;
    clas2.b = 3;
    clas2.innerMethod();
    clas2.outerMethod();
}