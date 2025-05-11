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

int calculateDayOfWeek(int year, int month, int day) {
  if (month == 1 || month == 2) {
    year--;
    month += 12;
  }

  int k = year % 100;
  int j = year / 100;
  // 0 = 토요일, 1 = 일요일, ..., 6 = 금요일
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

    int startDayOfWeek = calculateDayOfWeek(Y, M, 1);
    int endDay = calculateEndDay(Y, M);
    int Day = 1;
    while (true) {
      for (int j = 0; j < 7; j++) {
        if (j > 0) cout << " ";

        if (--startDayOfWeek >= 0) cout << 0;
        else if (Day > endDay) cout << 0;
        else cout << Day++;
      }
      cout << "\n";

      if (Day > endDay) break;
    }
  }
}


