//
// 이진수에서 0과 1의 개수
// <fstream> 헤더 파일
//

#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream inputFile("input.txt");

  int t;
  inputFile >> t;

  for (int i = 0; i < t; i++) {
    int n;
    inputFile >> n;

    int cnt_0 = 0;
    int cnt_1 = 0;
    while (n > 0) {
      if (n % 2 == 0) cnt_0++;
      else cnt_1 ++;

      n /= 2;
    }

    cout << cnt_0 << " " << cnt_1 << endl;
  }
}