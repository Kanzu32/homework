#include <iostream>

using namespace std;

int main () {
  double n, sm = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    sm += 1.0/i;
  }

  cout << sm;
}