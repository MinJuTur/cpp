#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int cnt_2 = 0;
    int cnt_5 = 0;
    int lastNum = 1;
    int cnt_10 = 0;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;

      while (data % 2 == 0) {
        cnt_2++;
        data /= 2;
      }
      while (data % 5 == 0) {
        cnt_5++;
        data /= 5;
      }

      lastNum *= data % 10;
      lastNum %= 10;
    }

    if (cnt_2 > cnt_5) { //2가 남을 때
      cnt_10 = cnt_5;
      for (int j = 0; j < cnt_2-cnt_5; j++) {
        lastNum *= 2;
        lastNum %= 10;
      }
    } else if (cnt_5 >= cnt_2) { //5가 남을 때
      cnt_10 = cnt_2;
      for (int j = 0; j < cnt_5-cnt_2; j++) {
        lastNum *= 5;
        lastNum %= 10;
      }
    } else cnt_10 = cnt_2; // 남는 게 없을 때

    cout << lastNum << " " << cnt_10 << endl;
  }
}
