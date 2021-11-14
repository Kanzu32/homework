#include <iostream>
#include <cmath>

// Дан массив действительных чисел размера n. Выполнить циклический сдвиг элементов массива, находящихся на нечетных местах, влево.

using namespace std;

int main()
{
  int n;
  double first;
  cin >> n;

  double *arr = new double[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  first = arr[0];

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && i+2 < n) {
      arr[i] = arr[i+2];
    } else if (i % 2 == 0) {
      arr[i] = first;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}