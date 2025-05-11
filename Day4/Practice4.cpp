#include <iostream>
#include<cmath>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;

    int arr[6] = {0,9,189,2889,38889,488889}; // i번째 수 -> i 자리수
    int n = 0; //몇 자리 숫자에 속하는지
    int num = 0; // k번째 숫자가 속하는 숫자 후보(나머지가 0일 때)
    int moreCnt = 0; // num 이후 몇 개의 낱개 숫자를 더 세어야 하는지

    if (k < arr[1]) {
      n = 1;
    } else if (k < arr[2]) {
      n = 2;
    } else if (k < arr[3]) {
      n = 3;
    } else if (k < arr[4]) {
      n = 4;
    } else if (k < arr[5]) {
      n = 5;
    } else {
      n = 6;
    }

    num = (int) pow(10,n-1) + (k-arr[n-1])/n - 1;
    moreCnt = (k-arr[n-1]) % n;

    if (moreCnt == 0) cout << num % 10 << endl;
    else cout << to_string((num+1))[moreCnt-1] << endl;

  }
}
