//
// 주어진 정수의 최대, 최소 구하기
// <climits> 헤더파일 사용
//

#include <iostream>
#include <climits>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int max = INT_MIN;
    int min = INT_MAX;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;

      if (data > max) max = data;
      if (data < min) min = data;
    }
    cout << max << " " << min << endl;
  }
}
