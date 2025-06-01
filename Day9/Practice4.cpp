//
// Cross Puzzle
// 찾고자 하는 단어의 첫글자 먼저 찾기
// 첫글자 찾으면 단어의 글자크기만큼 8개 방향에 대해 검사 -> 있으면 출력 후 종료
// 없으면 단어의 첫글자 다시 찾아 반복
// 단어의 첫글자가 끝까지 없거나, 있어도 8개 방향에 단어가 없으면 -1 출력 후 끝내기
//
#include <iostream>
#include <vector>
using namespace std;

int searchDirection(vector<vector<char>>& arr, int x, int y, const string& s) {
  int len = s.size(); // 단어의 길이

  if (x-len+1 >= 1) { // 위 방향: x감소, y고정
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x-i][y] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 0;
  }

  if (x-len+1 >= 1 && y+len-1 < arr[0].size()) { // 오른쪽 위 방향: x감소, y증가
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x-i][y+i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 1;
  }

  if (y+len-1 < arr[0].size()) { // 오른쪽 방향: x고정, y증가
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x][y+i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 2;
  }

  if (x+len-1 < arr.size() && y+len-1 < arr[0].size()) { // 오른쪽 아래 방향: x증가, y증가
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x+i][y+i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 3;
  }

  if (x+len-1 < arr.size()) { // 아래 방향: x증가, y고정
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x+i][y] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 4;
  }

  if (x+len-1 < arr.size() && y-len+1 >= 1) { // 왼쪽 아래 방향: x증가, y감소
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x+i][y-i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 5;
  }

  if (y-len+1 >= 1) { // 왼쪽 방향: x고정, y감소
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x][y-i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 6;
  }

  if (x-len+1 >= 1 && y-len+1 >= 1) { // 왼쪽 위 방향: x감소, y감소
    bool flag = true;
    for (int i = 1; i < len; i++) {
      if (arr[x-i][y-i] != s[i]) {
        flag = false; break;
      }
    }
    if (flag) return 7;
  }

  return -1;
}

void findString(vector<vector<char>>& arr, const string& s) {
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 1; j < arr[0].size(); j++) {
     // 단어의 첫글자 찾기
      if (arr[i][j] == s[0]) {
        int direction = searchDirection(arr, i, j, s);
        if (direction != -1) { // 찾았을 때
          cout << i << " " << j << " " << direction << endl;
          return;
        }
      }
    }
  }
  // 못 찾았을 때
  cout << -1 << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> arr(m+1, vector<char>(n+1)); //격자판(인데스 1부터 사용)
    for (int i = 1; i < arr.size(); i++) { //1~m
      string row;
      cin >> row;
      for (int j = 1; j < arr[0].size(); j++) { //1~n
        arr[i][j] = row[j-1];
      }
    }

    int k;
    cin >> k;

    while (k--) {
      string s;
      cin >> s;
      findString(arr, s);
    }

  }
}