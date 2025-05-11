#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int N;
    cin >> N;

    int temp = N;
    int arr[10] = {0};
    while (temp > 0) {
      if (temp % 10 != 0) arr[temp % 10] = 1;
      temp /= 10;
    }

    int cnt = 0;
    for (int j = 0; j < 10; j++) {
      if (arr[j] == 1 && N % j == 0) cnt++;
    }

    cout << cnt << endl;
  }
}
