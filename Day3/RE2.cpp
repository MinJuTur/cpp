//
// 숫자 정사각행렬 달팽이 모양 출력하기
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, a, b;
    cin >> n >> a >> b;

    int x = 0; // 가로
    int y = 1; // 세로
    int repeat = n;
    int cnt = 0;
    for (int j = 0; j < 2*n-1; j++) {
      if (j % 2 != 0) repeat--;

      switch (j % 4) {
        case 0: //오른쪽
          for (int k = 0; k < repeat; k++) {
            x++;
            cnt++;
            if (cnt >= a && cnt <= b) cout << (y-1)*n+x << " ";
          }
          break;
        case 1: //아래
          for (int k = 0; k < repeat; k++) {
            y++;
            cnt++;
            if (cnt >= a && cnt <= b) cout << (y-1)*n+x << " ";
          }
          break;
        case 2: //왼쪽
          for (int k = 0; k < repeat; k++) {
            x--;
            cnt++;
            if (cnt >= a && cnt <= b) cout << (y-1)*n+x << " ";
          }
          break;
        case 3: //위
          for (int k = 0; k < repeat; k++) {
            y--;
            cnt++;
            if (cnt >= a && cnt <= b) cout << (y-1)*n+x << " ";
          }
          break;
        default:
          break;
      }
    }
    cout << endl;
  }
}



