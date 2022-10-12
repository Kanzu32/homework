#include <iostream>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

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
  int* tmp = new int[n]{};
  int i = 0;
  int j = 0;
  int mid = n/2;
  if (n%2 == 1) {
    mid++;
  }
  for (int k = 0; k<n; k++) {
    if (i > mid) {
            int a = arr[mid+j];
            tmp[k] = a;
            j++;
        }
        else if (j > n-1) {
            int a = arr[i];
            tmp[k] = a;
            i++;
        }
        else if (arr[i] < arr[mid+j]) {
            int a = arr[i]; 
            tmp[k] = a;
            i++;
        }
        else {
            int b = arr[mid+j];
            tmp[k] = b;
            j++;
        }
  }

  return tmp;
} 

int* mergeSort(int* arr, int n, int length = 1) {
  if (length >= n) {
    return arr;
  }
  int* tmp = new int[n]{};
  int tmpi = 0;
  int mid = n/2;
  if (n%2 == 1) mid++;
  for (int section = 0; section < ceil(mid*1.0/length); section++) {
    int i = section*length;
    int j = mid+section*length;
    while(j < min(mid+(section+1)*length, n) || i < min(section*length+length, n)) {
      if (j >= min(mid+(section+1)*length, n)) {
        tmp[tmpi] = arr[i];
        i++;
      } else if (i >= min(section*length+length, n) || arr[i] >= arr[j]) {
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
  const std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  int n = 5;
  //int *arr = new int[n]{4, 3, 5, 7, 0, 1};
  int *arr = new int[n]{0, 1, 3, 4, 6};
  //pasteSort(arr, n);
  //arr = mergeSort(arr, n);
  arr = msort(arr, n);
  //qsort(arr, n);
  const std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  std::cout << endl << "nanoseconds: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << endl;
  std::cout << "microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
  std::cout << "milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << endl;
}