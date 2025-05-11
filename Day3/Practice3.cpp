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

      if (n % 10 != 0) {
        result *= n % 10;
      }
      n /= 10;

      if (n == 0) { //각 자리수 곱하기가 끝났을 때
        if (result < 10) break;

        n = result;
        result = 1;
      }

    }
    cout << result << "\n";
  }
}
