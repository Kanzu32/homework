#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double last, x, e;
  cin >> last, x, e;
  double y = 0.5 * (last + x / (last - 1));
  while ( abs(pow(y, 2) - pow(last, 2)) >= e ) {
    last = y;
    y = 0.5 * (last + x / (last - 1));
  }

  cout << y << endl;
  system("pause");
}