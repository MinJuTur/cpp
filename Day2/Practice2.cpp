#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int Acnt = 0;
    int Bcnt = 0;
    int Ccnt = 0;
    int Dcnt = 0;
    int Fcnt = 0;
    for (int j = 0; j < n; j++) {
      int score;
      cin >> score;

      if (score >= 90) Acnt++;
      else if (score >= 80) Bcnt++;
      else if (score >= 70) Ccnt++;
      else if (score >= 60) Dcnt++;
      else Fcnt++;
    }

    cout << Acnt << " " << Bcnt << " " << Ccnt << " " << Dcnt << " " << Fcnt << "\n";
  }
}
