//
// 숫자의 모든 자리수 반복 곱하기
// long이 아니라 unsigned int 이용하기
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    unsigned int n;
    cin >> n;

    unsigned int result = 1;
    while (true) {
      if (n % 10 != 0) result *= n % 10;
      n /= 10;

      if (n == 0) {
        if (result < 10) break;
        n = result;
        result = 1;
      }
    }
    cout << result << endl;
  }
}