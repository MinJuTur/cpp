#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;

    int cnt = 0;
    bool isString = false;
    for (int j = 0; j < s.size(); j++) {
      if ('0' <= s[j] && s[j] <= '9') {
        if (isString) continue;
        isString = true;
        cnt++;
      } else isString = false;
    }

    cout << cnt << endl;
  }
}
