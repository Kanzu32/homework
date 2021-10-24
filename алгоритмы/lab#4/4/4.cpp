#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int k;
  cin >> k;
  
  for (int n = 1; n < k; n++) {
    for (int m = 1; m < k; m++) {
      int sn = 0;
      int sm = 0;

      for (int i = 1; i < n/2+1; i++) {
        if (n % i == 0) {
          sn += i;
        }
      }

      for (int j = 1; j < m/2+1; j++) {
        if (m % j == 0) {
          sm += j;
        }
      }
      
      if (sm == n && sn == m) {
        cout << n << " " << m << endl;
      }

    }
  }
  system("pause");
}