//
// 숫자의 진법 변환
//
#include <iostream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int s,t;
    string n;
    cin >> s >> n >> t;

    int convertTo10 = 0; // n을 10진수로 변환한 값
    int multi = 1;
    for (int i = n.size() - 1; i >= 0; i--) {
       int temp;
       if (n[i] >= 'a' && n[i] <= 'z') temp = 10+n[i]-'a';
       else temp = n[i]-'0';

       convertTo10 += temp * multi;
       multi *= s;
    }

    int arr[32] = {0}; // t진법으로 변환(거꾸로 저장)
    int idx = 0;
    while (convertTo10 > 0) {
      arr[idx++] = convertTo10 % t;
      convertTo10 /= t;
    }

    for (int i = idx-1; i >= 0; i--) {
      if (arr[i] >= 10) cout << (char) ('a'+arr[i]-10);
      else cout << arr[i];
    }
    cout << endl;
  }
}






































