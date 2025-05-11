#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        int data;
        cin >> data;
        arr[j][k] = data;
      }
    }

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        int data;
        cin >> data;
        arr[j][k] += data;
      }
    }

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n; k++) {
        cout << arr[j][k] << " ";
      }
      cout << endl;
    }
  }
}
