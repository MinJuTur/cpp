//
// 홀수마방진
//
#include <iostream>
#include <vector>
using namespace std;

bool isValidPos(int n, int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

bool isEmpty(vector<vector<int>>& arr, int x, int y) {
  return arr[x][y] == 0;
}

void turnToValidPos(vector<vector<int>>& arr, int n, int& x, int& y) {
  if (x-1 < 0 && y+1 >= n) {
    x++;
  } else if (x-1 < 0) {
    x = n-1; y++;
  } else if (y+1 >= n) {
    x--; y = 0;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0)); // 마방진
    int x = 0;   // 행
    int y = n / 2;   // 열
    arr[x][y] = 1;
    for (int num = 2; num <= n*n; num++) { // num: 마방진에 채울 숫자
      if (isValidPos(n, x-1, y+1) && isEmpty(arr, x-1, y+1)) arr[--x][++y] = num;
      else if (isValidPos(n, x-1, y+1)) { // 다음 셀이 이미 다른 숫자로 채워져 있을 떄
        arr[++x][y] = num;
      } else {  // 다음 셀이 마방진 행렬 밖으로 벗어났을 때
        turnToValidPos(arr, n, x, y);
        arr[x][y] = num;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
  }
}