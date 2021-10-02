#include <iostream>

using namespace std;

int main() {
  double x;
  cin >> x;
  if (x < 0) {
    cout << -x << endl;
    system("pause");
    return 0;
  }

  cout << x << endl;
  system("pause");
  return 0;

}