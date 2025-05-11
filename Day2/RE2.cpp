//
// Created by 장민주 on 2025-04-21.
//

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    int scores[5] = {0};
    for (int j = 0; j < n; j++) {
      int score;
      cin >> score;

      if (score >= 90) scores[0]++;
      else if (score >= 80) scores[1]++;
      else if (score >= 70) scores[2]++;
      else if (score >= 60) scores[3]++;
      else scores[4]++;
    }

    for (int j = 0; j < 5; j++) {
      cout << scores[j] << " ";
    }
    cout << "\n";
  }
}
