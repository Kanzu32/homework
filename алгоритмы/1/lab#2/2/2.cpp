#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double c;
  cout << "Enter temperature: ";
  cin >> c;
  cout << round((c * 1.8) + 32) << endl;
  system("pause");
  return 0;
}