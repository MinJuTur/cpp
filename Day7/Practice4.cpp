//
// 시이저 암호문 복호기법
//
#include <iostream>
#include <fstream>
#include <cfloat>
using namespace std;

int main() {
  ifstream input("input.txt");

  int t;
  input >> t;

  while (t--) {
    string code;
    input >> code;

    // 영어 알파벳의 문자 빈도수의 백분율
    double realAlpha[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929,
      0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

    // 암호문의 알파벳 문자 빈도수의 백분율
    double codeAlpha[26] = {0};
    int alphaCnt = 0;
    for (int i = 0; i < code.size(); i++) {
      char temp = code[i];
      if (code[i] >= 'A' && code[i] <= 'Z') {
        codeAlpha[code[i]-'A']++;
        alphaCnt++;
      } else if (code[i] >= 'a' && code[i] <= 'z') {
        codeAlpha[code[i]-'a']++;
        alphaCnt++;
      }
    }
    for (int i = 0; i < 26; i++) {
      codeAlpha[i] = codeAlpha[i] / alphaCnt * 100;
    }


    double minKaiSquare = DBL_MAX; // 가장 작은 kaiSquare 값
    int key = -1; // 가장 작은 kaiSquare 값일 때의 key 값

    for (int tempKey = 0; tempKey <= 25; tempKey++) { // tempKey: 키 값(0 ~ 25)
      double kaiSquare = 0;
      for (int i = 0; i < 26; i++) {
        // 각 알파벳 문자
        kaiSquare += codeAlpha[(i+tempKey) % 26] * codeAlpha[(i+tempKey) % 26] / realAlpha[i];
      }

      if (kaiSquare < minKaiSquare) {
        minKaiSquare = kaiSquare;
        key = tempKey;
      }
    }

    // 변환해서 출력하기
    for (int i = 0; i < code.size(); i++) {
      if (code[i] >= 'A' && code[i] <= 'Z') {
        cout << (char)(((code[i]-'A')-key+26) % 26 + 'A');
      } else if (code[i] >= 'a' && code[i] <= 'z') {
        cout <<  (char)(((code[i]-'a')-key+26) % 26 + 'a');
      } else cout << code[i];
    }
    cout << endl;
  }
}