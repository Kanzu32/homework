#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n, x;
  cout << "Enter n: ";
  cin >> n;
  x = n % 12 + 1;
  cout << x << endl;
  system("pause");
  return 0;
}