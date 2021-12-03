#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

// Дан массив действительных чисел размера n и действительное k.Выполнить сортировку по возрастанию всех элементов массива, значения которых меньше k по модулю.

using namespace std;

int main() {
  int n, count = 0, index = 0;
  double k;
  cin >> n >> k;
  vector <double> arr(n);
  vector <double> toSort;

  for (int i = 0; i < n; i++) { // in
    cin >> arr[i];
    if (abs(arr[i]) < k)
      toSort.push_back(arr[i]);
      count++;
  }

  sort(toSort.begin(), toSort.end());

  for (int i = n-1; i >= 0; i--) { // rewrite arr
    if (abs(arr[i]) < k) {
      arr[i] = toSort.back();
      toSort.pop_back();
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}
