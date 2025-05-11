//
// 끝자리 숫자 계산하기
// 각 숫자의 일의 자리끼리만 곱하면 된다. 나머지 연산을 이용한다.
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int sum = 1;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;

      sum *= data % 10;
      sum %= 10;
    }
    cout << sum << endl;
  }
}
