#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
  int t;
   cin >> t;

   while (t--) {
     string input;
     cin >> input;

     int len = input.size();
     int result[12] = {0}; //2~11

     if ((input[len-1]-'0') % 2 == 0) result[2] = 1;

     int sum = 0; //모든 자리수 합
     int sum_hal = 0; //홀수 합
     int sum_zzac = 0; //짝수 합
     for (int i = 0; i < len; i++) {
       int d = input[i]-'0';
       sum += d;
       if (i % 2 == 0) sum_hal += d;
       else sum_zzac += d;
     }
     if (sum % 3 == 0) result[3] = 1;

     if (len == 1 && (input[0]-'0') % 4 == 0) result[4] = 1;
     else if (len >= 2 && ((input[len-2]-'0')*10+(input[len-1]-'0')) % 4 == 0) result[4] = 1;

     if (input[len-1] == '0' || input[len-1] == '5') result[5] = 1;

     if (result[2] == 1 && result[3] == 1) result[6] = 1;

     string temp = input;
     while (temp.size() > 1) {
       int part = (temp[0]-'0')*3+temp[1]-'0';
       temp = to_string(part) + temp.substr(2,temp.size());
     }
     if (temp == "7") result[7] = 1;

     if (len == 1 && input == "8") result[8] = 1;
     else if (len == 2 && ((input[0]-'0')*10+(input[1]-'0')) % 8 == 0) result[8] = 1;
     else if (len >= 3 && ((input[len-3]-'0')*100+(input[len-2]-'0')*10+(input[len-1]-'0')) % 8 == 0) result[8] = 1;

     if (sum % 9 == 0) result[9] = 1;

     if (input[len-1] == '0') result[10] = 1;

     int diff = abs(sum_hal-sum_zzac);
     if (diff % 11 == 0) result[11] = 1;

     for (int i = 2; i <= 11; i++) {
       cout << result[i] << " ";
     }
     cout << endl;
   }
}