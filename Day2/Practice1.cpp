#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    int half = k/2;

    for (int j = 0; j < k; j++) {
      for (int g = 0; g < k; g++) {
        if (j + g == k-1) {
          if (j == half) cout << "O";
          else cout << "*";
        } else if (j == half) cout << "+";
        else if (g == half) cout << "I";
        else cout << ".";
      }
      cout << "\n";
    }
  }
}
