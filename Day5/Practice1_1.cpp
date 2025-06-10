#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    unsigned int N;
    cin >> N;

    unsigned int temp = N;
    int arr[10] = {0}; // index: 1~9
    while (temp > 0) {
      arr[temp % 10] = 1;
      temp /= 10;
    }

    int cnt = 0;
    for (int i = 1; i <= 9; i++) {
      if (arr[i] == 1) {
        if (N % i == 0) cnt++;
      }
    }
    cout << cnt << endl;
  }
}