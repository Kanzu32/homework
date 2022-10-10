#include <iostream>

using namespace std;

class A {
  
  friend void fn(A a);
  public:
    int a;
    A(int b)
    {
      a = b;
  }
  // A& operator +(A& a) {
  //   this->a += a.a;
  //   return *this;
  // }
};

A& operator +(A& a, A& b) {
  a.a += b.a;
  return a;
}
void fn(A a) {
  a.a = a.a+1;
  cout << a.a;
}

void operator ,(const A a, const A b){
  cout <<"NAHUYA=?\n";
}

int main() {
  A a = A(4);
  A b = A(5);
  A c = a+b;
  cout << c.a;
}