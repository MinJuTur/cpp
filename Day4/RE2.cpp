//
// 두 사각형 면적 및 둘레 구하기
// 배열에 사각형의 존재를 1로 표현
// 1이 있으면 면적++, 1이 있을 때 주변이 0이면 테두리++
//
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int arr[100][100] = {0}; //0부터 99까지

    int px,py,qx,qy;

    cin >> px >> py >> qx >> qy;
    for (int j = px; j < qx; j++) {
      for (int k = py; k < qy; k++) {
        arr[j][k] = 1;
      }
    }
    cin >> px >> py >> qx >> qy;
    for (int j = px; j < qx; j++) {
      for (int k = py; k < qy; k++) {
        arr[j][k] = 1;
      }
    }

    int sumRange = 0; // 면적 합
    int edgeSum = 0; // 테두리 길이 합:
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 100; k++) {
        if (arr[j][k] == 1) {
          sumRange++;
          if (j == 0 || arr[j-1][k] == 0) edgeSum++; //위
          if (k == 0 || arr[j][k-1] == 0) edgeSum++; //왼쪽
          if (k == 99 || arr[j+1][k] == 0) edgeSum++; //아래
          if (j == 99 || arr[j][k+1] == 0) edgeSum++; //오른쪽)
        }
      }
    }
    cout << sumRange << " " << edgeSum << endl;
  }
}
