#include <iostream>
#include <cmath>
using namespace std;

int calCnt(int num, int k) {
  if (num % k != 0) return 0;

  int cnt = 0;
  while (num % k == 0) {
    cnt++;
    num /= k;
  }
  return cnt;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int total_cnt_2 = 0;
    int total_cnt_5 = 0;
    int total_rest = 1;
    while (n--) {
      int num;
      cin >> num;

      int cnt_2 = calCnt(num, 2);
      int cnt_5 = calCnt(num, 5);
      total_rest *= num/(pow(2,cnt_2)*pow(5,cnt_5));
      total_rest %= 10;

      total_cnt_2 += cnt_2;
      total_cnt_5 += cnt_5;
    }

    total_rest *= total_cnt_2 > total_cnt_5 ? pow(2, total_cnt_2-total_cnt_5) : pow(5, total_cnt_5-total_cnt_2);
    total_rest %= 10;
    cout << total_rest << " " << min(total_cnt_2, total_cnt_5) << endl;
  }
}