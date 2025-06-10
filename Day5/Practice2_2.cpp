#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string input;
    cin >> input;

    bool isNum = false;
    int cnt = 0;
    for (int i = 0; i < input.size(); i++) {
      char c = input[i];

      if (c >= '0' && c <= '9') {
        if (!isNum) {
          isNum = true;
          cnt++;
        }
      } else isNum = false;
    }
    cout << cnt << endl;
  }
}
