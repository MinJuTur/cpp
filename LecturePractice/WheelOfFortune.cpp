//
// string 클래스 활용
//

#include <iostream>
#include <string>
#include <cstdlib> # rand() 함수를 위해
#include <ctime> # time() 함수를 위해
using namespace std;

#define DICT_LEN 3
#define MAX_TRIES 6

int main() {
  string dictionary[] = {"space", "wheel", "program"};
  srand(time(NULL));
  string prob = dictionary[rand()%DICT_LEN];
  int length = prob.length();
  int tries = 0;
  string answer(length, '-');

  cout << "current state : " << answer << endl;


  while (tries < MAX_TRIES && answer != prob) {
    char c;
    cout << "guess a letter : ";
    cin >> c;

    // 이미 추측한 단어일 때
    if (answer.find(c) != string::npos) {
      cout << c << " is guessed previously.\n";
      continue;
    }

    int pos = prob.find(c);

    // 정답에 없는 단어일 때
    if (pos == string::npos) {
      cout << c << " is not in the target string.\n";
      tries++;
      continue;
    }

    // 정답에 있는 단어일 때 -> answer 갱신
    do {
      answer[pos] = c;
      pos = prob.find(c, pos+1);
    } while (pos != string::npos);
    cout << "current state : " << answer << endl;

    // 다 맞췄을 때
    if (answer == prob) {
      cout << "You WON!!!\n";
      break;
    }
  }

  if (tries >= MAX_TRIES) {
    cout << "You lost : the answer was " << prob << endl;
  }
}