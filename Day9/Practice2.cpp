//
// 입체사목게임
//
#include <iostream>
#include <vector>
using namespace std;

int getWinner(vector<vector<int>>& arr) {

  for (int i = 1; i <= 6; i++) { // 수평 확인
    for (int j = 1; j <= 4; j++) {
      if (arr[i][j] != 0 && arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i][j+2] && arr[i][j] == arr[i][j+3]) return arr[i][j];
    }
  }

  for (int i = 1; i <= 3; i++) { // 수직 확인
    for (int j = 1; j <= 7; j++) {
      if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+2][j] && arr[i][j] == arr[i+3][j]) return arr[i][j];
    }
  }

  for (int i = 1; i <= 3; i++) { // 대각선 확인(\빙향)
    for (int j = 1; j <= 4; j++) {
      if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i+2][j+2] && arr[i][j] == arr[i+3][j+3]) return arr[i][j];
    }
  }

  for (int i = 1; i <= 3; i++) { // 대각선 확인(/빙향)
    for (int j = 4; j <= 7; j++) {
      if (arr[i][j] != 0 && arr[i][j] == arr[i+1][j-1] && arr[i][j] == arr[i+2][j-2] && arr[i][j] == arr[i+3][j-3]) return arr[i][j];
    }
  }
  return 0; // 무승부
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> arr(7,vector<int>(8,0)); // 인덱스 i=1~6, j=1~7 사용)
    for (int k = 1; k <= n; k++) { // n번 반복
      int i = 6; // 행 번호
      int j; cin >> j; // 열 번호(고정)

      while (arr[i][j] != 0) i--; // 넣을 수 있는 칸이 나올 때까지 행 이동
      arr[i][j] = k % 2 ? 1 : 2; // 홀수번째면 1, 짝수번째면 2 넣기
    }
    cout << getWinner(arr) << endl;
  }
}