#include <iostream>
#include <cmath>

// Дан массив действительных чисел размера n и действительное k.Выполнить сортировку по возрастанию всех элементов массива, значения которых меньше k по модулю.

using namespace std;

int main(){
    int n, count = 0, index = 0;
    double k;
    cin >> n >> k;
    double *arr = new double[n];

    for (int i = 0; i < n; i++) { // in
      cin >> arr[i];
      if (abs(arr[i]) < k) count++;
    }

    double *toSort = new double[count];

    for (int i = 0; i < n; i++) { // fill arr to sort
      if (abs(arr[i]) < k) {
        toSort[index] = arr[i];
        index++;
      }
    }

    for (int x = 0; x < count; x++) { // sort
      for (int i = 1; i < count; i++) {
        if (toSort[i-1] > toSort[i]) {
          swap(toSort[i-1], toSort[i]);
        }
      }
    }

    cout << "sorted: ";
    for (int i = 0; i < count; i++) { // print only sorted
      cout << toSort[i] << " ";
    }
    cout << endl;

    index = 0;
    cout << "all: ";
    for (int i = 0; i < n; i++) { // print sorted and other
      if (abs(arr[i]) < k) cout << toSort[index++] << " ";
      else cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
}
