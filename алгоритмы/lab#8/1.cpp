#include <iostream>

using namespace std;

int main(){
  int sign(int);
  int a, b, c;
  cin >> a >> b >> c;
  //cout << sign(a) << " " << sign(b) << " " << sign(c) << endl;
  cout << sign(a-b) - sign(3*a + c-b);
}

int sign(int x) {
  if (x < 0) return -1;
  else if (x == 0) return 0;
  return 1;
}