#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int arr[100] = {0}; //0~99

    for (int j = a; j <= b; j++) {
      arr[j]++;
    }
    for (int j = c; j <= d; j++) {
      arr[j]++;
    }

    int mixed = 0;
    int total = 0;
    for (int j = 1; j < 100; j++) {
      if (arr[j] > 0) total++;
      if (arr[j] > 1) mixed++;
    }

    if (mixed > 0) { //겹친 구간이 있을 때
      mixed--;
      total--;
    } else if (mixed == 0) { //겹친 구간이 없을 때
      total -= 2;
    }

    cout << mixed << " " << total << "\n";
  }
}
