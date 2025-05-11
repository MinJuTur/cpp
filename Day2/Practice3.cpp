#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    long result = 1;
    for (int j = 0; j < n; j++) {
      long data;
      cin >> data;

      result *= data%10;
      result = result%10;
    }
    cout << result%10 << "\n";
  }
}