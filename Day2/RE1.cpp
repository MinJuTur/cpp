//
// 직선 그래프 출력하기
// 특수한 조건부터 if 문에서 거른다.
// *를 어떻게 출력하냐가 가장 중요하다. x축, y축, 중심은 출력하기 쉽다.
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;

    int half = k/2;
    for (int j = 0; j < k; j++) { //j:행
      for (int h = 0; h < k; h++) { //h:열
        if (j + h == k-1) {
          if (j == h) cout << "O";
          else cout << "*";
        } else if (h == half) cout << "I";
        else if (j == half) cout << "+";
        else cout << ".";
      }
      cout << "\n";
    }
  }
}


