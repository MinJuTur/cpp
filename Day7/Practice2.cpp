//
// 체크썸
//
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long int n;
    cin >> n;

    int arr[32] = {0}; // n을 이진수로 변환해 저장(거꾸로)
    int i = 0;
    while (n > 0) {
      arr[i++] = n % 2;
      n /= 2;
    }

    int pow[8] = {1, 2, 4, 8, 16, 32, 64, 128};

    int checkSum = 0;
    for (int j = 0; j < 8; j++) {
      checkSum += arr[j] * pow[j%8];
    }

    int sum = 0;
    for (int j = 8; j < 32; j++) {
      sum += arr[j] * pow[j%8];
    }

    while (sum >= 256) sum -= 256;
    int calCheckSum = 255 - sum;

    if (calCheckSum == checkSum) cout << 1 << endl;
    else cout << 0 << endl;
  }
}
