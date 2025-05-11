#include <iostream>
using namespace std;

void list3Numbers(int a, int b, int c);

int main() {
  int t;
  int a, b, c;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    list3Numbers(a, b, c);
  }

  return 0;
}

void list3Numbers(int a, int b, int c) {
  if (a <= b && a <= c) { //a가 최소일 때
    if (b <= c) cout << a << " " << b << " " << c << endl;
    else cout << a << " " << c << " " << b << endl;
  } else if (b <= a && b <= c) {//b가 최소일 때
    if (a <= c) cout << b << " " << a << " " << c << endl;
    else cout << b << " " << c << " " << a << endl;
  } else if (c <= a && c <= b) {//c가 최소일 때
    if (a <= b) cout << c << " " << a << " " << b << endl;
    else cout << c << " " << b << " " << a << endl;
  }
}