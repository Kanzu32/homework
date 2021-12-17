#include <iostream>

using namespace std;

int main() {
  int arr[13], x;

  for (int i = 0; i < 13; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < 6; i++) {
    x = arr[i];
    arr[i] = arr[13-i-1];
    arr[13-i-1] = x;
  }

  for (int i = 0; i < 13; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  system("pause");
}