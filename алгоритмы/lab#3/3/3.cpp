#include <iostream>

using namespace std;

int main() {
  int x, n1, n2, n3, n4;
  cin >> x;
  n1 = x/1000;
  n2 = x%1000/100;
  n3 = x%100/10;
  n4 = x%10;
  
  if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  system("pause");
}