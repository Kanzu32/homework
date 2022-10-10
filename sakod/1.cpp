#include <iostream>
#include <cmath>
#include <algorithm>

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

int* mergeSort(int* arr, int n, int length = 1) {
  if (length >= n) {
    return arr;
  }
  int* tmp = new int[n]{};
  int tmpi = 0;
  int mid = ceil(n/(length*2.0))*length;
  for (int section = 0; section < ceil(mid*1.0/length); section++) {
    int i = section*length;
    int j = mid+section*length;
    while(j < min(mid+(section+1)*length, n) || i < section*length+length) {
      if (j >= min(mid+(section+1)*length, n)) {
        tmp[tmpi] = arr[i];
        i++;
      } else if (i >= section*length+length || arr[i] >= arr[j]) {
        tmp[tmpi] = arr[j];
        j++;
      }else {
        tmp[tmpi] = arr[i];
        i++;
      }
      tmpi++;
    }
  }

  return mergeSort(tmp, n, length*2);
  
}

void pasteSort(int* arr, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
      swap(arr[j-1], arr[j]);
    }
  }
}

int main()
{
  int n = 6;
  int *arr = new int[n]{4, 3, 5, 7, 0, 1};
  //pasteSort(arr, n);
  //arr = mergeSort(arr, n);
  //qsort(arr, 0, n-1);
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}