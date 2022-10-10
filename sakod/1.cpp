#include <iostream>

using namespace std;

void qsort(int* arr, int begin, int end) {
  int i = begin;
  int j = end;
  int pivot = arr[(begin + end) / 2];
  while (i <= j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot ) j--;

    if (i <= j) {
      if (arr[i] > arr[j]) {
        swap(arr[i], arr[j]);
      }
      i++;
      j--;
    }
  }

  if (begin < j)
    qsort(arr, begin, j);
  if (i < end)
    qsort(arr, i, end);
}

void twoArrSort(int* arr, int n) {
  
  int* tmp = new int[n]{};
  for (int grLen = 1; grLen <= n; grLen = 2*grLen) {
    int i = 0;
    int j = grLen;
    int tmpi = 0;
    int iter = 1;
    while (iter*grLen <= n) {
      while (tmpi < iter*grLen) {
      if (i < (iter-1)*2*grLen+grLen && arr[i] <= arr[j]) {
        tmp[tmpi] = arr[i];
        i++;
      } else if (j < iter*2*grLen && arr[j] < arr[i]) {
        tmp[tmpi] = arr[j];
        j++;
      } else if (i >= n) {
        for (int k = 0; k < n; k++) {
          arr[k] = tmp[k];
          tmpi = 0;
        }
      } else {
        tmp[tmpi] = arr[i];
        i++;
      }
      tmpi++;
      }
      i += grLen+1;
      j += grLen+1;
      iter++;
    }
    for (int k = 0; k < n; k++) {
      cout << tmp[k] << " ";
      arr[k] = tmp[k];
      tmpi = 0;
    }
    cout << "\n";
  }
  
}

int main()
{
  int n = 6;
  int *arr = new int[n]{4, 3, 5, 7, 0, 1};

  int *res = new int[n]{};
  twoArrSort(arr, n);
  //qsort(arr, 0, n-1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}