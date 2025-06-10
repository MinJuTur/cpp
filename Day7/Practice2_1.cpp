// 32비트를 8비트 단위로 나누어 계산, 3바이트가 실제 데이터, 1바이트가 체크썸
// 실제 데이터가 있는 3바이트를 바이트 단위로 나눠서 더하기 256보다 작아지도록 256 빼기
// 체크썸 값 = 255 - 위에서 구한 값 뺀 값


// 십진수를 이진수로 변환 -> 앞의 3바이트를 바이트 단위로 나눠서 합치기

#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    unsigned int n;
    cin >> n;

    deque<int> arr; //십진수 n을 이진수로 바꿔 저장
    for (int i = 0; i < 32; i++) {
      if (n > 0) {
        arr.push_front(n % 2);
        n /= 2;
      } else arr.push_front(0);
    }

    int calculatedCheckSum = 0;
    int realCheckSum = 0;
    for (int i = 0; i < 32;) {
      int partNum = 0;
      for (int j = 7; j >= 0 && i < 32; j--, i++) {
        partNum += arr[i]*(int)pow(2,j);
      }

      if (i < 28) {
        calculatedCheckSum += partNum;
      } else realCheckSum = partNum;
    }

    while (calculatedCheckSum >= 256) calculatedCheckSum -= 256;
    calculatedCheckSum = 255 - calculatedCheckSum;

    if (calculatedCheckSum == realCheckSum) cout << 1 << endl;
    else cout << 0 << endl;
  }
}