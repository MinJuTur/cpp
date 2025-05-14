//
// 전치 행렬
//
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int arr[n][n] = {{0}};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[j][i];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << arr[i][j] << " ";
      }
      cout << "\n";
    }
  }
}
