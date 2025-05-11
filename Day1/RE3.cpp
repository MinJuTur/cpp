//
// 세 정수의 정렬(2)
// if문 나열
//

#include <iostream>
#include <climits>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    // a b c, a c b, b a c, b c a, c a b, c b a 총 6가지
    if (a <= b && b <= c) cout << a << " " << b << " " << c << endl;
    else if (a <= c && c <= b) cout << a << " " << c << " " << b << endl;
    else if (b <= c && c <= a) cout << b << " " << c << " " << a << endl;
    else if (b <= a && a <= c) cout << b << " " << a << " " << c << endl;
    else if (c <= a && a <= b) cout << c << " " << a << " " << b << endl;
    else if (c <= b && b <= a) cout << c << " " << b << " " << a << endl;
  }
}