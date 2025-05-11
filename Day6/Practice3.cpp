#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;
    int size = s.length();

    int digits[size]; // 각 자리수를 배열에 저장
    int totalSum = 0; // 모든 자리수의 합
    for (int i = 0; i < size; i++) {
      digits[i] = s[i] - '0';
      totalSum += digits[i];
    }

    int arr[12] = {0}; //2-11의 배수인지 저장하는 배열(인덱스: 2-11만 사용)

    if (digits[size-1] % 2 == 0) arr[2] = 1; // 2의 배수
    if (totalSum % 3 == 0) arr[3] = 1; // 3의 배수
    if ((size == 1 && digits[0] % 4 == 0) || (size >= 2 && (digits[size-2]*10+digits[size-1]) % 4 == 0)) arr[4] = 1; // 4의 배수
    if (digits[size-1] == 0 || digits[size-1] == 5) arr[5] = 1; // 5의 배수
    if (arr[2] && arr[3]) arr[6] = 1; // 6의 배수


    if (size == 1 && digits[0] % 7 == 0) { // 한 자리 수일 때
      arr[7] = 1; // 7의 배수
    } else {
      string temp_s = s;
      while (temp_s.length() > 1) {
        int a = temp_s[0] - '0';
        int b = temp_s[1] - '0';
        int temp = a * 3 + b;

        temp_s = to_string(temp) + temp_s.substr(2);
      }
      if (temp_s == "7") arr[7] = 1; // 7의 배수
    }

    if ((size == 1 && digits[0] % 8 == 0) || (size == 2 && (digits[0]*10+digits[1]) % 8 == 0) || (size >= 3 && (digits[size-3]*100+digits[size-2]*10+digits[size-1]) % 8 == 0)) arr[8] = 1; // 8의 배수
    if (totalSum % 9 == 0) arr[9] = 1; // 9의 배수
    if (digits[size-1] == 0) arr[10] = 1; // 10의 배수

    int oddSum = 0; // 홀수 번째 자리수의 합
    int evenSum = 0; // 짝수 번째 자리수의 합
    for (int i = 0; i < size; i++) {
      if (i % 2 == 0) evenSum += digits[i];
      else oddSum += digits[i];
    }
    int diff = oddSum > evenSum ? oddSum - evenSum : evenSum - oddSum;
    if (diff % 11 == 0) arr[11] = 1; // 11의 배수

    // 출력
    for (int i = 2; i <= 11; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
