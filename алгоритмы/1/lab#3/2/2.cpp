#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double x, y, r, x1, y1, length;
  cout << "x, y, r, x1, y1: ";
  cin >> x >> y >> r >> x1 >> y1;

  length = sqrt(pow(x-x1, 2) + pow(y-y1, 2));
  
  if (length == r) {
    cout << "C = " << 2*M_PI*r << endl;
  } else {
    cout << "S = " << M_PI*length*length << endl;
  }
  system("pause");
  return 0;
}