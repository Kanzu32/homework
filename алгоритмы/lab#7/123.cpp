#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
  int n;
  cin >> n;
  int **arr = new int*[n];
  
  for (int i = 0; i < n; i++) {
    arr[i] = new int[i+1];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i+1; j++) {
      arr[i][j] = 0;
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  //arr[2][3] = rand() %(b-a+1)+a;
}
