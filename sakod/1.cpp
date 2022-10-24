#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;
int* glarr;
void qsort(int* arr, int size) {
  int i = 0;
  int j = size-1;
  int pivot = arr[size/2];
  
  do {

    while(arr[i] < pivot) i++;
    while(arr[j] > pivot) j--;

    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }

  } while (i <= j);

  if (j > 0)
    qsort(arr, j+1);
  if (i < size)
    qsort(&arr[i], size-i);
}

int* msort(int* arr, int n) {

  if (n == 2) {
    if (arr[0] > arr[1]) {
      swap(arr[0], arr[1]);
    }
    return arr;
  }
  if (n == 1) {
    return arr;
  }
  int m = 2*floor(log2(n));

  if (m == n) { m = n/2; };
  msort(arr, m);
  msort(&arr[m], n-m);
  int i = 0;
  int j = m;
  int r = 0;
  int tmp[m];

  for (int x = 0; x < m; x++) {tmp[x] = arr[x];};

  while (i < m && j < n) {
    if (tmp[i] > arr[j]) {
      arr[r] = arr[j];
      j++;
      r++;
    } else {
      arr[r] = tmp[i];
      i++;
      r++;
    }
  }

  while(j < n) {
    arr[r] = arr[j];
    j++;
    r++;
  }

  while(i < m) {
    arr[r] = tmp[i];
    i++;
    r++;
  }

  return arr;
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
  const std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  int n = 5;
  //int *arr = new int[n]{4, 3, 5, 7, 0, 1};
  //int *arr = new int[n]{0, 1, 3, 4, 6};
  int *arr = new int[n]{7, 6, 5, 3, 0};
  glarr = arr;
  //pasteSort(arr, n);
  //arr = msort(arr, n);
  qsort(arr, n);
  const std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  std::cout << endl << "nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
  std::cout << "microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
  std::cout << "milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << endl;
}