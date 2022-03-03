#include <iostream>
#include <vector>

// Дан массив целых чисел размера n.Перед первым минимальным элементом массива вставить все его делители.

using namespace std;

int main() {
  int n, index, value, count = 0;
  cin >> n;
  vector <int> arr;

  for (int i = 0; i < n; i++) { //in
    int val;
    cin >> val;
    arr.push_back(val);
  }

  for (int i = 1; i < n; i++) { //find min
    if (arr[i] < arr[i - 1]) {
      value = arr[i];
      index = i;
      break;
    }
  }

  for (int i = 1; i <= value; i++) {
    if (value % i == 0) arr.insert(arr.begin()+index, i);
  }

  for (int i = 0; i < arr.size(); i++) { //out res
    cout << arr[i] << " ";
  }
  cout << endl;
  system("pause");
}
