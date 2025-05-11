#include <iostream>
#include <fstream>
using namespace std;

int calculateEndDay(int year, int month) {
  if (month == 2) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 29;
    else return 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
  return 31;
}

int calculateWeek(int year, int month, int day) {
  if (month == 1 || month == 2) {
    year--;
    month += 12;
  }

  int k = year % 100;
  int j = year / 100;
  int result = (day + 13*(month+1)/5 + k + k/4 + j/4 + 5*j) % 7;

  // 0 = 일요일, 1 = 월요일, ..., 6 = 토요일로 변환
  return (result+6)%7;
}

int main() {
  ifstream inputFile("input.txt");

  int t;
  inputFile >> t;

  for (int i = 0; i < t; i++) {
    int Y,M;
    inputFile >> Y >> M;

    cout << Y << " " << M << "\n";

    bool isDone = false;
    int endDay = calculateEndDay(Y, M);
    int startWeek = calculateWeek(Y, M, 1);
    int endWeek = calculateWeek(Y, M, endDay);
    int num = 1;
    while (!isDone) {
      for (int j = 0; j < 7; j++) {
        if (j > 0) cout << " ";
        if (startWeek > 0) {
          cout << 0;
          startWeek--;
        } else if (num > endDay) {
          cout << 0;
        } else cout << num++;
      }
      cout << "\n";

      if (num > endDay) isDone = true;
    }
  }
}


