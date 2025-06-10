#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m,vector<int>(n,0));
    for (int i = 0 ; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }

    for (int i = 0 ; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int data;
        cin >> data;
        arr[i][j] += data;
      }
    }

    for (int i = 0 ; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }

  }
}