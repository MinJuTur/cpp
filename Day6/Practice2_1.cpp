#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int r, s, t;
    cin >> r >> s >> t;

    vector<vector<int>> A(r,vector<int>(s,0));
    vector<vector<int>> B(s,vector<int>(t,0));
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < s; j++) {
        cin >> A[i][j];
      }
    }

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < t; j++) {
        cin >> B[i][j];
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < t; j++) {
        int element = 0;
        for (int k = 0; k < s; k++) {
          element += A[i][k]*B[k][j];
        }
        cout << element << " ";
      }
      cout << endl;
    }
  }
}
