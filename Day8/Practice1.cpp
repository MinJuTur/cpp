//
// 실수 표현
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string input;
    cin >> input;

    int intNum = 0, floatNum = 0, dot = 0, eNum = 0, op = 0, unknown = 0, len = input.size();
    for (int i = 0; i < len; i++) {
      if (input[i] == '.') dot++; // 소숫점 카운트
      if (input[i] == 'E' || input[i] == 'e') eNum++; // E 갯수 카운트
      if (!dot && !eNum) {
        if (input[i] >= '0' && input[i] <= '9') intNum++; // 정수부 카운트
      }
      else if (!eNum) {
        if (input[i] >= '0' && input[i] <= '9') floatNum++; // 소수부 카운트
      }
      else { //지수부 카운트
        if (input[i] >= '0' && input[i] <= '9') eNum++;
        else if (input[i] == '+' || input[i] == '-') op++;
        else if (!(input[i] == 'E' || input[i] == 'e')) unknown++;
      }
    }

    bool result = ((!intNum && !floatNum) || (!dot && !eNum) || (dot > 1) || (eNum == 1) || (op > 1) || (unknown > 0)) ? false : true;
    cout << result << endl;
  }
}