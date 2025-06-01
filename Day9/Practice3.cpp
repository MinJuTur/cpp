//
// 숫자 읽기
//
#include <iostream>
#include <string>
using namespace std;

void numToString(string temp, int unitNum) {
  string unitArr1[4] = {"", "Thousand", "Million", "Billion"};
  string unitArr2[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  string unitArr3[10] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
  string unitArr4[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  if (temp.size() == 1) {
    if (temp[0] != '0') {
      cout << unitArr3[temp[0] - '0'];
    }
  } else if (temp.size() == 2) {
    int num = (temp[0] - '0') * 10 + (temp[1] - '0');
    if (num >= 10 && num <= 19) {
      cout << unitArr2[temp[1] - '0'];
    } else {
      if (temp[0] != '0') {
        cout << unitArr4[temp[0] - '0'];
        if (temp[1] != '0') cout << "_";
      }
      if (temp[1] != '0') {
        cout << unitArr3[temp[1] - '0'];
      }
    }
  } else {
    if (temp[0] == '0' && temp[1] == '0' && temp[2] == '0') return;

    if (temp[0] != '0') {
      cout << unitArr3[temp[0] - '0'] << "_Hundred";
      if (temp[1] != '0' || temp[2] != '0') cout << "_";
    }

    int num = (temp[1] - '0') * 10 + (temp[2] - '0');
    if (num >= 10 && num <= 19) {
      cout << unitArr2[temp[2] - '0'];
    } else {
      if (temp[1] != '0') {
        cout << unitArr4[temp[1] - '0'];
        if (temp[2] != '0') cout << "_";
      }
      if (temp[2] != '0') {
        cout << unitArr3[temp[2] - '0'];
      }
    }
  }

  if (!(temp.size() == 3 && temp[0] == '0' && temp[1] == '0' && temp[2] == '0') && unitNum > 0) {
    cout << "_" << unitArr1[unitNum];
  } else if (temp.size() < 3 && unitNum > 0 && temp != "00" && temp != "0") {
    cout << "_" << unitArr1[unitNum];
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    string n;
    cin >> n;

    while (n.size() > 1 && n[0] == '0') n.erase(0, 1); // 앞자리 0 제거

    int unitNum = n.size() % 3 ? n.size() / 3 : n.size() / 3 - 1;
    int begin = n.size() % 3;

    bool isPrinted = false;
    if (begin != 0) {
      string temp = n.substr(0, begin);
      if (temp != string(temp.size(), '0')) {
        numToString(temp, unitNum);
        isPrinted = true;
      }
      unitNum--;
    }

    for (int i = unitNum; i >= 0; i--) {
      string temp = n.substr(begin, 3);
      if (temp != "000") {
        if (isPrinted) cout << "_";
        numToString(temp, i);
        isPrinted = true;
      }
      begin += 3;
    }

    cout << endl;
  }
}
