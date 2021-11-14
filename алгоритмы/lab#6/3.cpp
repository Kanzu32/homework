#include <iostream>

// Дан массив целых чисел размера n.Перед первым минимальным элементом массива вставить все его делители.

using namespace std;

int main()
{
  int n, index, value, count = 0;
  cin >> n;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) { //in
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) { //find min
    if (arr[i] < arr[i-1]) {
      value = arr[i];
      index = i;
      break;
    }
  }

  for (int i = 1; i <= value; i++) { //find count of del
    if (value % i == 0) {
      count++;
    }
  }

  int *res = new int[count + n];

  for (int i = 0; i < index; i++) { //write nums before min
    res[i] = arr[i];
  }

  int j = 0;
  for (int i = 1; i <= value; i++) { //write del
    if (value % i == 0)
      res[index+j++] = i;
  }

  for (int i = index; i < n; i++) { //write nums after min
    res[i+count] = arr[i];
  }


  for (int i = 0; i < n+count; i++) { //out res
    cout << res[i] << " ";
  }
}
