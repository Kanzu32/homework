#include <iostream>
#include <cmath>

// Среди тех столбцов целочисленной матрицы размером n×m, которые содержат только такие элементы, значения которых по модулю не превышают k, найти столбец с минимальным произведением элементов.

using namespace std;

int main() {
  int n, m, k, minSm, colIndex = -1;
  cin >> n >> m >> k;
  minSm = pow(k, n)+1;
  int **arr = new int*[n];
  for (int i = 0; i < n; i++) {
    arr[i] = new int[m];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for (int j = 0; j < m; j++) {
    int sm = 1;
    for (int i = 0; i < n; i++) {
      if (abs(arr[i][j]) > k) break;
      sm *= arr[i][j];
      if (i == n-1 && sm < minSm) {
        colIndex = j;
        minSm = sm;
      }
    }
  }
  if (colIndex == -1) cout << "NO";
  else cout << "col number: " << colIndex+1;


}