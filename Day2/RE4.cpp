//
// 가위바이위보 게임
// 비길 떄의 경우를 잘 나눠야하는 문제이다.
//

#include <iostream>
using namespace std;

int main() {
  //가위1 바위2 보3으로 표시

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    // 가위, 바위, 보 각각 몇 명이 냈는지 세기
    int scissor = 0;
    int rock = 0;
    int paper = 0;
    for (int j = 0; j < n; j++) {
      int data;
      cin >> data;

      if (data == 1) scissor++;
      else if (data == 2) rock++;
      else if (data == 3) paper++;
    }

    //비겼을 때: 세 종류가 모두 나왔을 떼, 한 종류만 나왔을 때
    if ((scissor > 0 && rock > 0 && paper > 0) || scissor == n || rock == n || paper == n) {
      cout << 0 << endl;
    } else { //승자가 나올 때: 두 종류만 나왔을 때
      if (scissor == 0) cout << paper << endl;
      else if (rock == 0) cout << scissor << endl;
      else if (paper == 0) cout << rock << endl;
    }
  }
}
