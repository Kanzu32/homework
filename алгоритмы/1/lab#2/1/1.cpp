#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double x, y;
  cout << "Enter x and y: ";
  cin >> x >> y;
  long double res = sinh( pow(x + log(y), 3)/sqrt(abs(x-log(y))) ) * cosh( (x + log(y)) * sqrt(abs(x - log(y))) );
  cout << res << endl;
  system("pause");
  return 0;
}