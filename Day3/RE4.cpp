//
// 달력 출력하기
//
#include <iostream>
#include <fstream>
using namespace std;

int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isYuneYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
  return false;
}

// 마지막 날짜 구하는 함수
int getFinalDate(int year, int month) {
  if (month == 2 && isYuneYear(year)) return 29;
  return months[month];
}

// 요일 구하는 함수: 0=일요일, 1=월요일, 2=화요일, 3=수요일, 4=목요일, 5=금요일, 6=토요일
int findDayOfWeek(int year, int month, int day) {
  int sumDays = 0;
  for (int i = 1582; i < year; i++) {
    if (isYuneYear(i)) sumDays += 366;
    else sumDays += 365;
  }
  for (int i = 1; i < month; i++) {
    sumDays += getFinalDate(year,i);
  }
  sumDays += day-1;

  return (sumDays+5) % 7;
}



int main() {
  ifstream inputFile("input.txt");
  int t;
  inputFile >> t;

  for (int i = 0; i < t; i++) {
    int year, month;
    inputFile >> year >> month;

    cout << year << " " << month << "\n";

    int dayOfWeek = findDayOfWeek(year, month, 1);
    int finalDate = getFinalDate(year, month);
    int num = 1;
    while (true) {
      for (int j = 0; j < 7; j++) {
        if (j > 0) cout << " ";

        if (--dayOfWeek >= 0) cout << 0;
        else if (num > finalDate) cout << 0;
        else cout << num++;
      }
      cout << "\n";
      if (num > finalDate) break;
    }
  }
}