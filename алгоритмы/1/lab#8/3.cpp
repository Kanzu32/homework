#include <iostream>

using namespace std;

int main() {
  bool isPerfect(int x);
  int n;
  cin >> n;
  
  for (int i = 0; i < n; i++) {
    if (isPerfect(i)) cout << i << " ";
  }
}

bool isPerfect(int x) {
  int sm = 0;
  for (int i = 2; i <= x/2; i++) {
    if (x%i == 0) {
      sm += i;
    }
  }
  if (sm+1 == x) return true;
  return false;
}