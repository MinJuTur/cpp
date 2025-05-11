//
// 직선 그래프 출력하기(활용)
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
                if (j == h && h == half) cout << "O";
                else if (j == h) cout << "*";
                else if (h == half) cout << "I";
                else if (j == half) cout << "+";
                else cout << ".";
            }
            cout << "\n";
        }
    }
}