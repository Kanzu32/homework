#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector <double> res;

  double arr[16][16] = {
      {1, 2, 3, 4, 5, 6, 7, 8, 1, 10, 11, 12, 24, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 33, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 93, 14, 15, 1},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 43, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 42, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 24, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 69, 14, 15, 13},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 26, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 83, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 53, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 93, 14, 1, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 103, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 23, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 63, 14, 15, 16},
      {1, 2, 3, 4, 5, 6, 7, 8, 1, 10, 11, 12, 33, 14, 15, 16}, };
  
  for (int i = 0; i < 16; i++) {
    for (int j = 8; j < 16; j++) {
      if ((i < 8 && j - 8 >= i) || (i >= 8 && 23 - j <= i)) {
        if ( abs( ((int)arr[i][j])%10 - ((int)arr[i][j])%100/10 ) == 2 ) {
          res.push_back(arr[i][j]);
        }
      }
    }
  }

  if (res.size() != 0) {
    auto min = min_element(res.begin(), res.end());
    cout << *min;
  } else cout << "NO";
  
}