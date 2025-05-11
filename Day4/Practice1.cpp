#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, before, now;
    cin >> n;

    int cnt = 0;
    bool isUp = false;
    cin >> before;
    for (int j = 1; j < n; j++) {
      cin >> now;

      if (before < now) {
        isUp = true;
      } else if (before > now && isUp) {
        cnt++;
        isUp = false;
      }

      before = now;
    }

    cout << cnt << endl;
  }
}
