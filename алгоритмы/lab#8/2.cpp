#include <iostream>

using namespace std;

int main() {
  void func(double* arr, int size, int shift);

  int n;
  cin >> n;

  double *arr = new double[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  func(arr, n, 2);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

void func(double* arr, int size, int shift) {
  double first;
  first = arr[0];
  for (int i = 0; i < size; i++) {
    if (i % shift == 0 && i + shift < size)
    {
      arr[i] = arr[i + shift];
    }
    else if (i % shift == 0)
    {
      arr[i] = first;
    }
  }
}