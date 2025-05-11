#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");

  int t;
  inputFile >> t;

  for (int i = 0; i < t ; i++) {
    int n;
    inputFile >> n;

    int cnt0 = 0;
    int cnt1 = 0;

    while (n > 0) {
      if (n % 2 == 0) cnt0++;
      else cnt1++;

      n /= 2;
    }

    cout << cnt0 << " " << cnt1 << endl;
  }

  inputFile.close();
  return 0;
}
