//
// 주가분석(1)
// 중간고점 가격이 발생한 횟수 구하기(올라갔다가 내려가면)
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int cnt = 0;

    int data1;
    cin >> data1;
    bool isUp = false;
    for (int j = 1; j < n; j++) {
      int data2;
      cin >> data2;

      if (data1 < data2) isUp = true;
      if (isUp && data1 > data2) {
        cnt++;
        isUp = false;
      }
      data1 = data2;
    }
    cout << cnt << endl;
  }
}
