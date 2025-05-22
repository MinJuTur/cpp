//
// 괄호
//
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string input;
    cin >> input;

    bool isOk = true;
    stack<char> stack; // 괄호를 저장할 스택

    for (int i = 0; i < input.length(); i++) {
      if (input[i] == '(' || input[i] == '{' || input[i] == '[') stack.push(input[i]);
      else {
        if (stack.empty()) { // 2번 조건 위배
          isOk = false;
          break;
        } else {
          char temp = stack.top();
          stack.pop();
          // 2번 조건 위배
          if (!(input[i] == ')' && temp == '(' || input[i] == '}' && temp == '{' || input[i] == ']' && temp == '[')) {
            isOk = false;
            break;
          }
        }
      }
    }
    if (!stack.empty()) isOk = false; // 1번 조건 위배
    cout << isOk << endl;
  }
}