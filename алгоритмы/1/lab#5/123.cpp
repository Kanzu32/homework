#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int arr[10][5];
  stand(time(NULL));

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i < 10; i+=2) {
    for (int j = 0; j < 5; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}