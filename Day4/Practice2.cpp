#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int px,py,qx,qy;
    cin >> px >> py >> qx >> qy;
    int rx,ry,sx,sy;
    cin >> rx >> ry >> sx >> sy;

    int arr[100][100] = {0};
    int area = 0;
    int perimeter = 0;

    // 사각형 저장하기
    for (int j = px; j < qx; j++) {
      for (int k = py; k < qy; k++) {
        arr[j][k] = 1;
      }
    }
    for (int j = rx; j < sx; j++) {
      for (int k = ry; k < sy; k++) {
        arr[j][k] = 1;
      }
    }

    // 면적 계산하기
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 100; k++) {
        if (arr[j][k] == 1) area++;
      }
    }

    // 테두리 길이 계산하기
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 100; k++) {
        if (arr[j][k] == 1) {
          if (j == 0 || arr[j-1][k] == 0) perimeter++;
          if (k == 0 || arr[j][k-1] == 0) perimeter++;
          if (j == 99 || arr[j+1][k] == 0) perimeter++;
          if (k == 99 || arr[j][k+1] == 0) perimeter++;
        }
      }
    }

    cout << area << " " << perimeter << endl;
  }
}
