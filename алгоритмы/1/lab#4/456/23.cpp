#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin >> n;
  n++;
  int *arr = new int[1000]{
      0,
  };
  arr[n] = 1;
  for (int i = n - 1; i >= 1; i--)
  {
    arr[i] = arr[i + 1] + arr[i + 2] + arr[i + 3];
  }
  cout << arr[1];
}