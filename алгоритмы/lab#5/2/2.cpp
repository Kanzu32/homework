#include <iostream>

using namespace std;

int main() {
  int arr[16], n, count = 1, countMax = 0, value;

  for (int i = 0; i < 16; i++) {
    cin >> arr[i];
  }

  for (int x = 0; x < 15; x++) {
    for (int i = 1; i < 16; i++) {
      if (arr[i-1] > arr[i]) {
        n = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = n;
      }
    }
  }

  for (int i = 1; i < 16; i++) {
    if (arr[i] == arr[i-1]) {
      count++;
    } else if (count > countMax) {
      countMax = count;
      count = 1;
      value = arr[i-1];
    } else count = 1;
  }

  if (count > countMax) {
    value = arr[15];
  }

  cout << value << endl;
  system("pause");
}